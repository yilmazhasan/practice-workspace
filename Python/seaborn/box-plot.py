import numpy as np; np.random.seed(0)
import seaborn as sns; sns.set_theme()
import matplotlib.pyplot as plt
import random
import pandas as pd

ar = []
for i in range(5):
    ar.append(i * 2)
    ar.append(i * 3)
r1 =pd.Series( ar)
print(ar)

ar = []
for i in range(5):
    ar.append(i*4)
    ar.append(i*4)
r2 =pd.Series( ar)
print(ar)

# first is y axis, second is x
df = pd.DataFrame({'quality': r1, 'rate': r2})

sns.boxplot(df['rate'], df['quality'], palette='GnBu_d')
plt.title('Boxplot of Quality and Rate')

plt.show()