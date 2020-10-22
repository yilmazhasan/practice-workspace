# ref: https://www.kaggle.com/parulpandey/deep-dive-into-logistic-regression-for-beginners

import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns
%matplotlib inline

# File system manangement
import os

from sklearn.preprocessing import LabelEncoder
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LogisticRegression
from sklearn.metrics import accuracy_score
from sklearn.model_selection import cross_val_score
from sklearn.metrics import classification_report

# Suppress warnings 
import warnings
warnings.filterwarnings('ignore')


titanic = pd.read_csv('https://raw.githubusercontent.com/dphi-official/First_ML_Model/master/titanic.csv')
# print('Training data shape: ', train.shape)
titanic.head()
#X = titanic.drop('Survived', axis=1)
X = titanic
Y = titanic['Survived']
X_train, X_test, Y_train, Y_test = train_test_split(X, Y, test_size=0.33, random_state=42) 

sns.countplot(x = 'Survived',data = X_train)

sns.countplot(x = 'Survived',hue = 'Sex',data = X_train)
sns.countplot(x = 'Survived',hue = 'Pclass',data = X_train)
sns.boxplot(x='Pclass',y='Age',data=X_train)
plt.show()



print("Null in Training set")
print("---------------------")
print(train.isnull().sum())
print("---------------------")
print("Null in Testing set")
print("---------------------")
print(test.isnull().sum())

# Let’s create a function to impute ages regarding the corresponding age average per class.
def add_age(cols):
    Age = cols[0]
    Pclass = cols[1]
    if pd.isnull(Age):
        return int(train[train["Pclass"] == Pclass]["Age"].mean())
    else:
        return Age

X_train['Age'] = X_train[['Age','Pclass']].apply(add_age,axis=1)
X_test['Age'] = X_test[['Age','Pclass']].apply(add_age,axis=1)

##Remove some fields
# Since we have lots of null values for Cabin column, so it is better to remove it.
X_train.drop("Cabin",inplace=True,axis=1)
X_test.drop("Cabin",inplace=True,axis=1)

# Since there are just two missing values, we shall impute them with the mode of the Embarked column.
X_train['Embarked'].fillna(X_train['Embarked'].mode()[0],inplace=True)
X_test['Embarked'].fillna(X_test['Embarked'].mode()[0],inplace=True)

# Since there is one missing value, we shall impute them with the mean of the Fare column.
X_test['Fare'].fillna(X_test['Fare'].mean(),inplace=True)
##

## COMBINE
def combine(df,col1,col2):
    df["Family"] = df[col1]+df[col2]
    df.drop([col1,col2],inplace=True,axis=1)
    return df

X_train = combine(X_train,'SibSp','Parch')
X_test = combine(X_test,'SibSp','Parch')
##

## AGE CATEGORY
def process_age(df,cut_points,label_names):
    df["Age"] = df["Age"].fillna(-0.5)
    df["Age_categories"] = pd.cut(df["Age"],cut_points,labels=label_names)
    return df

# separate continuous feature into a categorical feature by dividing it into ranges.
cut_points = [-1,0,5,12,18,35,60,100]
label_names = ["Missing","Infant","Child","Teenager","Young Adult","Adult","Senior"]
X_train = process_age(X_train,cut_points,label_names)
X_test = process_age(X_test,cut_points,label_names)

pivot = X_train.pivot_table(index="Age_categories",values='Survived')
pivot.plot.bar()
##

## CREATE DUMMIES
# We can use the pandas.get_dummies() function Now, we shall have to encode Sex, Embarked, Pclass and Age_categories. 
# Name and Ticket columns have a lot of categories, hence we shall delete them.
def create_dummies(df,column_name):
    dummies = pd.get_dummies(df[column_name],prefix=column_name)
    df = pd.concat([df,dummies],axis=1)
    return df

for column in ["Pclass","Sex","Age_categories",'Embarked']:
    X_train = create_dummies(X_train,column)
    X_test = create_dummies(X_test,column)
##

## drop unnecesseary columns
X_train.drop(['Survived', 'Name','Sex','Ticket','Pclass','Age_categories','Embarked'],inplace=True,axis=1)
X_test.drop(['Survived', 'Name','Sex','Ticket','Pclass','Age_categories','Embarked'],inplace=True,axis=1)
##

lr = LogisticRegression()
columns = ['PassengerId', 'Age', 'Fare','Family',
       'Pclass_1', 'Pclass_2', 'Pclass_3', 'Sex_female', 'Sex_male',
       'Age_categories_Missing', 'Age_categories_Infant',
       'Age_categories_Child', 'Age_categories_Teenager',
       'Age_categories_Young Adult', 'Age_categories_Adult',
       'Age_categories_Senior']

#lr.fit(X_train[columns], train["Survived"])
train_X, val_X, train_y, val_y = train_test_split(X_train, Y_train, test_size=0.20,random_state=0)
lr.fit(train_X, train_y)
predictions = lr.predict(val_X)
from sklearn.metrics import accuracy_score
accuracy = accuracy_score(val_y, predictions)


# we have already did this before; X_train and Y_train
X = titanic[columns]
y = titanic['Survived']

train_X, val_X, train_y, val_y = train_test_split(X, y, test_size=0.20,random_state=0)

lr = LogisticRegression()
lr.fit(train_X, train_y)
predictions = lr.predict(val_X)
accuracy = accuracy_score(val_y, predictions)
print(accuracy)
from sklearn.metrics import classification_report
print(classification_report(val_y,predictions))



lr = LogisticRegression()
scores = cross_val_score(lr, X, y, cv=10)
scores.sort()
accuracy = scores.mean()

print(scores)
print(accuracy)


# Submission
submission = pd.read_csv('../input/titanic/gender_submission.csv')
submission_df = pd.DataFrame({'PassengerId' : test['PassengerId'],
                              'Survived':predictions_test})
submission_df.head()


from sklearn.linear_model import LogisticRegression

columns = ['PassengerId', 'Age', 'Fare','Family',
       'Pclass_1', 'Pclass_2', 'Pclass_3', 'Sex_female', 'Sex_male',
       'Age_categories_Missing', 'Age_categories_Infant',
       'Age_categories_Child', 'Age_categories_Teenager',
       'Age_categories_Young Adult', 'Age_categories_Adult',
       'Age_categories_Senior']

lr.fit(X_train[columns], X_train["Survived"])

# Creating a Validation set
X = train[columns]
y = train['Survived']

train_X, val_X, train_y, val_y = train_test_split(
    X, y, test_size=0.20,random_state=0)


lr = LogisticRegression()
lr.fit(train_X, train_y)
predictions = lr.predict(val_X)

accuracy = accuracy_score(val_y, predictions)
print(accuracy)
from sklearn.metrics import classification_report
print(classification_report(val_y,predictions))

# Making predictions and measuring accuracy
lr = LogisticRegression()
scores = cross_val_score(lr, X, y, cv=10)
scores.sort()
accuracy = scores.mean()

print(scores)
print(accuracy)

# making predictions on test data
lr = LogisticRegression()
lr.fit(X,y)
predictions_test = lr.predict(test[columns])

# submission
submission = pd.read_csv('../input/titanic/gender_submission.csv')
submission_df = pd.DataFrame({'PassengerId' : test['PassengerId'],
                              'Survived':predictions_test})
submission_df.head()