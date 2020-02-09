from sys import stdin
from collections import defaultdict
import collections 


# a string in ss before last c involves match or not, if so return ind ow -1
def isBeforeCharStrMatch(ss, c, match):
    ss = [e for e in ss]
    match = [e for e in match]
    indC = len(ss)-1
    while indC >= 0:
        if ss[indC] == c :
            break;
        indC -= 1

    ssSubUntilC = ss[:indC]

    for e in match:
        try:
            ssSubUntilC.remove(e)
        except:
            return -1;   #means ssSub not contain that char c
        else:
            None
    return indC;

print(isBeforeCharStrMatch("abcdefg", "b", "bcdefg") == -1)
print(isBeforeCharStrMatch("abcdefg", "g", "fedbc") == 6) 

#in ss find smallest possible char that is after a string such that contains chars of remaining
def giveSmallestCharInd(ss, remaining): 
    i = 0
    lenRem = len(remaining)
    while i < lenRem:
        c = remaining[i]
        minCharInd = isBeforeCharStrMatch(ss, c,remaining[:i] + remaining[i+1:])
        if minCharInd != -1:
            return minCharInd;
        i += 1

    return -1;

print(giveSmallestCharInd("aaabeeb", "abe")== 6)
print(giveSmallestCharInd("aaabeeb", "abe")== 6) #since before last "a" in first str there is no "be" ,