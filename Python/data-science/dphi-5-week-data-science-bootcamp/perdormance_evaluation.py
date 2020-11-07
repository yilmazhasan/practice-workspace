
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import warnings
warnings.filterwarnings("ignore")
%matplotlib inline


# since the column names are numerical, we will give our own column names for our understanding
col = ["num_preg", "plasma_glucose_conc", "D_blood_pressure", "skin_fold_thickness", "serum_insulin", "body_mass_index", "pedigree_func", "age", "diabetes"]
diabetes_data = pd.read_csv("https://raw.githubusercontent.com/dphi-official/ML_Models/master/Performance_Evaluation/diabetes.txt", names = col)


diabetes_data.head()

# Seperating Input variables and output variable
X = diabetes_data.drop('diabetes', axis = 1)
y = diabetes_data.diabetes

#Split into training and testing
from sklearn.model_selection import train_test_split
x_train, x_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=3)

# The below line of code will not need to separate input variables and output variables.
# The code is very simple if you remember numpy and pandas session. Indexing dataframe and arrays
# x_train, x_test, y_train, y_test = train_test_split(diabetes.iloc[:, :-1], diabetes.iloc[:,-1], test_size=0.2, random_state=3)

# Developing a model
from sklearn.neural_network import MLPClassifier
mlp = MLPClassifier(max_iter=1000)
mlp.fit(x_train, y_train)
y_pred = mlp.predict(x_test)

# Confusion Matrix
from sklearn.metrics import confusion_matrix
confusion_matrix(y_test, y_pred)
# TN FP
# FN TP

tn, fp, fn, tp = confusion_matrix(y_test, y_pred).ravel()     # ravel() is used to convert a 2D array to 1D array. The output by confusion matrix is a 2D array.
print("True Positive", tp)
print("True Negative", tn)
print("False Positive", fp)
print("False Negative", fn)

# Accuracy
#(TP + TN) / (TP + TN + FN + FP)
from sklearn.metrics import accuracy_score
acc = accuracy_score(y_test, y_pred)
acc

# When is it good to use accuracy score as a model evaluation metric?
#The classifications in the dataset is nearly symmetrical (means equal distribution of all the classes).
#The false positive and false negative on test data are nearly equal.

# Recall (Sensitivity)
# TP / (TP + FN)

from sklearn.metrics import recall_score
recall_score(y_test, y_pred)


## Recall (Specificity)
# TN / (TN + FP)
# sklearn does not have an inbuild function for Specificity. 
#But by adding parameter pos_label =0 to the recall function, 
#we treat that as the positive class, and hence gives the correct output

## Specificty
print("Specificity with recall pos label=0: ",recall_score(y_test, y_pred, pos_label=0))
# Checking with formulas
print("Specificity with Formulas: ", tn/(tn+fp))

## Precision
# TP / (TP + FP)

from sklearn.metrics import precision_score
precision_score(y_test, y_pred)


# Imbalanced Datasets
diabetes_data.iloc[:,-1].value_counts()

# Matthews Correlation Coefficient
# MC = ((TP * TN) - (FP * FN)) / (sqrt((TP+FP) * (TP*FN) * (TN*FP) * (TN*FN))
from sklearn.metrics import matthews_corrcoef
print("MCC Score: ",matthews_corrcoef(y_test, y_pred))

# F1 Score
# (2 * Precision * Recall) / (Precision + Recall)


from sklearn.metrics import f1_score
print("F1 Score: ",f1_score(y_test, y_pred))


#Area Under the Curve (Reciever Operating Characterstics)
from sklearn.metrics import plot_roc_curve

plot_roc_curve(mlp, x_test, y_test)
plt.show()


# 1.2 Regression Evaluation Metrics
wine = pd.read_csv("https://raw.githubusercontent.com/dphi-official/ML_Models/master/Performance_Evaluation/winequality.csv", sep=";")
wine.head()

# Seperate Input and Output Variables

X = wine.drop('quality', axis = 1)
y = wine.quality


# Split
# Here we are performing both separation of input and output variable and the splitting.
from sklearn.model_selection import train_test_split
x_train, x_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=3)

from sklearn.linear_model import LinearRegression

lr = LinearRegression()
lr.fit(x_train, y_train)
y_pred = lr.predict(x_test)
y_pred[:10]

# Performance Measurement
# Mean Absoule Error
# MAE = (1 / n ) * Sum(abs(y-y_pred))

from sklearn.metrics import mean_absolute_error
mean_absolute_error(y_test, y_pred)

# Mean Squared Error
# MAE = (1 / n ) * Sum(square(y-y_pred))

from sklearn.metrics import mean_squared_error
print("Mean Squared Error: ",mean_squared_error(y_test, y_pred))

# Root Mean Square Error 
print("Root Mean Squared Error: ",mean_squared_error(y_test, y_pred, squared=False))

# R Squared
# The metric helps us to compare our current model with a constant baseline and tells us how much our model is better
# R^2 = 1 - MSE(Model)/ MSE(Baseline)
from sklearn.metrics import r2_score
r2_score(y_test, y_pred)

## 2 Cross Validation

# Here the diabetes data is use
# separate input and output vairables
X = diabetes_data.drop('diabetes', axis = 1)
y = diabetes_data.diabetes



# 2.1 K-Fold Cross Validation
from sklearn.model_selection import cross_validate
cv_results = cross_validate(mlp, X, y, cv=10, scoring=["accuracy", "precision", "recall"])

print("Accuracy: ", cv_results["test_accuracy"].mean())
print("Precision: ", cv_results["test_precision"].mean())
print("Recall: ", cv_results["test_recall"].mean())


import sklearn.metrics as m
m.SCORERS.keys()


# 2.2 Leave One out Cross Validation
from sklearn.model_selection import LeaveOneOut

cv_results = cross_validate(mlp, X, y,
                            cv=LeaveOneOut(), scoring=["accuracy"])
cv_results

cv_results['test_accuracy'].mean()


# 3. Hyper Parameter Tuning

# 3.1 GridSearchCV
# 3.1.1 Crime Rate-Linear Regression
