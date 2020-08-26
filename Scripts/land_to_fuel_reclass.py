''' land_to_fuel reclass - reclassify a land class raster to a fuel class.

Uses a csv lookup table to reclassify a land class into a fuel class
Generates an OpenCL C script and appends that to the initString variable of the 
Spark framework so that it executes between the start init code and the end init code.

Inputs:
fileName - the filename of the *.csv lookup table
'''

DEBUG = True  #set True if running this script outside of the Spark framework

import csv

#-----------------------------------------------------------------
# a bit of set up stuff

lc_header = 'Land class'
lc_description = 'Description'
fc_header = 'Fuel class'

spread_models = ['unburnable', 
                'fc_grassland',
                'fc_woodland',
                'fc_sclerophyll_dry',
                'fc_sclerophyll_wet',
                'fc_rainforest',
                'fc_other_forest',
                'fc_heath_coastal',
                'fc_heath_semi_arid',
                'fc_pine',
                'fc_moorlands',
                'fc_wetlands',
                'fc_urban']

if DEBUG:
    fileName = './Input/vegetation_lookup/lnc_vegetation_2.csv'
    fileName2 = './Scripts/initStr_starter.c'
    initString = ""


#------------------------------------------------------------------
# Define fuel classes and land classes as objects

class FuelClass(object):
    ''' Fuel type class.

    Used to store attributes of the fuel class including a list
    of the land classes it is comprised of. The land classes should correspond to the
    'land classification' raster layer in the Spark framework.

    Attributes:
        _fuel_class: an integer between 1 and 12 corresponding to a Spark spread model.
        _land_classes[]: a list of the land classes comprising the fuel class.
        _name: a string naming the class, default value ""
        _description: a string giving a short deacription of the class, default value ""

    '''

    def __init__(self, fuel_class: int):
        '''Inits FuelClass with a class corrspondinig to the Spark spread models.
        
        The value of fuel_class should be between 1 and 12.
        '''
        self._fuel_class = fuel_class
        self._land_classes = []
        self._name = ""
        self._description = ""

    def add_land_class(self, land_class):
        '''adds a land class to the list of land classes that comprise this fuel class.'''
        self._land_classes.append(land_class)

    def set_name(self, name: str):
        '''Sets the name of the fuel class.'''
        self._name = name

    def set_description(self, description: str):
        '''Sets the description of the fuel class.'''
        self._description = description

    def get_class(self) -> int:
        '''Gets the name of the fuel class.'''
        return self._fuel_class

    def get_name(self) -> str:
        '''Gets the name of the fuel class.'''
        return self._name

    def get_description(self) -> str:
        '''Gets the description of the fuel class.'''
        return self._description

    def get_land_classes(self):
        return self._land_classes

class LandClass(object):
    ''' Land type class.

    Used to hold attributes of a land classes.

    Attributes:
        _land_class: an integer corresponding to the Spark land classification raster and the lookup csv
        _name: a string naming the class, default value ""
        _description: a string giving a short deacription of the class, default value ""
        _fuel_class: int indicating the fuelclass to which it belongs
    '''

    def __init__(self, land_class: int):
        '''Inits LandClass with a class corrsponding to a column in the lookup csv
        '''

        self._land_class = land_class
        self._name = ""
        self._description = ""

    def set_name(self, name: str):
        '''Sets the name of the land class.'''
        self._name = name

    def set_description(self, description: str):
        '''Sets the description of the land class.'''
        self._description = description

    def get_class(self) -> int:
        '''Gets the name of the land class.'''
        return self._land_class

    def get_name(self) -> str:
        '''Gets the name of the land class.'''
        return self._name

    def get_description(self) -> str:
        '''Gets the description of the land class.'''
        return self._description

#---------------------------------------------------------
# now shit gets real

headers = True #set true for first row of lookup table to get header indices
lc_idx = -1
lc_desc_idx = -1
fc_idx = -1

lc_idx_array = [] # a list of unique land indices. Used to prevent duplication.
fc_idx_array = [] # a list of unique fuel indices. Used to prevent duplication.
# lc_array = []
fc_array = []

with open(fileName) as f:
    lookup = csv.reader(f)
    header = True

    for row in lookup:
        if header: # find the columns indices
            for i in range(len(row)):
                if row[i] == lc_header:
                    lc_idx = i
                elif row[i] == lc_description:
                    lc_desc_idx = i
                elif row[i] == fc_header:
                    fc_idx = i
        
            header = False

        else:
            if row[fc_idx] not in fc_idx_array: #need to create a new fuel class
                fc = FuelClass(row[fc_idx])
                fc_idx_array.append(row[fc_idx])
                fc_array.append(fc)
            
            if row[lc_idx] not in lc_idx_array: # need to create new land class
                lc = LandClass(row[lc_idx])
                if lc_desc_idx > -1:
                    lc.set_description(row[lc_desc_idx])
                lc_idx_array.append(row[lc_idx])
                # lc_array.append(lc)

                # add the new land class to the relevant fuel class
                for fc in fc_array:
                    if fc.get_class() == row[fc_idx]:
                        fc.add_land_class(lc)
                
if DEBUG:
    #print out the list of fuel classes and their land classes                
    for fc in fc_array:
        land_class_str = ' '.join([str(elem.get_class()) for elem in fc.get_land_classes()]) 
        print(f'fuel class: {fc.get_class()}, land classes: {land_class_str}')

    print('\n\n')        

    
with open(fileName2) as s:
    s_lines = s.readlines()

for line in s_lines:
    initString += line
    
    if 'insert reclass rules here' in line:
        for fc in fc_array:
            for lc in fc.get_land_classes():
                initString += f'    case {lc.get_class()}:    // {lc.get_description()}\n'

            initString += f'        class = {fc.get_class()};    // {spread_models[int(fc.get_class())]}\n'
            initString += '        break;\n\n'

if DEBUG:
    with open('./Scripts/landclass_to_fuelclass.c', 'w') as f:
        f.write(initString)
        print('output to ./Scripts/landclass_to_fuelclass.c\n\n')