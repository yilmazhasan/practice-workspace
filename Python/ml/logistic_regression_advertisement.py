import pandas as pd                   # Data analysis and manipulation tool
import numpy as np                    # A fundamental package for scientific computing with Python
import matplotlib.pyplot as plt       # For interactive visualization in Python
import seaborn as sns                 # Data visualization library based on matplotlib. It provides a high-level interface 
                                      # for drawing attractive and informative statistical graphics.


data = pd.read_csv('https://raw.githubusercontent.com/dphi-official/Logistic-Regression/master/advertisement_data.csv')


data.head()             # Returns first five observations / records from the data.



data.info()          # Returns a concise summary of a dataframe

# Basic statistical details 
data.describe()


# Plotting histogram of the age variable
sns.set_style('whitegrid')            # sets the style of the plots; it affects things like color of the axes, whether grid enabled or not.
data['Age'].hist(bins=30)             # plots histogram with with bins = 30
plt.xlabel('Age')                     # labels the x - axis as 'Age'
plt.ylabel('Number of data points')   # labels y - axis as 'Number of data points'



# Joint plot for 'Area Income' and 'Age'
# Plots two variables with bivariate and univariate graphs 
sns.jointplot(x='Age',y='Area Income',data=data)



sns.jointplot(x='Age',y='Area Income',data=data, kind = 'reg')    # with regression line in the scatter plot and kernel density curve in both histograms



sns.jointplot(x='Age',y='Daily Time Spent on Site',data=data,color='red',kind='kde')    # will show joint plot with kernel density estimates


sns.jointplot(x='Daily Time Spent on Site',y='Daily Internet Usage',data=data,color='green')

sns.pairplot(data,hue='Clicked on Ad',palette='bwr')     # plots pairwise relationships between different features
                                                         # 'hue' will separate people who clicked on add from people who did not clicked on add


                                                         