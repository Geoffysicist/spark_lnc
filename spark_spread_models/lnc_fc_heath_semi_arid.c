// lnc_fc_heath_semi_arid
// modified geoff.goldrick@protonmail.com 2020-08-18

// -------------------------------------------
// Heathland model - Anderson et al. (2015)
// Model parameters
// These must be defined below, or included as a user-defined layer
//
// 1. Temperature, 'temp' (input)
// 2. Relative humidity, 'rel_hum' (input)
// 3. Wind reduction factor, 'WF' (input), 0.67 for heath-shrublands and 0.35 for woodlands.
// 4. Average fuel height, 'fuel_height' (input)
// 5. Rate of spread for zero wind, 'R0' (input), recommended as 5 m/min.
// 6. Solar radiation factor, 'delta' (input), {0,1}, delta = 1 for sunny days from 12:00 - 17:00 from October to March (high solar radiation) and 0 otherwise.
// -------------------------------------------

//Wind reduction factor, 'WF' (input), 0.67 for heath-shrublands and 0.35 for woodlands.
float WF = 0.67;
int R0 = 5;

// Backing and flanking coefficients compared to head fire ROS
REAL wind_speed = length(wind_vector);
REAL wdot = dot(normalize(wind_vector),advect_normal_vector);

// Calculate length-to-breadth ratio (LBR) for grassland
REAL LBR = 1.0;
if (wind_speed < 5){
    LBR = 1.0; 
} else { 
    LBR = 1.1*pow(wind_speed, 0.464); 
} 

// Determine coefficient for flank rank of spread
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

// Initialising the solar radiation variable 
REAL delta; 
if (hour > 11 && hour < 17){
    delta = 1;}
else {
    delta = 0;}

// Calculating moisture content 
REAL MC = 4.37 + 0.161*rel_hum - 0.1*(temp - 25) - delta * 0.027 * rel_hum;

REAL head_speed;
// Calculating rate of spread in m/min
if (wind_speed < 5){
    head_speed = (R0 + 0.2*(5.67*pow(5*WF, 0.91) - R0)*wind_speed) * pow(fuel_height, 0.22) * exp(-0.076*MC);
} else {
    head_speed = 5.67 * pow(WF*wind_speed, 0.91) * pow(fuel_height, 0.22) * exp(-0.076*MC); }

// Converting spread rate into m/s
head_speed = head_speed / 60;

// Adjust for calculated speed coefficient for fire flanks
speed = head_speed * speed_fraction;