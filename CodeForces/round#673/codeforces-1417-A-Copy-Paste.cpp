/**
* http://codeforces.com/contest/1417/problem/A
* @author github.com/yilmazhasan
**/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int getMinIndex(vector<int> vec) {
	int min = vec[0];
	int ind = 0;
	
	for(int i = 0; i < vec.size(); i++) {
		
		if(min > vec[i]) {
			min = vec[i];
			ind = i;
		}
		
	}
	
	return ind;
	
}

int getMaxNumOfTimes(vector<int> nums, int limit) {

	vector<int> remainings;
	
	int maxNum = 0;

	int min = *min_element(nums.begin(), nums.end());
	int minInd = getMinIndex(nums);

	for(int i = 0; i < nums.size(); i++) {
		if(i != minInd) {
			int diff = limit - nums[i];
			if(diff > 0) {
				maxNum += diff / min;				
			}	
		}
	}
	
	
	return maxNum;
}


int main(){

	int numOfInput;
	int numOfNums;
	int limit;
	int d;
	vector<int> nums;


	cin >> numOfInput;

	for(int i = 0; i < numOfInput; i++) {
		cin >> numOfNums >> limit;
		nums.clear();
		for(int j = 0; j < numOfNums; j++) {
			cin >> d;

			nums.push_back(d);
		}
		
		cout << getMaxNumOfTimes(nums, limit) << endl;
	}

	return 0;
}