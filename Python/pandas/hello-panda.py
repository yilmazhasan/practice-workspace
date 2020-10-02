import pandas as pd

test = {
383:    3.000000,
663:    1.000000,
726:    1.000000,
737:    9.000000,
833:    8.166667
}

s = pd.Series(test)
s = s[s != 1]
s



###

#.where(lambda x : x!=1)