from sys import stdin
from collections import defaultdict
import collections 

def getIncrementedBitsArray(bitsAr):

    i = len(bitsAr) - 1;
    surplus = 1 if bitsAr[-1] == 1 else 0; #added one to bin number
    bitsAr[-1] = (bitsAr[-1] + 1) % 2;
    i-=1;
    
    while i >= 0:        
        if surplus + bitsAr[i] > 1:
            surplus = 1 
            bitsAr[i] = (bitsAr[i] + surplus) % 2;
            i-=1
        else :
            bitsAr[i] = bitsAr[i] + surplus;
            break;

    return bitsAr;

def getNextBitPerm(bitsAr):

    l = len(bitsAr)
    if bitsAr[:l/2] == [1]*(l/2):
        return [];

    bitsAr = getIncrementedBitsArray(bitsAr)

    while onesAndZerosEqualTo(bitsAr, l/2, l/2) == False:
        bitsAr = getIncrementedBitsArray(bitsAr)
    
    return bitsAr
    
def onesAndZerosEqualTo(bitsAr, zeroCount, oCount):
    o=0
    z=0
    for b in bitsAr:
        if b == 1:
            o += 1
        else :
            z += 1

    return o == zeroCount && oCount == z
