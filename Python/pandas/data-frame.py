import pandas as pd

s1 = np.array([None, 2,3,5])
s2 = np.array([20,40,30, None])
s = np.array([s1,s2])

df = pd.DataFrame(s.transpose(), [0,1,2,3], ["day","earning"])

df.isnull() # if an earning and day is null or not
df.isnull().sum() # How many each emtpy/null is there in earnings and days column
df.isnull().sum(axis=1) # How many total emtpy/null is there in a row of earnings or days