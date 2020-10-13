# Loading Libraries
import numpy as np
import seaborn as sns

# ignoring warnings
import warnings
warnings.filterwarnings("ignore")


plt.figure(figsize=(16,12))
sns.heatmap(data.corr(), cmap = 'bwr', annot=True)

# annot : to display the corr value in graph
# cmap: specify color theme of heatmap

# plot histogram
#sns.countplot(data)


# seperate input and target variables

y = df['quality']   # set quality as target variable (Y)
x = df.drop('quality', axis=1) # all columns except quality will be input variables (X)
