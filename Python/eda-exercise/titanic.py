import pandas as pd

td = pd.read_csv('https://raw.githubusercontent.com/dphi-official/First_ML_Model/master/titanic.csv');


td.head()
td.info()
td.Sex.value_counts()
td.Survived.value_counts()
td.Fare.median()


# number of people survived via sex
td.Survived[td.Sex == 'female'].value_counts()


is_survived = td.Survived == 1
class_of_surviveds = td[is_survived].Pclass

# compare surviving counts with age
age_ranges = [0,10,20,30,40,50,60,70,80,90,100]
td.groupby(pd.cut(td.Age, age_ranges)).count()

age_of_surviveds = td[is_survived]
age_of_surviveds.Age.groupby(pd.cut(age_of_surviveds.Age, age_ranges)).count()


# Create a subset of the data, only taking observations for which the passsenger survived. Call this newly created dataset as survived_passengers. 
# How many of the survived passengers had embarked from 'Southampton' i.e. 'S'?

embarked_surviveds = surviveds['Embarked']
embarked_surviveds.value_counts()


# top 5 (not unique)
td.Fare.nlargest(5)
