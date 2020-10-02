import numpy as np 
from timeit import Timer
import __builtin__

list_x = list(range(10000))
list_y = list(range(10000))

arr_x = np.array(list_x)
arr_y = np.array(list_y)

def list_sum():
    z = []
    for i in range(len(list_x)):
        z.append(list_x[i] + list_y[i])

def numpy_arr_sum():
    z = arr_x + arr_y


if __name__ == "__main__":

    # builtin code, numpy executes very slowly compared to normal execution
    # __builtin__.numpy_arr_sum = numpy_arr_sum
    # __builtin__.list_sum = list_sum

    # timer_obj1 = Timer("list_sum()", "from __builtin__ import list_sum")
    # timer_obj2 = Timer("list_sum()", "from __builtin__ import numpy_arr_sum")

    timer_obj1 = Timer("list_sum()", "from __main__ import list_sum")
    timer_obj2 = Timer("numpy_arr_sum()", "from __main__ import numpy_arr_sum")

    print ("Pure python version:" , timer_obj1.timeit(1000))
    print ("Numpy version:" , timer_obj2.timeit(1000))

