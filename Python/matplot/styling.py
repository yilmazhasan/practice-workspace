import matplotlib.pyplot as plt
import numpy as np
import pandas as pd

x = pd.read_csv("https://raw.githubusercontent.com/dphi-official/Datasets/master/Standard_Metropolitan_Areas_Data-data.csv")

x.head() # check all variables are there in the dataset


# color is with full name or a char for rgbcmyk, or can be given as a num between [0,1]  
plt.bar(x.region, x.crime_rate, color="r", label = "for legend")
#plt.barh(x.region, x.crime_rate)    ## horizontal

# STYLING
# linestyle='dashed' | linestyle='---' | linestyle='-' | 'dashdot' | 'dotted' | ':' | 'solid'
# marker = 'o' (for circe) | 'x' (for crosses) | '^'  (for triangle)
# linewidth=3

# COMBINE all STYLES: as last argument -> '--ro' : dashed, red, circular
# default is 'b-' which is solid blue line

plt.title("Title")
plt.xlabel("X")
plt.ylabel("Y")

# add a legend
plt.legend()

# SIZE

plt.figure(figsize=(width_ratio, height_ratio))   #  ratio

plt.show()