/**
* http://codeforces.com/contest/1422/problem/A
* @author github.com/yilmazhasan
**/

#include <iostream>
#include <algorithm>
#include <vector>
#include <time.h>

using namespace std;

template <class T> 
void print(vector<T> digitsOfNum) {
	for(long i = 0; i < digitsOfNum.size(); i++)
		cout << digitsOfNum[i] <<" " ;
		cout << endl;
}

long getD(long a, long b, long c) {

	long d = 0;
 
	vector<long> nums = {a, b, c};
	sort(nums.begin(), nums.end());


	vector<long> diffSums = {abs(a+b-c), abs(a+c-b), abs(b+c-a)};
	sort(diffSums.begin(), diffSums.end()); 

	long minD = diffSums[0] + 1;
	long maxD = a + b + c - 1;

	if(maxD == minD) {
		d = minD;
	} else {

		d = rand() % (maxD - minD) + minD ;
	}

//	cout << d << endl;

//	print(nums);
// print(diffSums);

	return d;
}

int main(){

	long testCases;
	long a, b, c, d;

	cin >> testCases;

	for(long i = 0; i < testCases; i++) {
		cin >> a >> b >> c;
		cout << getD(a, b, c) << endl;
	}

	return 0;
}