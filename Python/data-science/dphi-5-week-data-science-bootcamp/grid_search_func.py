# Errror on grid_func -> ValueError: n_splits=5 cannot be greater than the number of members in each class.
#from sklearn.metrics import accuracy_score
from sklearn.ensemble import RandomForestClassifier
from sklearn.metrics import make_scorer
from sklearn.metrics import accuracy_score
from sklearn.model_selection import GridSearchCV

# defined a function for implementing hyper parameter tuning
def grid_func(classifier, parameter, X_train, y_train):
    clf = classifier
    np.random.seed(9)
    parameters = parameter
    acc_scorer = make_scorer(accuracy_score)

    # run the grid search func
    grid_obj = GridSearchCV(clf, parameters, scoring=acc_scorer)
    grid_obj = grid_obj.fit(X_train, y_train)
    return grid_obj
 
# plot mean scores for a particular grid object 
def hp_cv_scores(grid_obj):
    grid_obj.cv_results_
    mean_test_scores = grid_obj.cv_results_['mean_test_score']
    mean_train_scores = grid_obj.cv_results_['mean_train_score']
    plt.figure(figsize=(10, 6))

    param_values = [str(x) for x in grid_obj.param_grid.values()[0]]
    x= np.arange(1,len(param_values)+1)

    plt.plot(x, mean_train_scores, c='r', label='Train set')
    plt.xticks(x, param_values)
    plt.plot(x,mean_test_scores, c='g', label='Test set')
    plt.xlabel(grid_obj.param_grid.keys()[0])
    plt.ylabel('mean_scores')
    plt.legend()
    plt.show()


classifier= RandomForestClassifier(random_state=9)

##### train ex data #Loading the salary dataset
data = pd.read_csv('https://raw.githubusercontent.com/dphi-official/Linear_Regression_Introduction/master/Salary_Data.csv')
X = data[['YearsExperience']]
y = data['Salary']
from sklearn.model_selection import train_test_split 
# Assign variables to capture train test split output
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.3, random_state=47)
#####

# plotting the graph to find the variation in model for given n_estimators -- NEEDS LEG
grid = grid_func(classifier, {'n_estimators': [2,3,4]}, X_train, y_train)
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


'''parameter = {
    'n_estimators': [10, 50, 100],
    'max_features': ['log2', 'sqrt'],
    'criterion': ['entropy', 'gini'],
    'max_depth': [2,4,6],
    'n_estimators': [10, 50, 100],
    'min_samples_split': [2, 3, 5],
    'min_samples_leaf': [1, 3, 5]

}'''