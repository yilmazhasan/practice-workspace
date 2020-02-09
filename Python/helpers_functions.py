from sys import stdin
from collections import defaultdict
import collections 

def print2dArray(ar2d):
    if type(ar2d[0][0]) == type(True):
        for ar in ar2d:
            print [1 if a else 0 for a in ar ]
    else:
        for ar in ar2d:
            print [a for a in ar ]   
            
                        
            
line = raw_input("Enter numbers to find stat values:");
nums = map(int, line.split(" "))
nums.sort()

print("Mean: %.1f" % getMean(nums));
