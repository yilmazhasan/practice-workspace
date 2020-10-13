import pandas as pd

melbourne_file_path = "https://raw.githubusercontent.com/dphi-official/First_ML_Model/master/melbourne_data.csv"
melbourne_data = pd.read_csv(melbourne_file_path) 
melbourne_data.columns

y = melbourne_data.Price

melbourne_features = ['Rooms', 'Bathroom', 'Landsize', 'Lattitude', 'Longtitude']

X = melbourne_data[melbourne_features]

X.describe()



from sklearn.tree import DecisionTreeRegressor

# Define model. Specify a number for random_state to ensure same results each run
melbourne_model = DecisionTreeRegressor(random_state=1)

# Fit model
melbourne_model.fit(X, y)



print("Making predictions for the following 5 houses:")
print(X.head())
print("The predictions are")
print(melbourne_model.predict(X.head()))