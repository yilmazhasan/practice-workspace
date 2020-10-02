#fig, (ax1, ax2) = plt.subplots(1,2) # row, col
fig, (ax1, ax2) = plt.subplots(1,2, sharey = True) # sharey makes axis overlapped

fig.suptitle("Horizontally stacked subplots")

ax1.plot([1,2,3], [4,6,8],"go")
ax1.set_title("Chart 1")

## Another
ax2.plot([1,2,3], [2,4,6], "r^")
ax2.set_title("Chart 2")

plt.show()