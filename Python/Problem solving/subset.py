def printSet(ar):
	for e in ar:
		if e != None:
			print("{},".format(e)),
	print("");

def findSubSet(ar):
	subset = [None]*len(ar);
	subSetHelper(ar, subset, 0);
	
def subSetHelper(ar, subset, i):
	if i == len(ar):
		printSet(subset);
	else :
		subset[i] = None;
		subSetHelper(ar, subset, i+1);
		subset[i] = ar[i];
		subSetHelper(ar, subset, i+1);



def findSubSetIter(ar):

	n = len(ar)
	subsets = []

	for i in range(1, 1<<n):
		subset = [None] * n;
		for j in range(n):
			if i & 1 << j:
				subset[j] = ar[j]		

		subsets.append(subset);
		printSet(subset)




ar = [1,2,3];

#findSubSet(ar);
findSubSetIter(ar);