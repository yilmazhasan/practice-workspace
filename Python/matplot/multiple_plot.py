import matplotlib.pyplot as plt
import numpy as np
import pandas as pd

x = pd.read_csv("https://raw.githubusercontent.com/dphi-official/Datasets/master/Standard_Metropolitan_Areas_Data-data.csv")

x.head() # check all variables are there in the dataset


# color is with full name or a char for rgbcmyk, or can be given as a num between [0,1]  

row = 1; col = 2; index = 1 # index 1 means this subplot will be displayed first
plt.subplot(row, col, index)

plt.plot(x.work_force, x.income, "go")
plt.title("Income vs Work Force")

row = 1; col = 2; index = 2 # index 2 means this subplot will be displayed at the 2nd pos
plt.subplot(row, col, index)

plt.plot(x.hospital_beds, x.income, "r^")
plt.title("Income vs Hospital Beds")

plt.suptitle("Sub Plots") # add a centered title to the figure

plt.show()