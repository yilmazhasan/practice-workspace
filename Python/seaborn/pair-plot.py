import numpy as np; np.random.seed(0)
import seaborn as sns; sns.set_theme()
import matplotlib.pyplot as plt
import random
import pandas as pd

ar = []
for i in range(5):
    ar.append(random.random() * 3)
#    r1 = r1.set_value(i, random.random() * 3)
r1 =pd.Series( ar)
print(ar)

ar = []
for i in range(5):
    ar.append(np.random.rand()*4)
#    r2 = r2.set_value(i, np.random.rand()*4)
r2 =pd.Series( ar)
print(ar)

ar = []
for i in range(5):
    ar.append(np.random.rand()*5)
#    r3 = r3.set_value(i, np.random.rand()*5)
r3 =pd.Series( ar)
print(ar)

df = pd.concat([r1, r2, r3], axis = 1) # if axis is not provided, concatenates all as oneDim array
# or
#df = pd.DataFrame({'r1': r1, 'r2': r2, 'r3': r3})
# plot pair scatter chart, see correlation visually
sns.pairplot(df)

plt.show()