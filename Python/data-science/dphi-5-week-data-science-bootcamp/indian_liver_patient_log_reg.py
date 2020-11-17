import pandas as pd

_liver_data = pd.read_csv('https://raw.githubusercontent.com/dphi-official/Datasets/master/liver_patient_data/indian_liver_patient_dataset.csv')
_eval_data = pd.read_csv('https://raw.githubusercontent.com/dphi-official/Datasets/master/liver_patient_data/indian_liver_patient_new_testdataset.csv')

cols_to_drop = ["Gender"]
cols_to_normalise = ['Total_Bilirubin', 'Direct_Bilirubin', 'Alkaline_Phosphotase', 'Alamine_Aminotransferase',
       'Aspartate_Aminotransferase', 'Total_Protiens', 'Albumin', 'Albumin_and_Globulin_Ratio']

# make a deep copy
import copy
eval_data = copy.deepcopy(_eval_data)
liver_data = copy.deepcopy(_liver_data)

## Training Model
from sklearn.linear_model import LogisticRegression

X_train = liver_data
y_train = liver_data['Liver_Problem']

# add new cols and categorize
X_train["is_male"] = (X_train.Gender == "Male").astype(int) 
y_train = (y_train == 1).astype(int) # 1 is liver

# Drop since they are dropped from input
X_train = X_train.drop(["Liver_Problem"]+cols_to_drop, axis=1)

# see nans
#X_train.isna().any()

# see zeros
#liver_data.astype(bool).sum(axis=0)

# fill nas
X_train.Albumin_and_Globulin_Ratio = X_train.Albumin_and_Globulin_Ratio.fillna(X_train.Albumin_and_Globulin_Ratio.mean())

# To improve accuracy drop unrelated fields
X_train = normalise(X_train, cols_to_normalise)

logistic_regressor = LogisticRegression()  # create object for the class

#fit model to our training data i.e learn coefficients
logistic_regressor.fit(X_train, y_train)

X_test = eval_data

X_test["is_male"] = (X_test.Gender == "Male").astype(int) 


# Drop since they are dropped from input
X_test = X_test.drop(cols_to_drop, axis=1)

## Making predictions based on your model
y_pred = logistic_regressor.predict(X_test)  # make predictions
# undo change
y_pred[y_pred == 0] = 2

prediction = pd.DataFrame(y_pred, columns=['prediction']).to_csv('C:\\Users\\hasany\\Desktop\\liver_prediction_logistic3.csv', index=False)