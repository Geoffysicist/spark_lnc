// Buttongrass moorland model
// Marsden-Smedley and Catchpole (1995)

// -------------------------------------------
// Model parameters
// 1. Dew point temperature, 'dew_temp'  (input)
// 2. Relative humidity, 'rel_hum' (input)
// 3. Fuel age 'fire_history' (yrs)
// -------------------------------------------

// Backing and flanking coefficients compared to head fire ROS
REAL wind_speed = length(wind_vector);
REAL wdot = dot(normalize(wind_vector),advect_normal_vector);

// Calculate length-to-breadth ratio (LBR) for grassland (in lieu of an equation for buttongrass)
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

// Calculating magnitude of 2m wind
REAL wind_2m_mag = length(wind_vector*0.666);

// Calculate moisture
REAL mc = exp(1.660+0.0214*rel_hum-0.0292*dew_temp);

// Calculate head fire rate of spread
REAL head_speed = 0.678*pow(wind_2m_mag, 1.312)*exp(-0.0243*mc)*(1-exp(-0.116*fire_history))*0.0166667;

// Adjust for calculated speed coefficient for fire flanks
speed = speed_fraction * head_speed;