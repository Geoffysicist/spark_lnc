//Initialise the custom inputs for the Dry Schlorophyll model
// modified geoff.goldrick@protonmail.com 2020-08-18 

// Set dry eucalypt parameters
bool useExponential = false;
bool useTall = true;
if (useExponential) {

  // Gould 2011 exponential model, uses fire_history in years
  if (useTall) {

    // Tall shrub
    fhs_surface = 3.39*(1-exp(-0.030*fire_history*12));
    fhs_near_surface = 2.95*(1-exp(-0.022*fire_history*12));
    h_near_surface = 23.33*(1-exp(-0.025*fire_history*12));

  } else {

    // Low shrub
    fhs_surface = 3.33*(1-exp(-1*0.035*fire_history*12));
    fhs_near_surface = 2.81*(1-exp(-1*0.018*fire_history*12));
    h_near_surface = 20.02*(1-exp(-1*0.035*fire_history*12));
  }
} else {

  // Gould 2011 hyperbolic model, uses fire_history in years
  if (useTall) {

    // Tall shrub
    fhs_surface = (4.03*fire_history*12)/(27.93+fire_history*12);
    fhs_near_surface = (3.77*fire_history*12)/(48.93+fire_history*12);
    h_near_surface = (28.11*fire_history*12)/(33.84+fire_history*12);

  } else {

    // Low shrub
    fhs_surface = (3.78*fire_history*12)/(20.69+fire_history*12);
    fhs_near_surface = (3.44*fire_history*12)/(50.73+fire_history*12);
    h_near_surface = (22.22*fire_history*12)/(18.55+fire_history*12);
  }
}
