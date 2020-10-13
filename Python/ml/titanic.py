import numpy as np # linear algebra
import pandas as pd # data processing, CSV file I/O (e.g. pd.read_csv)

titanic = pd.read_csv('https://raw.githubusercontent.com/dphi-official/First_ML_Model/master/titanic.csv')

titanic.head()

print('Total number of passangers in the training data...', len(titanic))
print('Number of passangers in the training data who survived...', len(titanic[titanic['Survived'] == 1]))

print('% of men who survived', 100*np.mean(titanic['Survived'][titanic['Sex'] == 'male']))
print('% of women who survived', 100*np.mean(titanic['Survived'][titanic['Sex'] == 'female']))


print('% of passengers who survived in first class', 100*np.mean(titanic['Survived'][titanic['Pclass'] == 1]))
print('% of passengers who survived in third class', 100*np.mean(titanic['Survived'][titanic['Pclass'] == 3]))


print('% of children who survived', 100*np.mean(titanic['Survived'][titanic['Age'] < 18]))
print('% of adults who survived', 100*np.mean(titanic['Survived'][titanic['Age'] > 18]))


# Data preprocessing
# Non numeric features to numeric
titanic['Sex'] = titanic['Sex'].apply(lambda x: 1 if x == 'male' else 0)

# count missing values
titanic.isnull().sum()


# fill na's with mean   
titanic['Age'] = titanic['Age'].fillna(np.mean(titanic['Age']))


# We can use fillna() function to fill the missing values as discussed in the pandas session / notebook.
titanic.Embarked.fillna(value='S', axis = 0, inplace = True) #rowwise input

# omt irrelevant columns
titanic = titanic[['Survived', 'Pclass', 'Sex', 'Age', 'SibSp', 'Parch', 'Fare']]

# input and target variables 

X = titanic.drop('Survived', axis = 1)
y = titanic['Survived']

# Train and test split

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