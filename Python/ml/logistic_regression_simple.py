# ref: https://www.kaggle.com/parulpandey/deep-dive-into-logistic-regression-for-beginners

import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
%matplotlib inline

from sklearn.linear_model import LogisticRegression
from sklearn.model_selection import train_test_split

data = np.array([
    [22,0], [21,0], [19,0], [15,0], [17,0], [24,1], [16,0], [18,0], [40,1], [47,1], [48,1], [49,1], [50,1], 
    [53,0], [54,1], [55,0], [56,1], [57,1], [58,1], [59,1], [60,1], [62,1]])

df = pd.DataFrame(data, [i for i in range(len(data))], ["age", "bought_insurance"])
plt.scatter(df.age, df.bought_insurance, marker='+', color='red')
plt.show()

X_train, X_test, Y_train, Y_test = train_test_split(df[['age']], df.bought_insurance, test_size=0.1) 

model = LogisticRegression()
model.fit(X_train, Y_train)

model.predict(X_test)

model.score(X_test, Y_test)

model.predict_proba(X_test) # returns the probability of bought insurance and not (notice sum of two is 1)

model.predict(np.array([[55]]))