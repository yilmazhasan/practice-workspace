#include<iostream>
#include <numeric>
#include <vector>

using namespace std;


bool isItPossible(vector<int> &nums, int m) {
    int sum = accumulate(nums.begin(), nums.end(), 0);

    return (sum == m);
}


int main(){

	int t;

	cin >> t;

	int n, m, x;
    vector<int> nums = {1,2,3,4};

    for(int i = 0; i < t; i++) {
        cin >> n >> m;

        nums.clear();
        for(int j = 0; j < n; j++) {
            cin >> x;
            nums.push_back(x);
        }

        if(isItPossible(nums, m)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

	return 0;
}
