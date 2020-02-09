from sys import stdin
from collections import defaultdict
import collections 

def isAnagram(s1, s2):
    dic1 = defaultdict(int);
    dic2 = defaultdict(int);

    for c in s1:
        dic1[c] = dic1[c] + 1;
    for c in s2:
        dic2[c] = dic2[c] + 1;

    for k in dic1.keys():
        if dic1[k] != dic2[k]:
            return False;
    
    return True;
    
    
def excludeByIndexes(str, indexes):
    strAr = [c for c in str]

    for i in indexes:
        strAr[i] = None

    strAr = [c for c in str if c != None]

    return "".join(strAr)

def substrByIndexes(str, indexes):

    strAr = [str[i] for i in indexes]

    return "".join(strAr)

def divide(ss):
    s = []
    dic = defaultdict(int);

    for c in ss:
        dic[c] = dic[c]+1;

    for k in dic.keys():
        for i in range(dic[k]/2):
            s.append(k);
    s.sort()
    return "".join(s);

def reverse(s):
    l = len(s)
    r = ['']*l;
    
    for i,c in enumerate(s):
        r[l-1-i] = s[i];

    return ''.join(r);    


print(isAnagram("namaz", "zaman") == True)
print(isAnagram("aa", "aaa") == False)