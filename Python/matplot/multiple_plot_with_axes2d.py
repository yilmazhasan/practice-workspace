fig, ax = plt.subplots(nrows=2, ncols=2, figsize=(6,6)) 

fig.suptitle("Horizontally stacked subplots")

ax[0,0].plot([1,2,3], [4,6,8],"go")
ax[0,1].plot([1,2,3], [4,6,8],"bo")
ax[1,0].plot([1,2,3], [4,6,8],"yo")
ax[1,1].plot([1,2,3], [4,6,8],"ro")

plt.show()