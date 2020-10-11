/**
* http://codeforces.com/contest/1430/problem/B
* @author github.com/yilmazhasan
**/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void printNum(vector<char> digitsOfNum) {
	for(long long i = 0; i < digitsOfNum.size(); i++)
		cout << digitsOfNum[i];
		cout << endl;
}

long long getMaxBarrelsDiff(vector<long long> barrels, long long k) {
	sort(barrels.begin(), barrels.end());

	long long maxAmount = 0;
	long long size = barrels.size();
	for(long long i = size-1; i >= size-k-1; i--) {
		maxAmount += barrels[i];
	}
	return maxAmount;
}


int main(){

	long long t, n, k, x;

	vector<long long> barrels;

	cin >> t;

	for(long long i = 0; i < t; i++) {
		cin >> n >> k;

		barrels.clear();
		for(long long j = 0; j < n; j++) {
			cin >> x;
			barrels.push_back(x);
		}

		cout << getMaxBarrelsDiff(barrels, k) << endl;
	}

	return 0;
}