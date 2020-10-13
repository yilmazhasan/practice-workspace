import pandas as pd
from sklearn.model_selection import train_test_split

data = [
    {
    'Country': 'Nepal',
    'Age': 48,
    'Salary': '62000',
    'ProductPurchase': 'Yes'  
    },
    {
    'Country': 'China',
    'Age': 26,
    'Salary': '38000',
    'ProductPurchase': 'Yes'  
    },
    {
    'Country': 'India',
    'Age': 30,
    'Salary': '54000',
    'ProductPurchase': 'No'  
    },
    {
    'Country': 'China',
    'Age': 28,
    'Salary': '50000',
    'ProductPurchase': 'Yes'  
    },
    {
    'Country': 'India',
    'Age': 40,
    'Salary': None,
    'ProductPurchase': 'No'  
    },
    {
    'Country': 'Nepal',
    'Age': 31,
    'Salary': '48000',
    'ProductPurchase': 'Yes'  
    },
    {
    'Country': 'China',
    'Age': None,
    'Salary': '32000',
    'ProductPurchase': 'Yes'  
    },
    {
    'Country': 'Nepal',
    'Age': 42,
    'Salary': '89000',
    'ProductPurchase': 'Yes'  
    },
    {
    'Country': 'India',
    'Age': 53,
    'Salary': '63000',
    'ProductPurchase': 'No'  
    },
    {
    'Country': 'Nepal',
    'Age': 36,
    'Salary': '47000',
    'ProductPurchase': 'No'  
    }
]


df = pd.DataFrame(data)

X = df.drop('ProductPurchase', axis=1)
Y = df['ProductPurchase']

X_train, X_test, Y_train, Y_test = train_test_split(X, Y, test_size=0.33, random_state=42) 
# Specifying a number for random_state ensures you get the same results in each run. to remain same train and test set

print('X_train')
print(X_train)
print('X_test')
print(X_test)

