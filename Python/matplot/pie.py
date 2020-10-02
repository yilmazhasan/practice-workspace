import matplotlib.pyplot as plt
import numpy as np
import pandas as pd

firms = ["Firm A" , "Firm B", "Firm C", "Firm D", "Firm E"]
market_share = [20, 25, 15, 10, 20]

# explode the pie chart to emphazise a certain part of parts (Firm B in this case)
Explode = [0, 0.5, 0, 0, 0]

plt.pie(market_share, explode = Explode, labels= firms, autopct = '%1.1f%%')

plt.show()