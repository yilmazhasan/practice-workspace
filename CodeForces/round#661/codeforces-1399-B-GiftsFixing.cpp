/**
* https://codeforces.com/contest/1399/problem/B
* @author github.com/yilmazhasan
* 8/5/2020
**/

#include <iostream>
#include <vector>
#include<bits/stdc++.h> 

using namespace std;

bool removeSmallest(vector<long> nums) {
	
	sort(nums.begin(), nums.end());

	for(long i = 1; i < nums.size(); i++) {
		if(nums[i] - nums[i-1] > 1) {
			return false;
		}
	}

	return true;
}

long long findMinMove(vector<long long> candies, vector<long long> oranges) {
    auto minCandy = min_element(candies.begin(), candies.end());
    auto minOrange = min_element(oranges.begin(), oranges.end());

    long minCandInd = std::distance(candies.begin(), minCandy);
    long minOrangeInd = std::distance(oranges.begin(), minOrange);
    long long move = 0;
    long long candyMove = 0;
    long long orangeMove = 0;
    long long bigger = 0;
    for(long i = 0; i < candies.size(); i++) {
        candyMove = candies[i] - candies[minCandInd];
        orangeMove = oranges[i] - oranges[minOrangeInd];
        if(candyMove > orangeMove) {
            bigger = candyMove;
        } else {
            bigger = orangeMove;
        }
        move += bigger; // until bigger move, small will already be moved 
    }

    return move;
}

int main(){
	long numOfTest;
	cin >> numOfTest;
	
	long n;
	long long num;
	vector<long long> candies;
	vector<long long> oranges;
	for(long i = 0; i < numOfTest; i++) {
		cin >> n;
		candies.clear();
		for(long j = 0; j < n; j++) {
			cin >> num;
			candies.push_back(num);
		}

		oranges.clear();
		for(long j = 0; j < n; j++) {
			cin >> num;
			oranges.push_back(num);
		}

        cout << findMinMove(candies, oranges) << endl;
	}

	return 0;
}

