/**
* https://codeforces.com/contest/1399/problem/A
* @author github.com/yilmazhasan
* 8/5/2020
**/

#include <iostream>
#include <vector>
#include<bits/stdc++.h> 

using namespace std;

bool removeSmallest(vector<int> nums) {
	
	sort(nums.begin(), nums.end());

	for(int i = 1; i < nums.size(); i++) {
		if(nums[i] - nums[i-1] > 1) {
			return false;
		}
	}

	return true;
}


int main(){
	int numOfTest;
	cin >> numOfTest;
	
	int n;
	int num;
	vector<int> nums;
	for(int i = 0; i < numOfTest; i++) {
		cin >> n;
		nums.clear();
		for(int j = 0; j < n; j++) {
			cin >> num;
			nums.push_back(num);
		}

		if(removeSmallest(nums)) {
			cout << "YES" << endl;
		}else {
			cout << "NO" << endl;
		}
	}

	return 0;
}

