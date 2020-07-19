/**
* https://codeforces.com/contest/1385/problem/B
* @author github.com/yilmazhasan
* 7/17/2020
**/

#include <iostream>
#include <vector>
#include<bits/stdc++.h> 

using namespace std;

std::map<int, int> freqs;

template <class T>
void print(vector<T> vec) {
	for(int i = 0; i < vec.size(); i++) {
		cout << vec[i] << " ";
	}
	cout << endl;
} 

vector<int> restore(vector<int> vec) { 

	vector<int> halfVec;

	for(int i = 0; i < vec.size(); i++) {
		freqs[vec[i]]++;
	}


	for(int i = 0; i < vec.size(); i++) {
		if(freqs[vec[i]] % 2 == 0) {
			halfVec.push_back(vec[i]);
		}

		if(freqs[vec[i]] != 0) {
			freqs[vec[i]]--;
		}
	}

	return halfVec;
}

int main(){

	int numOfTest;
	int size;
	int t;

	vector<int> nums;

	cin >> numOfTest;

	for(int i = 0; i < numOfTest; i++) {
		cin >> size;
		nums.clear();
		freqs.clear();
		for(int j = 0; j < size * 2; j++) {
			cin >> t;

			nums.push_back(t);

		}

		vector<int> half = restore(nums);

		print(half);

	}

	return 0;
}

