import pandas as pd
_house_data = pd.read_csv('https://raw.githubusercontent.com/dphi-official/Datasets/master/kc_house_data/kc_house_data.csv')

_eval_data = pd.read_csv('https://raw.githubusercontent.com/dphi-official/Datasets/master/kc_house_data/kc_house_new_test_data.csv')

cols_to_drop = ["zipcode", "lat", "long", "yr_built", "yr_renovated", "sqft_living15", "sqft_lot15"]
cols_to_normalize = [] #["sqft_living", "sqft_lot", "sqft_above", "sqft_basement"]

# make a deep copy
import copy
eval_data = copy.deepcopy(_eval_data)
house_data = copy.deepcopy(_house_data)

## Training Model
from sklearn.linear_model import LinearRegression

X_train = house_data
y_train = house_data['price']

# clean zeros on train data #
X_train.yr_renovated[X_train.yr_renovated == 0] = round(X_train.yr_renovated[X_train.yr_renovated != 0].mean())
X_train.sqft_basement[X_train.sqft_basement == 0] = round(X_train.sqft_basement[X_train.sqft_basement != 0].mean())

# To improve accuracy drop unrelated fields
X_train["age_renovated"] = (2020 - X_train.yr_renovated)
X_train["age_built"] = (2020 - X_train.yr_built)
X_train = X_train.drop(cols_to_drop + ["price"], axis=1)

X_train = normalise(X_train, cols_to_normalize)

linear_regressor = LinearRegression()  # create object for the class

#fit model to our training data i.e learn coefficients
linear_regressor.fit(X_train, y_train)

X_test = eval_data

# clean zeros on test data #
X_test.yr_renovated[X_test.yr_renovated == 0] = round(X_test.yr_renovated[X_test.yr_renovated != 0].mean())
X_test.sqft_basement[X_test.sqft_basement == 0] = round(X_test.sqft_basement[X_test.sqft_basement != 0].mean())

X_test["age_renovated"] = (2020 - X_test.yr_renovated)
X_test["age_built"] = (2020 - X_test.yr_built)

# Drop since they are dropped from input
X_test = X_test.drop(cols_to_drop, axis=1)

X_test = normalise(X_test, cols_to_normalize)

## Making predictions based on your model
y_pred = linear_regressor.predict(X_test)  # make predictions

prediction = pd.DataFrame(y_pred, columns=['prediction']).to_csv('C:\\Users\\hasany\\Desktop\\prediction7.csv', index=False)

# data cleaning
X_train.head().isnull().any()

def normalise_all(df):
    column_maxes = df.max()
    column_mins = df.min()
    df_max = column_maxes.max()
    df_min = column_mins.min()
    normalized_df = (df - df_min) / (df_max - df_min)
    return normalized_df

def normalise(df, cols):
    copy = df/1
    for col in cols:
        column_maxes = df[col].max()
        df_max = column_maxes.max()
        column_mins = df[col].min()
        df_min = column_mins.min()
        copy[col] = (df[col] - df_min) / (df_max - df_min)
    return copy