import numpy as np

numpy_array1 = np.array([1,2,3])



## Notes
# add two np_array1 + np_array2

start = 2; stop = 10; 
num = 4 # default is 50
x = np.linspace(start, stop, num)
print (x)

# append
ar = np.array([1,2])
ar = np.append(ar, 3)
ar = np.append(ar, [4,5])

#delete
ar = np.delete(ar, 1) # delete element at 1

# or a pure list can also be used 
l = [1,2,3]
np.delete(l, 1)

# reshape
a = np.arange(10)
a.reshape(2,5)
#or
np.reshape(a, 2,5))

#Access an element of 2d array
a = np.arange(10)
a.reshape(2,5)
a[0,1]
#slicing
a[0,1:2] # returns first row sliced as 1th(incl) to 2nd (excl) elements

#striding
a = np.array([0,1,2,3,4,5])
a[0,6,2] # stridr by 2 -> 0,2,4

a = np.reshape(a, (2,5))

if __name__ == "__main__":
    print("main")
