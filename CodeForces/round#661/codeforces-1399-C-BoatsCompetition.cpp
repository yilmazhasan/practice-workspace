/**
* https://codeforces.com/contest/1399/problem/C
* @author github.com/yilmazhasan
* 8/5/2020
**/

#include <iostream>
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

// sum of how many pairs of that vec are equal to sum
int howManyPairMakesSumOf(int sum, vector<int> nums) {
    int counter = 0;
    vector<bool> used(nums.size());

    for(int i = 0; i < nums.size(); i++) {
        if(used[i]) {
            continue;
        }
        for(int j = i+1; j < nums.size(); j++) {
            if(used[i]) {
                continue;
            }
            if(!used[i] && !used[j] && nums[i] + nums[j] == sum) {
                used[i] = used[j] = true;
                counter++;
                break;
            }
        }
    }

    return counter;
}

int boatsCompetition(vector<int> weights) {
    map<int, bool> isSumCalculated;
    int maxTeam = 0;
    for(int i = 0; i < weights.size(); i++) {
        for(int j = i+1; j < weights.size(); j++) {
            int sum = weights[i] + weights[j];
            if(isSumCalculated[sum]) {
                continue;
            }
            isSumCalculated[sum] = true;
            int teams = howManyPairMakesSumOf(sum, weights);
            // cout << i << j << " sum: " << sum <<  " " << teams << endl;

            if(teams > maxTeam) {
                maxTeam = teams;
            }
        }
    }

    return maxTeam;
}

int main(){
	int numOfTest;
	cin >> numOfTest;
	
	int n;
	int num;
	vector<int> weights;
	for(int i = 0; i < numOfTest; i++) {
		cin >> n;
		weights.clear();
		for(int j = 0; j < n; j++) {
			cin >> num;
			weights.push_back(num);
		}

        // sort(weights.begin(), weights.end());
        cout << boatsCompetition(weights) << endl;
        // print(weights);
	}

	return 0;
}

