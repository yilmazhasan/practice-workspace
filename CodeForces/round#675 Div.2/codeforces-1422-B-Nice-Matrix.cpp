/**
* http://codeforces.com/contest/1422/problem/A
* @author github.com/yilmazhasan
**/

// time limit exceeds on test 2

#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <numeric>
#include <climits>

using namespace std;

long long getMinActionToMakeVecPalindrome(vector<long long> &vec) {
	long long actions = 0;
	long long size2 = vec.size()/2;
	long long lastInd = vec.size()-1;
	for(long long i = 0; i < size2; i++) {
		long long mean = ((vec[i] + vec[lastInd-i]) / 2);
		actions += abs(mean - vec[i]) + abs(vec[lastInd-i] - mean );
	}

	return actions;
}

long long getMinActionToMakeAllEqual(long long &a, long long &b, long long &c, long long &d) {

	vector<long long> vec = {a,b,c,d};
	sort(vec.begin(), vec.end());

	long long res = vec[2] + vec[3] -vec[0]-vec[1];

	return res;

	double sum = (a + b + c + d ) / 4.0;
	long long mean = floor(sum);
	// cout << a << " " << b << " " << c << " " << d << endl; 
	long long actionsNeeded1 = abs(mean - a) +  abs(mean - b) +  abs(mean - c) +  abs(mean - d);
	mean = ceil(sum);
	long long actionsNeeded2 = abs(mean - a) +  abs(mean - b) +  abs(mean - c) +  abs(mean - d);
// cout << mean << " " << actionsNeeded << endl;

//	cout << a << " "<< b << " " << c << " " << d << " : "<< actionsNeeded << endl; 
	if(actionsNeeded1 < actionsNeeded2)
	return actionsNeeded1; 
	else 
	return actionsNeeded2; 

}

long long getActionsToMakeIntersectedRowAndColPalindrome(vector<long long> &row, vector<long long> &col) {

	long long midElCol = round(accumulate(col.begin(),col.end(),0) / col.size());
	long long midElRow = round(accumulate(row.begin(),row.end(),0) / row.size());

	long long sm = 0;
	long long bg = 0;

	if(midElCol < midElRow) {
		sm = midElCol;
		bg = midElRow;
	} else {
		sm = midElRow;
		bg = midElCol;
	}

	long long min = INT_MIN;
	int rowSize = row.size();
	// cout << sm << " " << bg << endl;
	for(long long i = sm; i <= bg; i++) {

		long long sum = 0;
		for(long long j = 0; j < rowSize; j++) {
			if(i != rowSize/2) {
				sum += abs(i-row[j]) + abs(i-col[j]);
			} else {
				sum += abs(i-row[j]);
			}
		}

		if(min > sum) {
			// cout << "i: " << i << endl;
			min = sum;
		}
			// cout << "i: " << i << " " << sum << endl;

	}

	return min;
}

long long getMinActionToMakeMatrixNice(vector<vector<long long>> &mx) {

	long long n2 = mx.size() / 2;
	long long m2 = mx[0].size() / 2;

	long long lastN = mx.size()-1;
	long long lastM = mx[0].size()-1;

	long long sum = 0;
	// long long x = 0;
	for(int i = 0; i < n2; i++) {
		for(int j = 0; j < m2; j++) {
//			cout << i << "," << j << " : " <<i << "," << lastM-j << " : " <<lastN-i << "," << lastM-j << " : " <<lastN-i << "," << j << " : "  << endl;
			sum +=  getMinActionToMakeAllEqual(mx[i][j], mx[i][lastM-j], mx[lastN-i][lastM-j], mx[lastN-i][j]);
			// cout << i << " " << j << " ::: " << x << endl;
			// sum += x;
		}
	}

	// if it is odd then middle row should be checked
	bool rowOdd = false;
	bool colOdd = false;
	vector<long long> midColVec;

	if (n2 * 2 != mx.size()) {
		rowOdd = true;
	}

	if (m2 * 2 != mx[0].size()) {
		colOdd = true;
		for(long long i = 0; i <= lastN; i++) {
			midColVec.push_back(mx[i][m2]);
		}
	}

	if(rowOdd && colOdd) {
		sum += getActionsToMakeIntersectedRowAndColPalindrome(mx[n2], midColVec);
	} else {
		if(rowOdd) {
			sum += getMinActionToMakeVecPalindrome(mx[n2]);
		} else {
			sum += getMinActionToMakeVecPalindrome(midColVec);
		}
	}

	return sum;
}

int main(){

	long long testCases;
	long long n,m;
	long long x;

	// cout << getActionsToMakeRowAndColPalindrome({1,3,5}, {2,3,4}) << endl;
	// cout << getActionsToMakeRowAndColPalindrome({1,0,9}, {2,0,4}) << endl;

	// cout << getMinToMakeAllEqual(1,2,3,4) << endl;

	// cout << getMinToMakeAllEqual(2,3,5,7) << endl;
	// cout << getMinToMakeAllEqual(2,3,4,5) << endl;
	vector<vector<long long>> nums;

	cin >> testCases;

	for(long long i = 0; i < testCases; i++) {
		cin >> n >> m;
		nums.clear();
		for(long long j = 0; j < n; j++) {
			vector<long long> row;
			for(long long k = 0; k < m; k++) {
				cin >> x;
				row.push_back(x);
			}
			nums.push_back(row);
		}

		cout << getMinActionToMakeMatrixNice(nums) << endl;
	}

	return 0;
}