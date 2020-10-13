import numpy as np; np.random.seed(0)
import seaborn as sns; sns.set_theme()


uniform_data = np.random.rand(10, 12)
print(uniform_data)
ax = sns.heatmap(uniform_data)

import matplotlib.pyplot as plt
plt.show()



# Change the limits of the colormap:
# vmin=0, vmax=1

# Plot a heatmap for data centered on 0 with a diverging colormap:
# , center=0

# Annotate each cell with the numeric value using integer formatting:
#  annot=True

# add lines betw each cell
#  linewidths=.5)

# change colormap
# cmap="YlGnBu")

# center color map at a specific value
# center=flights.loc["Jan", 1955])


# dont draw a colorbar
# cbar=False
