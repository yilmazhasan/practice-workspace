import pandas as pd

import pandas as pd

_liver_data = pd.read_csv('https://raw.githubusercontent.com/dphi-official/Datasets/master/liver_patient_data/indian_liver_patient_dataset.csv')


_eval_data = pd.read_csv('https://raw.githubusercontent.com/dphi-official/Datasets/master/liver_patient_data/indian_liver_patient_new_testdataset.csv')

cols_to_drop = ["Gender"]
cols_to_normalize = ['Total_Bilirubin', 'Direct_Bilirubin', 'Alkaline_Phosphotase', 'Alamine_Aminotransferase',
       'Aspartate_Aminotransferase', 'Total_Protiens', 'Albumin', 'Albumin_and_Globulin_Ratio']

# make a deep copy
import copy
eval_data = copy.deepcopy(_eval_data)
liver_data = copy.deepcopy(_liver_data)

## Training Model
from sklearn.linear_model import LinearRegression

X_train = liver_data
y_train = liver_data['Liver_Problem']

# add new cols
X_train["is_male"] = (X_train.Gender == "Male").astype(int) 
X_train["Age"] = round (X_train.Age / 10)

# see zeros
liver_data.astype(bool).sum(axis=0)

# Drop since they are dropped from input
X_train = X_train.drop(["Liver_Problem"]+cols_to_drop, axis=1)

# see nans
X_train.isna().any()

# fill nas
X_train.Albumin_and_Globulin_Ratio = X_train.Albumin_and_Globulin_Ratio.fillna(X_train.Albumin_and_Globulin_Ratio.mean())


# To improve accuracy drop unrelated fields
X_train = normalise(X_train, cols_to_normalize)

linear_regressor = LinearRegression()  # create object for the class

#fit model to our training data i.e learn coefficients
linear_regressor.fit(X_train, y_train)

X_test = eval_data

X_test["is_male"] = (X_test.Gender == "Male").astype(int) 
X_test["Age"] = round (X_test.Age / 10)


# Drop since they are dropped from input
X_test = X_test.drop(cols_to_drop, axis=1)

X_test = normalise(X_test, cols_to_normalize)


## Making predictions based on your model
y_pred = linear_regressor.predict(X_test)  # make predictions

import numpy as np
y_pred_rounded = np.round(y_pred).astype(int)
prediction = pd.DataFrame(y_pred_rounded, columns=['prediction']).to_csv('C:\\Users\\hasany\\Desktop\\liver_prediction1.csv', index=False)

def normalise(df, cols):
    copy = df/1
    for col in cols:
        column_maxes = df[col].max()
        df_max = column_maxes.max()
        column_mins = df[col].min()
        df_min = column_mins.min()
        copy[col] = (df[col] - df_min) / (df_max - df_min)
    return copy

# scores1 : 
