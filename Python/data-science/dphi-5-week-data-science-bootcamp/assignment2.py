import numpy as np # linear algebra
import pandas as pd # data processing, CSV file I/O (e.g. pd.read_csv)

titanic_data = pd.read_csv("https://raw.githubusercontent.com/dphi-official/First_ML_Model/master/titanic.csv", index_col = 'PassengerId')

# columns: Index(['Survived', 'Pclass', 'Name', 'Sex', 'Age', 'SibSp', 'Parch', 'Ticket', 'Fare', 'Cabin', 'Embarked'],

# sex
titanic_data.Sex.value_counts()

# zeros
titanic_data.Fare[titanic_data.Fare == 0]

titanic_data.SibSp.value_counts()

# surviveds percentage
surviveds = titanic_data.Survived.value_counts()
percent = surviveds[1] / surviveds.sum() * 100


# any Fare is null
titanic_data.Fare.isnull().any()

# surviveds according to class
titanic_data[titanic_data.Survived == 1].Pclass.value_counts()

# surviveds percentage by class
titanic_data.groupby(titanic_data.Pclass).Survived.value_counts(normalize=True)

# surviveds percentage by Age
titanic_data[titanic_data.Age < 18].Survived.value_counts(normalize=True)

# surviveds percentage by Sex
titanic_data.groupby(titanic_data.Sex).Survived.value_counts(normalize=True)

# passenger surviveds
passenger_surviveds = titanic_data[titanic_data.Survived == 1]


# filter nulls
titanic_data.Age[titanic_data.Age.notna()]
