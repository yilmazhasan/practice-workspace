import numpy as np # linear algebra
import pandas as pd # data processing, CSV file I/O (e.g. pd.read_csv)
import matplotlib.pyplot as plt

from sklearn.linear_model import LinearRegression

area = [2600, 3000, 3200, 3600, 4000]
price = [550000, 565000, 610000, 680000, 715000]

# X = np.array([[1, 1], [1, 2], [2, 2], [2, 3]])
# y = 1 * x_0 + 2 * x_1 + 3

X = [[area[i]] for i in range(5)]
y = price

reg = LinearRegression()
reg.fit(X, y)

def myfunc(x):
  return reg.coef_ * x + reg.intercept_

mymodel = list(map(myfunc, X))

plt.scatter(X, y)
plt.plot(X, mymodel)
plt.show()

print(reg.predict([[3300]]))
