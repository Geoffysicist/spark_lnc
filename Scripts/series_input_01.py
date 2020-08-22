"""series_input_01 - reads a time series of weather data from a csv file for input into Spark.

Inputs from Spark:
fileName      pathname of the input csv file
timeZone      UTC offset eg. +11:00

Variables read from csv file:
time          datetime in ISO standard without the time zone. Example 2020-08-18T13:20:00
wind_speed    Wind speed (km/h).
wind_dir      Wind bearing in degrees.
temp          Air temperature (C).
rel_hum       Relative humidity (%).
dew_temp      Dew point temperature (C).
drought_fac   Drought factor (1-10).
fuel_state    Fuel state parameter.

Reads the first row as column headings and looks for the variables listed above.
Must use these exact variable names as the column headings!

If debugging outside of Spark must set input varriables

"""
import csv

DEBUG = True  #set to True if debugging outside of Spark

# set input variables if debugging outside of Spark
if DEBUG:
    fileName = "Input/weather_series/spark_test_lnc_amg_04.csv"
    timeZone = "+10:00"
    time = []
    wind_speed = []
    wind_dir = []
    temp = []
    rel_hum = []
    dew_temp = []
    drought_fac = []
    fuel_state = []




with open(fileName, 'rt') as f:
    reader = csv.reader(f)
    first_row = True
    series_array = [time, wind_speed, wind_dir, temp, rel_hum, dew_temp, drought_fac, fuel_state]
    series_array_headings = ['time', 'wind_speed', 'wind_dir', 'temp', 'rel_hum', 'dew_temp', 'drought_fac', 'fuel_state']
    series_array_idx = [99, 99, 99, 99, 99, 99, 99, 99]
    
    for row in reader:
        if first_row:
            # use headings (first row) to work out the column index
            for i in range(len(row)):
                for h in range(len(series_array_headings)):
                    if series_array_headings[h] == row[i]:
                        series_array_idx[h] = i
            first_row = False
        else:
            # populate series
            for i in range(len(series_array_idx)):
                if i == 0:
                    # time needs a timezone
                    series_array[i].append(f"{row[series_array_idx[i]]}{timeZone}")
                elif not series_array_idx[i] == 99:
                    series_array[i].append(row[series_array_idx[i]])

if DEBUG:
    for h in series_array_headings:
        print(h, end='    ')
    print('')

    for t in range(len(time)):
        for r in range(len(series_array)):
            try:
                print(f"{series_array[r][t]}", end="\t")
            except IndexError:
                print("", end="\t")
        print('')