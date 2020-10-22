import matplotlib.pyplot as plt
import pandas as pd
import numpy as np

def draw_histograms(dataframe, features, rows, cols):
    fig = plt.figure(figsize = (20,20))
    for i, feature in enumerate(features):
        ax = fig.add_subplot(rows, cols, i+1)
        dataframe[feature].hist(bins=20,ax=ax,facecolor='midnightblue')
        ax.set_title(feature + 'Distribution', color='DarkRed')

    fig.tight_layout()
    plt.show()


s1 = pd.Series([1,2,3])
s2 = pd.Series([20,40,60])

df = pd.DataFrame(np.array([s1,s2]).transpose())
df.columns = ["day", "earnings"]
draw_histograms(df, df.columns, 2, 3) 