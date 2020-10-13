# Loading Libraries
import numpy as np
import pandas as pd

# ignoring warnings
import warnings
warnings.filterwarnings("ignore")


#load data
#chicago_data = pd.read_csv("https://raw.githubusercontent.com/dphi-official/Datasets/master/Chicago_Crime_Detective.csv")

rwd = red_wine_data = pd.read_csv('https://raw.githubusercontent.com/dphi-official/Datasets/master/Wine_Dataset/winequality-red.csv', index_col=None, na_values=['NA'],sep=';')

rwd.head()
rwd.shape
rwd.describe() # statistical overwiew
rwd.info() # Concise summary of data
rwd[rwd["quality"].isnull]
rwd.quality.fillna(rwd["quality"].mean(), inplace="True")

# correlation
rwd.corr()

# converts values into binary
rwd.get_dummies(rwd, columns=['LocationDescription']) # generates new columns such as 'LocationDescription_Street'

#columns
rwd.columns

rwd['quality'].unique()
rwd['quality'].value_counts() # gives frequencies

rwd.rename(columns={'fixed acidity': 'fixed_acidity'}, inplace=True) # old_name:new_name (inplace makes changes dataframe itself)
x = rwd.drop('quality', axis = 1) # Input variables/features
y = rwd.quality # Output variables/features




#df['YearMonth'] = pd.Series([x.month for x in df['Date']])

#generate day series from dates
#a["Day"] = a["Date"].map(lambda x:  pd.to_datetime(x).day_name())


#filter by column values

a.loc[a['Arrest']==True]


#percentage

#a["Year"].value_counts(normalize=True)


# top 5 except for OTHER since OTHER is in top 5 we subtract it

#  a['LocationDescription'].value_counts().head(6).sum()- a.loc[a['LocationDescription'] == 'OTHER']['LocationDescription'].value_counts()

# df.loc[df['column_name'].isin(some_values)]
# df.loc[(df['column_name'] >= A) & (df['column_name'] <= B)]


# append
# df.append({'a':1, 'b': None}, ignore_index=True)