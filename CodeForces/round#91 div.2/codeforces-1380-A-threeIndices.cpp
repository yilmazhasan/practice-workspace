/**
* https://codeforces.com/contest/1380/problem/A
* @author github.com/yilmazhasan
* 7/11/2020
**/

#include <iostream>
#include <algorithm>
#include <vector>
#include<bits/stdc++.h> 

using namespace std;

void checkIfThereSuchThreeIndices(vector<int> vec) {
	bool inc = false;

	int left = 0;
	int mid = 0;
	int right = 0;

	for(int i = 1; i < vec.size(); i++) {
		if(vec[i] > vec[i-1]) {
			left = i-1;
			mid = i;
			inc = true;
		} else if(vec[i] < vec[i-1]){
			if(inc) {
				right = i;
				cout << "YES" << endl << left+1 << " " << mid+1 << " " << right+1 << endl;
				return;
			}
		}
	}

	cout << "NO" << endl;
}

int main(){

	int numOfTest;
	int numOfNums;
	vector<int> nums;
	int t;

	cin >> numOfTest;

	for(int i = 0; i < numOfTest; i++) {
		cin >> numOfNums;
		nums.clear();

		for(int j = 0; j < numOfNums; j++) {
			cin >> t;
			nums.push_back(t);
		}

		checkIfThereSuchThreeIndices(nums);
	}

	return 0;
}

