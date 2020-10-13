import numpy as np # linear algebra
import pandas as pd # data processing, CSV file I/O (e.g. pd.read_csv)


df = pd.DataFrame([
    {'chronic': 0, 'car': 1, 'age': 70, 'recovered': 0}, 
    {'chronic': 0, 'car': 0, 'age': 65, 'recovered': 1}, 
    {'chronic': 0, 'car': 1, 'age': 65, 'recovered': 1}, 
    {'chronic': 0, 'car': 0, 'age': 75, 'recovered': 1}, 
    {'chronic': 1, 'car': 1, 'age': 65, 'recovered': 0}, 
    {'chronic': 0, 'car': 1, 'age': 25, 'recovered': 1}, 
    {'chronic': 1, 'car': 0, 'age': 25, 'recovered': 0}, 
    {'chronic': 1, 'car': 0, 'age': 5, 'recovered': 0}, 
    {'chronic': 1, 'car': 0, 'age': 55, 'recovered': 0}, 
    {'chronic': 1, 'car': 1, 'age': 65, 'recovered': 0},
    {'chronic': 1, 'car': 0, 'age': 55, 'recovered': 0}, 
    {'chronic': 0, 'car': 1, 'age': 65, 'recovered': 1},
    {'chronic': 1, 'car': 0, 'age': 55, 'recovered': 0}, 
    {'chronic': 0, 'car': 1, 'age': 65, 'recovered': 0}
    ])


X = df.drop('recovered', axis = 1)
y = df['recovered']


from sklearn.model_selection import train_test_split
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.33, random_state=42)


# Building model

from sklearn.tree import DecisionTreeClassifier
model = DecisionTreeClassifier()
model.fit(X_train, y_train)


from sklearn.metrics import accuracy_score
print('Training accuracy...', accuracy_score(y_train, model.predict(X_train)))
print('Test accuracy', accuracy_score(y_test, model.predict(X_test)))


from sklearn.tree import export_graphviz
import graphviz

dot_data= export_graphviz(model, out_file=None, 
                    feature_names=X_test.columns,  
                      class_names=['0', '1'],  
                      filled=True, rounded=True,  
                      special_characters=True)

graph1=graphviz.Source(dot_data)
graph1
a = graphviz.dot.Digraph
a.render()
