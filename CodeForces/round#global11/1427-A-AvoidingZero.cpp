#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// wrong answer In the 170-th testcase, the sum of the first 3 values of b is 0. (test case 170)

bool isItPossible(vector<int> &nums) {

	int sum = 0;
	int i = 0;
	int j = 0;
	int size = nums.size();

	int count = 0;

	int shiftCount = 0;

	for(i = -1; i < size-1; i++) {
		if(sum + nums[i+1] == 0) {
			for(j = i+1; j < size; j++) {
				if(sum + nums[j] != 0) {
					int temp = nums[j];
					nums[j] = nums[i+1];
					nums[i+1] = temp;
					count++;
					break;
				}
			}

			// if first element sum any other element is zero then remove first element add to end  
			if(i == 0 && j == size && sum + nums[j-1] == 0) {
				if(shiftCount < size) {
					int t = nums[0];
					nums.erase(nums.begin());
					nums.push_back(t);
					i = -1;
					sum = 0;
					shiftCount++;
				} else {
					return false;
				}
			}
		}



		sum += nums[i+1];
	}

	return sum != 0;
}


int main(){

	int t;
	int n;
	int x = 0;
	vector<int> nums;

	cin >> t;

	for(int i = 0; i < t; i++) {
		cin >> n ;
		nums.clear();
		for(int j = 0; j < n; j++) {
			cin >> x;
			nums.push_back(x);
		}

		if(isItPossible(nums)) {
			cout << "YES" << endl;
			print(nums);
		} else {
			cout << "NO" << endl;
		}
	}

	return 0;
}
