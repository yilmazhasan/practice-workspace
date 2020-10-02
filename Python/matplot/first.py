import matplotlib.pyplot as plt
import numpy as np
import pandas as pd

x = pd.read_csv("https://raw.githubusercontent.com/dphi-official/Datasets/master/Standard_Metropolitan_Areas_Data-data.csv")

x.head() # check all variables are there in the dataset

# print(x.head())


#plt.scatter(x.crime_rate, x.percent_senior)
# line chart

#plt.plot(x.work_force, x.income)
#plt.hist(x.percent_senior)

# color is with full name or a char for rgbcmyk, or can be given as a num between [0,1]  
plt.bar(x.region, x.crime_rate, color="r", label = "for legend")
#plt.barh(x.region, x.crime_rate)    ## horizontal

plt.title("Title")
plt.xlabel("X")
plt.ylabel("Y")

# add a legend
plt.legend()

plt.show()