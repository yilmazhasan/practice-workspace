/**
* https://codeforces.com/contest/1295/problem/B
* @author github.com/yilmazhasan
* Wrong answers on test input3, what inside is unknown
* sampless of IO: #numOfInputs str1Size requiredBalance1 str1 ...
* 5 -1 10101 -> 5, 4 -1 1010 -> -1 (infinity), 7 -2 1010101 -> 7, 7 2 0001111 -> 3
**/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int getNumOfPrefixes(string str, long requiredBalance);
int getNumOfPrefixesForOneRecurrence(string str, long requiredBalance);

int main(){

	int numOfInput;
	int lengthOfStr;
	long requiredBalance;
	string str;
	vector<int> lengthOfStrs;
	vector<long> requiredBalances;
	vector<string> strs;

	cin >> numOfInput;

	for(int i = 0; i < numOfInput; i++) {
		cin >> lengthOfStr >> requiredBalance >> str;
		lengthOfStrs.push_back(lengthOfStr);
		requiredBalances.push_back(requiredBalance);
		strs.push_back(str);
	}

	for(int i = 0; i < numOfInput; i++) {
		cout << getNumOfPrefixes(strs[i], requiredBalances[i]) << endl;
	}

	return 0;
}

int getNumOfPrefixes(string str, long requiredBalance) {

	int numOfOnes = 0;
	int numOfZeros = 0;
	int currentBalance = 0;

	int numOfPrefixes = 0;

	for(int i = 0; i < str.size(); i++) {
		if(str[i] == '0') {
			numOfZeros++;
		} else {
			numOfOnes++;
		}
	}

	long diffZerosMinusOnes = numOfZeros - numOfOnes;

	if(diffZerosMinusOnes == 0) {	// no need to repeat, it will be same when one more is concated or repeated, 
									// then means infinite loop in any case
			return -1;
	}

	if(requiredBalance == 0) {
		numOfPrefixes = getNumOfPrefixesForOneRecurrence(str+str, requiredBalance);	// since empty is a prefix
		// no need to look for second repeat, if diff is zero then infinite loop, if not zero then will never be equal t
		// if it can be zero in first occurence, then will not be
		return numOfPrefixes;
	}

	int numOfRecurrence = -1;

	numOfRecurrence = requiredBalance / diffZerosMinusOnes;

	numOfPrefixes = getNumOfPrefixesForOneRecurrence(str, requiredBalance);

	// if diff or required balance has not same sign, then it means no need to repeat, requiredBalance will never be sum up from diff 
	if(numOfRecurrence < 0) {
		return getNumOfPrefixesForOneRecurrence(str+str, requiredBalance);
	}

	if(numOfRecurrence > 1){
		numOfRecurrence -= 1; // let's start from one back 
	}

	currentBalance = numOfRecurrence * diffZerosMinusOnes;

	// it should be balanced in one or two recurrence
	int recurrenceMore = 2;

	while(recurrenceMore > 0) {
		for(int i = 0; i < str.size(); i++) {
			if(str[i] == '0') {
				currentBalance++;
			} else {
				currentBalance--;
			}

			if(currentBalance == requiredBalance) {
				numOfPrefixes++;
			}
		}

		recurrenceMore--;
	}

	return numOfPrefixes;
}

int getNumOfPrefixesForOneRecurrence(string str, long requiredBalance) {
	long diff = 0;
	int numOfPrefixes = 0;

	if(0 == requiredBalance) {
		numOfPrefixes++;	// since empty is zero balance
	}

	for(int i = 0; i < str.size(); i++) {
		if(str[i] == '0') {
			diff++;
		} else {
			diff--;
		}

		if(diff == requiredBalance) {
			numOfPrefixes++;
		}

	}

	return numOfPrefixes;
}