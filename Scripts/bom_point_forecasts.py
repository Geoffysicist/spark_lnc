"""bom_point_forecasts - reads a time series of weather data from a BOM Point Forecast csv file.

Inputs from Spark:
fileName      pathname of the input csv file
timeZone      UTC offset eg. +11:00

Variables read from csv file - order of columns:
date          Local Date 'DD Mmm YYY'
time          Local Time 'HH:MM'
temp          Air temperature 'Temp (C)'
rel_hum       Relative humidity 'RH (%)'.
wind_speed    Wind speed 'Wind Speed (km/h)'.
wind_dir      Wind bearing in degrees 'Wind Dir'.
drought_fac   'Drought factor' (1-10).
ffdi          Forest Fire Danger Index 'FFDI'
gfdi          Grass Fire Danger Index 'GFDI'.


If debugging outside of Spark must set input varriables

"""
import csv
import datetime as dt

months = ['Jan', 'Feb', 'Mar', 'Apr', 'May', 'Jun', 'Jul', 'Aug', 'Sep', 'Oct', 'Nov', 'Dec']


DEBUG = True  #set to True if debugging outside of Spark

# set input variables if debugging outside of Spark
if DEBUG:
    fileName = "./Input/weather_series/2020-08-21-08-08-07_PointForecast.csv"
    timeZone = "+10:00"
    time = []
    wind_speed = []
    wind_dir = []
    temp = []
    rel_hum = []
    dew_temp = []
    drought_fac = []





with open(fileName) as f:
    weather = csv.reader(f)
    header = True
    series_array = [temp, rel_hum, wind_dir, wind_speed, drought_fac]
    
    for row in weather:
        try:
            d = row[0].split(' ')
            date = dt.date(int(d[2]), int(months.index(d[1])+1), int(d[0]))
            weather_data = row[2:]
            time.append(f'{date.isoformat()}T{row[1]}:00{timeZone}')
            for i in range(len(series_array)):
                series_array[i].append(weather_data[i])


        except IndexError: # not a date of type "DD Mmm YYYY"            
            if DEBUG: print('not a date')
        
            # populate series


if DEBUG:
    for t in range(len(time)):
        print(time[t], end='\t')
        for r in range(len(series_array)):
            try:
                print(f"{series_array[r][t]}", end="\t")
            except IndexError:
                print("", end="\t")
        print('')