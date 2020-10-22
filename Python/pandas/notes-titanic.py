# Loading Libraries
import numpy as np
import pandas as pd

# ignoring warnings
import warnings
warnings.filterwarnings("ignore")


#load data
#chicago_data = pd.read_csv("https://raw.githubusercontent.com/dphi-official/Datasets/master/Chicago_Crime_Detective.csv")

#dataframe, red_wine_data
df = pd.read_csv('https://raw.githubusercontent.com/dphi-official/Datasets/master/Wine_Dataset/winequality-red.csv', index_col=None, na_values=['NA'],sep=';')

df.head()
df.shape
df.describe() # statistical overwiew
df.info() # Concise summary of data

# missing values
df.is_null().sum()

# filter, remove nulls
df[df["quality"].isnull()]
df.quality[df.quality.notna()]

df.quality.fillna(df["quality"].mean(), inplace="True")

# correlation
df.corr()

# converts values into binary
df.get_dummies(df, columns=['LocationDescription']) # generates new columns such as 'LocationDescription_Street'

#columns
df.columns

df['quality'].unique()
df['quality'].value_counts() # gives frequencies

df.rename(columns={'fixed acidity': 'fixed_acidity'}, inplace=True) # old_name:new_name (inplace makes changes dataframe itself)
x = df.drop('quality', axis = 1) # Input variables/features
y = df.quality # Output variables/features




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