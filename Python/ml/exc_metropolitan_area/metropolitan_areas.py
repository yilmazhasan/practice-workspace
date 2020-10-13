import numpy as np # linear algebra
import pandas as pd # data processing, CSV file I/O (e.g. pd.read_csv)

# https://docs.google.com/spreadsheets/d/1rruRHMCALDpWSSzKIHTl9Yello4y-xsWaIL1V8b9dwU/edit#gid=0
data = pd.read_csv('C:\\Users\\hasany\\source\\personal\\practice-workspace\\Python\\ml\\exc_metropolitan_area\\StandardMetropolitanAreasData_train_data.csv')

data.head()

X = data.drop('crime_rate', axis = 1)
y = data['crime_rate']

from sklearn.model_selection import train_test_split
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.33, random_state=42)

# Building model

from sklearn.tree import DecisionTreeClassifier
model = DecisionTreeClassifier()
model.fit(X_train, y_train)


#Evaluate the model
from sklearn.metrics import accuracy_score
print('Training accuracy...', accuracy_score(y_train, model.predict(X_train)))
print('Test accuracy', accuracy_score(y_test, model.predict(X_test)))

# note: The large difference between the training score and the validation score suggets that our model overfits.

# viualize decision tree

from sklearn.tree import export_graphviz
import graphviz

dot_data= export_graphviz(model, out_file=None, 
                    feature_names=X_test.columns,  
                      class_names=['0', '1'],  
                      filled=True, rounded=True,  
                      special_characters=True)

graph1=graphviz.Source(dot_data)
graph1

# improve model, by setting max_depth
# We can reduce overfitting by limiting the number of "questions" that the model is allowed to ask. as each node in the tree is a question, by limiting the depth of the tree we can limit the number of questions.
model_improved = DecisionTreeClassifier(max_depth = 3)
model_improved.fit(X_train, y_train)

print('train score...' , accuracy_score(y_train, model_improved.predict(X_train)))
print('test score...', accuracy_score(y_test, model_improved.predict(X_test)))

dot_data= export_graphviz(model_improved, out_file=None,impurity=False, 
                    feature_names=X_test.columns,  
                      class_names=['0', '1'],  
                      filled=True, rounded=True)

graph2=graphviz.Source(dot_data)
graph2