from sys import stdin
from collections import defaultdict
import collections 
import sys 

def getMean(nums):
	N = len(nums);

	return sum(nums) / float(N)

#median
def getMedian(nums):
    N = len(nums)    
    nums.sort();

    if N%2 == 0: 
        return (nums[N/2] + nums[N/2-1]) / 2.0
    else:
        return  nums[N/2]

#mode, return smallest if same freq
def getMode(nums):
    dic = defaultdict(int)

    for n in nums:
        dic[n] = dic[n] + 1

    dic  = collections.OrderedDict(sorted(dic.items())) #sort dict

    minCount = 0
    mode = 0

    for k,v in dic.iteritems():
        if v > minCount :
            mode = k;
            minCount = v;
    return mode;

#weightedMean [2,4] [1,2] -> (2*1 + 4*2) / 1+2
def getWeightedMean(nums, weights):

    weightedSum = 0;

    for i,n in enumerate(nums):
        weightedSum += weights[i] * nums[i]

    weightedMean = weightedSum / float(sum(weights))

    return weightedMean;

#lowers and uppers than median, not include median
def getLowerAndUpperHalf(nums):
    nums.sort()
    lowerHalf = []
    upperHalf = []

    N = len(nums);

    if N % 2 == 0:
        lowerHalf = nums[:N/2]
        upperHalf = nums[N/2:]
    else:
        lowerHalf = nums[:N/2]
        upperHalf = nums[(N/2)+1:]

    return [lowerHalf, upperHalf]

def getQ1(nums):
    lowerAndUpperHalf = getLowerAndUpperHalf(nums)
    Q1 = getMedian(lowerAndUpperHalf[0])
    return Q1;

def getQ2(nums):
    Q2 = getMedian(nums)
    return Q2;

def getQ3(nums):
    lowerAndUpperHalf = getLowerAndUpperHalf(nums)
    Q3 = getMedian(lowerAndUpperHalf[1])
    return Q3;

def getVariance(nums):
    mean = getMean(nums)

    sqrSum = 0;  """ standard deviation sum """

    for num in nums:
        sqrSum += (num-mean) ** 2
    
    variance = float(sqrSum)/len(nums)
    
    return variance

def getStdDev(nums):
    return getVariance(nums) ** 0.5

#Q3 - Q1
def getInterQuartileRange(nums):
    lowerAndUpperHalf = getLowerAndUpperHalf(nums)

    Q1 = getMedian(lowerAndUpperHalf[0])
    Q3 = getMedian(lowerAndUpperHalf[1])

    return (Q3 - Q1)

#result is nums times freqs
def getNumsOfFrequency(nums, freqs):
    S = [];

    for i,n in enumerate(nums):
        S += [n]*freqs[i]
    return S;

def factorial(n):
    if n < 2:
        return 1
    else:
        return n * factorial(n-1) 

def comb(m,n):
    return factorial(m) / (factorial(m-n) * factorial(n))

def binomialDist(x,n,p):
    q = 1-p
    return  comb(n,x) * pow(p,x) * pow(q, n-x)

def geoDist(n,p):
    q  =1-p
    return (q**(n-1)) * p

def poissonDist(k, lambd):
    return lambd**k * math.e**(-lambd) / factorial(k)


def myNormDist(mean, var, x): #what is wrong
    nD=(1.0/ ((2 * math.pi * var) ** 0.5)) * (math.e ** ((-1 * ((x-mean)**2))/(2*var)))

    return nD;

def myErf(z):   #what is wrong
    res = (2.0 / (math.pi**0.5)) * (math.e**(-1*(z**2)) - 1) * (-1 * math.pi)
    return res

def normDist(mean, stdDev, x):
    return 0.5 *(1 + math.erf(float(x - mean) / (stdDev * (2**0.5))))

def centralLimit(mean, stdDev, n, x):
    meanC = mean;
    stdDevC = n**0.5 * stdDev

    return normDist(meanC, stdDevC, x);

def covariance(set1, set2):
    if(len(set1) != len(set2)):
        return None;

    sums = 0
    l = len(set1)

    for i in range(l):
        for j in range(i+1, l):
            sums += (set1[i] - set1[j]) * (set2[i] - set2[j])
    
    covar = sums / float(l**2);
    
    return covar;

def covariance2(set1, set2):
    if(len(set1) != len(set2)):
        return None;

    mean1 = getMean(set1)
    mean2 = getMean(set2)

    sumOf = 0

    for i in range(len(set1)):
        sumOf += (set1[i] - mean1) * (set2[i] - mean2)        

    covar = float(sumOf) / len(set1)
     
    return covar
    
def pearsonCorrCoef(set1, set2):

    if(len(set1) != len(set2)):
        return None;

    stdDev1 = getStdDev(set1)
    stdDev2 = getStdDev(set2)


    covar = covariance(set1, set2)

    coeff = covar / (stdDev1 * stdDev2)

    return coeff

def getRanks(set1):
    setWithInd = [(e,i) for i,e in enumerate(set1)]
    sortedSet = sorted(setWithInd)

    ranks = [0]*len(set1)

    for i in range(len(sortedSet)):
        ranks[sortedSet[i][1]] = i+1

    return ranks

#changes between 1 and -1, means how rankings are close to each other
def spearmansRankCorrCoef(set1, set2):

    if(len(set1) != len(set2)):
        return None;

    l = len(set1)

    if(len(set1) != len(set2)):
        return None;

    set1Ranks = getRanks(set1)
    set2Ranks = getRanks(set2)

    sumOfDiff = 0
    for i in range(l):
        rankDif = set1Ranks[i] - set2Ranks[i]
        sumOfDiff += rankDif **2

    coeff = 1 - ((6* float(sumOfDiff)) / (l*(l**2-1))) 

    return coeff


from sklearn import linear_model #pip install -U scikit-learn scipy matplotlib
import numpy as np

def leastLinearRegressionCeoffs_sklearn(xSet, ySet):
    
    x = np.asarray(xSet).reshape(-1, 1)
    lm = linear_model.LinearRegression()
    lm.fit(x, ySet)

    return(lm.intercept_, lm.coef_[0])


def leastLinearRegressionCeoffs(xSet, ySet):
    
    stdDevX = getStdDev(xSet)
    stdDevY = getStdDev(ySet)
    meanX = getMean (xSet)
    meanY = getMean (ySet)

    pearsCoeff = pearsonCorrCoef(xSet, ySet)

    b = pearsCoeff * stdDevY / stdDevX

    a = meanY - b * meanX

    return(a, b)

from sklearn import linear_model
def multipleLinearRegressionCoefs_sklearn(x, y, queries):
    lm = linear_model.LinearRegression()
    lm.fit(x, y)
    a = lm.intercept_
    b = lm.coef_
    
    return a, b

def multipleLinearRegression(xArray, yArray, queryArray):

    for i in range(len(xArray)):
        xArray[i] = [1] + xArray[i]

    xMatrix = np.matrix(xArray)
    yMatrix = np.matrix(yArray)

    xTranspose = np.matrix.transpose(xMatrix)
    xTransposeDotXInv =  np.linalg.inv( xTranspose.dot(xMatrix))

    bMatrix = xTransposeDotXInv.dot(xTranspose.dot(yMatrix))
        
    yResult = []
    for qRow in queryArray:
        yRes = (np.matrix([1] + qRow)).dot(bMatrix) #returns 1x1 matrix
        yResult.append(yRes.item(0))
    
    return yResult

#line = raw_input();
#N = int(line.split(" ")[0])

line = raw_input("Enter numbers to find stat values:");
nums = map(int, line.split(" "))
nums.sort()


if __name__ == '__main__':
    print("Mean: %.1f" % getMean(nums));
    print("Median: %.1f" % getMedian(nums));
    print("Mode: %.1f" % getMode(nums));
    print("Standard deviation: %.1f" % getStdDev(nums))

    # to execute a function getting from command line
    #print (globals()[sys.argv[1]]( [int(x) for x in sys.argv[2][1:-1].split(',')]))