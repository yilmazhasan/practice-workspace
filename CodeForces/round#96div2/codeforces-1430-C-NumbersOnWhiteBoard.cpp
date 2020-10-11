/**
* http://codeforces.com/contest/1430/problem/B
* @author github.com/yilmazhasan
**/

// Wrong answer on test 2

#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;

void print(vector<int> digitsOfNum) {
	for(long long i = 0; i < digitsOfNum.size(); i++)
		cout << digitsOfNum[i] << " ";
		cout << endl;
}

int getMinAfterActions(vector<int> &nums, int size) {
	// cout << "-----" << endl;
	// print(nums);
	// cout << "-----" << endl;
	if(size == 1) {
		return nums[0];
	}

	int middleInd = size/2;
	if(size%2 == 0) {
		if(middleInd > 0)
		middleInd -= 1;
	} 

	int elToAdd;

	cout << nums[size-1] << " " << nums[middleInd] << endl; 
	elToAdd = ceil(nums[size-1] + nums[middleInd]) / 2; 

	nums[middleInd] = elToAdd;
	// nums.erase(nums.begin()+elIndToDel);

	return getMinAfterActions(nums, size-1);
}


int main(){

	int t, n;

	cin >> t;

	for(long long i = 0; i < t; i++) {
		cin >> n;
		
		if(n % 2 == 0) {
			cout << n/2 << endl;
		} else {
			cout << n/2 + 1<< endl;
		}
	
		vector<int> nums;
		for(int i = 1; i <= n; i++) {
			nums.push_back(i);
		}

		getMinAfterActions(nums, nums.size()) ; 
	}

	return 0;
}