// lnc_fc_sclerophyll_wet
// modified geoff.goldrick@protonmail.com 2020-08-18

// -------------------------------------------
// Wet Eucalypt model - Adapted from Project VESTA
// Model parameters
// These must be defined during init, or included as a user-defined layer
//
// 1. Temperature, 'temp' (input)
// 2. Relative humidity, 'rel_hum' (input)
// 3. Surface fuel hazard score, 'fhs_surface'
// 4. Near-surface fuel hazard score, 'fhs_near_surface'
// 5. Near surface height, 'h_near_surface'
// 6. Shrub height, 'fuel_height'
// -------------------------------------------

// Calculating the wind speed which is used to calculate head fire ROS
REAL wind_speed = length(wind_vector);

// Calculating the normalised dot product between the wind vector and the normal to the fire perimeter
REAL wdot = dot(normalize(wind_vector),advect_normal_vector);

// Estimating fuel moisture content using Gould et al. (2007) and Matthews et al. (2010)
// Initialising the fuel moisture variable
REAL Mf;

// Calculating fuel moisture between 12:00 and 16:59 (valid for sunny days from October to March)
if (hour > 11 && hour < 17){
    Mf = 2.76 + (0.124*rel_hum) - (0.0187*temp);}

// Calculating fuel moisture for other daylight hours (from 9:00 to 11:59 and 17:00 to 19:59 in this example)
else if ((hour < 12 && hour > 8) || (hour > 16 & hour < 20)){
    Mf = 3.6 + (0.169*rel_hum) - (0.045*temp);}

// Calculating fuel moisture for night time hours (from 20:00 to 8:59) in this example
else{
    Mf =  3.08 + (0.198*rel_hum) - (0.0483*temp);}  

// Applying wind reduction factors and fuel moisture modifications for wet forest as per Amicus
// These factors depend on the height of the shrubs within the forest
if (fuel_height < 2){
    wind_speed = wind_speed / 2;
    Mf = Mf + 0.2052*Mf + 0.8554;}
else if (fuel_height > 5){
    wind_speed = wind_speed / 3;
    Mf = Mf + 0.5923*Mf + 1.9565;}
else{
    wind_speed = wind_speed / 2.3;
    Mf = Mf + 0.5248*Mf - 0.0568;}

// Calculate moisture coefficients from Burrows (1999)
REAL moisture_coeff = 18.35 * pow(Mf,-1.495);

// Calculate length-to-breadth ratio (LBR) which varies with wind speed
// Using the reduced under canopy wind speed in this case
// Equations are curve fits adapted from Taylor (1997)
REAL LBR;
if (wind_speed < 5){
  LBR = 1.0;
} else if (wind_speed < 25){
  LBR = 0.9286 * exp(0.0505 * wind_speed);
} else {
  LBR = 0.1143 * wind_speed + 0.4143;
}
// Determine coefficient for backing and flanking rank of spread using elliptical equations
// Where R_backing = cb * R_head, R_flanking = cf * R_head,
REAL cc = sqrt(1.0-pow(LBR, -2.0));
REAL cb = (1.0-cc)/(1.0+cc);
REAL a_LBR = 0.5*(cb+1.0);
REAL cf = a_LBR/LBR;

// Determine shape parameters
REAL f = 0.5*(1.0+cb);
REAL g = 0.5*(1.0-cb);
REAL h = cf;

// Now calculate a speed coefficient using normal flow formula
REAL speed_fraction = (g*wdot+sqrt(h*h+(f*f-h*h)*wdot*wdot));

// Calculate head fire spread rate (in m/s)
REAL head_speed;
if ( wind_speed > 5 ){
  head_speed = (30.0 + 1.5308 * pow(wind_speed-5,0.8576) * 
           pow(fhs_surface,0.9301) * pow(fhs_near_surface*h_near_surface,0.6366) * 1.03 ) *
           moisture_coeff/3600;
} else {
  head_speed = 30.0 * moisture_coeff/3600;}

// Adjust for calculated speed coefficient for fire flanks
speed = head_speed * speed_fraction;