# ref: https://github.com/dphi-official/ML_Models/blob/master/Model_Optimisation/notebooks/random_forest_slides.ipynb

# Importing necessary packages
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
%matplotlib inline

from sklearn.model_selection import train_test_split, GridSearchCV
from sklearn.ensemble import RandomForestClassifier, RandomForestRegressor
from sklearn.metrics import accuracy_score, roc_auc_score, make_scorer

#ignoring the warnings
import warnings
warnings.filterwarnings('ignore')

# Reading data & separating it into train and test
# Splitting the data into training and target set

dataframe = pd.read_csv('https://raw.githubusercontent.com/dphi-official/ML_Models/master/Model_Optimisation/data/loan_prediction.csv')

dataframe.head()

# Splitting into input and target variable
# Here, target = Credit_History
y = dataframe[['Credit_History']]
X = dataframe.drop(['Credit_History', 'Loan_Status'], axis=1)

np.random.seed(9)
# splitting into train and test set            
X_train,X_test,y_train,y_test = train_test_split(X,y,test_size = 0.3, 
                                                 random_state = 42)

#model for tuning the min samples of leaf
clf_1 = RandomForestClassifier(min_samples_leaf=2, random_state=9)
clf_1.fit(X_train,y_train)

# One with min_samples_leaf set, one with max_depth set
# model for tuning the max depth
clf_2 = RandomForestClassifier(max_depth = 5, random_state=9)
clf_2.fit(X_train,y_train)

# predicting for min_samples 0f leaf as 2.
y_clf_1 = clf_1.predict(X_test)

# predicting for max depth 5.
y_clf_2 = clf_2.predict(X_test)

#calculate accuracy and roc auc score for min leaf samples
accuracy_clf_1 = accuracy_score(y_test, y_clf_1)
auc_roc1 = roc_auc_score(y_test, y_clf_1,  multi_class="ovr")
print("Accuracy score of the model with min sample leaf 2 is: {}".format(accuracy_clf_1))
print("roc_auc_score of the model1 is: {}".format(auc_roc1))

print("\n")

#calculate accuracy and roc auc score for max depth 5
accuracy_clf_2 = accuracy_score(y_test,y_clf_2)
auc_roc2 = roc_auc_score(y_test, y_clf_2,  multi_class="ovr")
print("Accuracy score of the model with max depth 5 is: {}".format(accuracy_clf_2))
print("roc_auc_score of the model2 is: {}".format(auc_roc2))


# Defined a custom function for implementing hyper parameter tuning
def gridfunc(classifier, parameter, X_train, y_train):
        
    clf = classifier
    np.random.seed(9)
    parameters = parameter
    acc_scorer = make_scorer(accuracy_score)
    
    # Run the grid search
    grid_obj = GridSearchCV(clf, parameters, scoring=acc_scorer, return_train_score=True)
    grid_obj = grid_obj.fit(X_train, y_train) 
    
    return grid_obj

# plot mean scores for a particular grid object 
#function for plotting mean scores for a particular grid object
def hp_cv_scores(grid_obj):
    grid_obj.cv_results_  #A dictionary with keys as column title and values as columns
    mean_test_scores = grid_obj.cv_results_['mean_test_score'] #Adding 'mean_test_score' as a key
    mean_train_scores = grid_obj.cv_results_['mean_train_score'] #Adding 'mean_train_score' as a key
    
    plt.figure(figsize=(10,6))
    
    # the below lines just fill up the column using the various parameter values we want to try
    all_vals = list(grid_obj.param_grid.values())
    param_values =[str(x) for x in all_vals[0]]
    
    # The below line creates values for ticks on x axis. If there are 2 parameter values to be tried, it'll create 2 ticks
    x = np.arange(1, len(param_values)+1)
     
    plt.plot(x,mean_train_scores, c='r', label='Train set') #Plotting the mean_train_scores in red
    
    plt.xticks(x,param_values)
    
    plt.plot(x,mean_test_scores,c='g', label='Test set') #Plotting the mean_test_scores in red
    plt.xlabel(list(grid_obj.param_grid.keys())[0]) #Label of the column will be the hyperparameter
    plt.ylabel('mean scores')
    plt.legend()
    plt.show()


classifier= RandomForestClassifier(random_state=9)

# plotting the graph to find the variation in model for given n_estimators -- NEEDS LEG
# note: .values will give the values in an array. (shape: (n,1) 
#.ravel will convert that array shape to (n, )
grid = grid_func(classifier, {'n_estimators': [2,3,4]}, X_train, y_train.values.ravel())
hp_cv_scores(grid)

# plotting the graph to find the variation in model for given max_features
grid = grid_func(classifier, {'max_features': ['log2', 'sqrt']}, X_train, y_train)
hp_cv_scores(grid)

# plotting the graph to find the variation in model for given criterion
grid = grid_func(classifier, {'criterion': ['entropy', 'gini']}, X_train, y_train)
hp_cv_scores(grid)

# plotting the graph to find the variation in model for given max depth
grid = grid_func(classifier, {'max_depth': [2, 4, 6, 8, 16]}, X_train, y_train)
hp_cv_scores(grid)

# plotting the graph to find the variation in model for given min samples split
grid = grid_func(classifier, {'min_samples_split': [2, 3, 5, 10, 15, 20, 25, 30, 35]}, X_train, y_train)
hp_cv_scores(grid)


# plotting the graph to find the variation in model for given min samples leaf
grid = grid_func(classifier, {'min_samples_leaf': [1, 3, 5, 8, 50, 100]}, X_train, y_train)
hp_cv_scores(grid)


# set the clf to the best combination of parameters
clf = grid.best_estimator_

# fit the best algorithm to the data
clf.fit(X_train, y_train)