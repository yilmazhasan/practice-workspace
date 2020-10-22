# import metrics library
from sklearn import metrics
import numpy as np

y_test = [1,2,3]
y_pred = [2,1,5]

# print result of MAE
print(metrics.mean_absolute_error(y_test, y_pred))

#print result of MSE
print(metrics.mean_squared_error(y_test, y_pred))

#print result of RMSE
print(np.sqrt(metrics.mean_squared_error(y_test, y_pred)))