/**
* https://codeforces.com/contest/1398/problem/C
* @author github.com/yilmazhasan
* 8/14/2020
**/

// Time limit exceeded on test 3
// find seperated ones, and take sum of factorials

// then remove from array and recalculate with current function 


#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include<bits/stdc++.h> 

using namespace std;

template <class T>
void print(vector<T> vec) {
	for(int i = 0; i < vec.size(); i++) {
		cout << vec[i] << " ";
	}
	cout << endl;
} 

int getMaxGoodSubarray(vector<int> vec) {
	int subArrayCount = 0;
	int sum = 0;

	for(int i = 0; i < vec.size(); i++) {

		sum = 0;
		for(int j = i; j < vec.size(); j++) {

			sum = sum - vec[j] + 1;

			if(sum == 0) {
				subArrayCount++;
				// cout << i << " " << j  << " " << sum << endl;
			}
		}

	}

	return subArrayCount;
}

int getMaxGoodSubarray2(string array) {
	int subArrayCount = 0;
	int subArraySum = 0;
	int el = 0;
	int requiredSum = 0;
	for(int i = 0; i < array.size(); i++) {
		// start from i
		// el = array[i] - '0';
		subArraySum = 0;

		// // first check itself
		// if(subArraySum == j - i + 1) {
		// 	subArrayCount++;
		// 	cout << i << " " << j << endl;
		// }

		requiredSum = 1;

		for(int j = i; j < array.size(); j++) {
			el = array[j] - '0';
			subArraySum += el;
			requiredSum++;
			if(subArraySum > requiredSum)
			if(subArraySum == requiredSum) {
				subArrayCount++;
				// cout << i << " " << j << endl;
			}
		}

	}

	return subArrayCount;
}

void print(vector<tuple<int>> vec) {
	cout << "---" << endl;
	for(int i = 0; i < vec.size(); i++) {
		cout << get<0>(vec[i]) << get<1>(vec[i]) << endl;
	}
}

vector<tuple<int, int>> getOnes(vector<int> vec) {
	cout << "..." << endl;
	int start = -1;
	int end = -1;

	vector<tuple<int, int>> ones;

	for(int i = 0; i < vec.size(); i++) {
		if(vec[i] == 1) {
			if(start == -1) {
				start = i;
			} else {
				end = i;
			}
		} else {
			if(start != -1 && end != -1) {
				ones.push_back(make_tuple(start, end));
				start = -1;
				end = -1;
			}
		}
	}

	return ones;
}

int main(){

	int numOfTest;
	int size;
	// string array;
	vector<int> vec;
	char t;

	cin >> numOfTest;

	for(int i = 0; i < numOfTest; i++) {
		cin >> size ;
		vec.clear();
		for(int j = 0; j < size; j++) {
			cin >> t;
			vec.push_back(t-'0');
		}
		// print(vec);
		// cin >> array ;

		auto ones = getOnes(vec);
		print(ones);

		// cout << getMaxGoodSubarray(vec) << endl; 
		// cout << getMaxGoodSubarray(array) << endl; 
		// print(numOfOnes);
	}

	return 0;
}

