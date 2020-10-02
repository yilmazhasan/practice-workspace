# rowCount, colCount of the total chart
row = 1; col = 3; 

index = 2 # index 1 means this subplot will be displayed first
plt.subplot(row, col, index)

plt.plot([1,2,3], [2,4,6], "go")
plt.title("Chart 1")

## Another
index = 3 # index 2 means this subplot will be displayed at the 2nd pos
plt.subplot(row, col, index)

plt.plot([1,2,3], [2,4,6], "r^")
plt.title("Chart 2")

## Another
index = 1 # index 3 means this subplot will be displayed at the 3rd pos
plt.subplot(row, col, index)

plt.plot([1,2,3], [2,4,6], "r^")
plt.title("Chart 3")

plt.suptitle("Sub Plots") # add a centered title to the figure

plt.show()
