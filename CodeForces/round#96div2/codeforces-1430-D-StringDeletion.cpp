/**
* http://codeforces.com/contest/1430/problem/B
* @author github.com/yilmazhasan
**/
// Wrong answer on test 2
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>

using namespace std;

void print(vector<int> digitsOfNum) {
	for(long long i = 0; i < digitsOfNum.size(); i++)
		cout << digitsOfNum[i] << " ";
		cout << endl;
}


string erasePrefixOfSame(string &s) {
	int i = 0;
	for(i = 1; i < s.size(); i++) {
		if(s[i] != s[i-1]) {
			break;
		}
	}

	if(i >= s.size()) {
		string s;
		return s;
	}

	return s.substr(i);
}

// 010011110001 -> starting from 4 ending at 7
vector<int> findMostFrequentIndices(string s) {
	int size = s.size();
	int maxStart = 0;
	int maxEnd = 0;
	int maxCount = 0;
	int start = 0;
	int end = -1;
	int count = 1;

	for(int i = 1; i < size; i++) {
		if(i == size-1) {
			count++;
			// cout << maxCount <<" " <<count<< " " << endl;
			// cout << i << " " << count << endl;
			if(count > maxCount) {
				maxCount = count;
				maxStart = i-count+1;
				maxEnd = i;
			}
			break;
		}

		if(s[i] != s[i-1] || i == size-1) {
			// cout << "to "<< i << " " << count << endl;
			if(count > maxCount) {
				maxCount = count;
				maxStart = i-count;
				maxEnd = i-1;
			}
			count = 0;
		}
		count++;
	}

	vector<int> v = {maxStart, maxEnd};
	// cout << "maxCount: " << maxCount << endl;
	return v;
}

int getMaxOperationToMakeEmpty(string &s) {
	int op = 0;

	while(s.size() != 0) {
		// int indToDel = getOptimalIndex(s);
		vector<int> v = findMostFrequentIndices(s);
		// cout<<"s: " << s << endl;
		// cout << v[0] << " " << v[1] << ": deleting index :  " << v[1] << endl;
		s.erase(s.begin() + v[1]);
		// s.erase(s.begin() + indToDel);

		s = erasePrefixOfSame(s);
		op++;
	}

	return op;
}

int main(){

	int t, n;

	string s = "1011";
	// auto v = findMostFrequentIndices(s);
	// print(v);

	// cout << getOptimalIndex(s) << endl;
	// s = "010";
	// cout << getOptimalIndex(s) << endl;
	// s = "0010";
	// cout << getOptimalIndex(s) << endl;
	cin >> t;

	for(int i = 0; i < t; i++) {
		cin >> n;
		cin >> s;
		cout << getMaxOperationToMakeEmpty(s) <<endl ; 
	}

	return 0;
}