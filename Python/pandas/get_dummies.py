import pandas as pandas

s = pd.Series(list('abca'))
pd.get_dummies(s)

s1 = ['a', 'b', np.nan]
pd.get_dummies(s1)
pd.get_dummies(s1, dummy_na=True)

df = pd.DataFrame({'A': ['a', 'b', 'a'], 'B': ['b', 'a', 'c'],
                   'C': [1, 2, 3]})
pd.get_dummies(df)
pd.get_dummies(df, prefix=['col1', 'col2'])

pd.get_dummies(pd.Series(list('abcaa')))

pd.get_dummies(pd.Series(list('abcaa')), drop_first=True)
pd.get_dummies(pd.Series(list('abc')), dtype=float)