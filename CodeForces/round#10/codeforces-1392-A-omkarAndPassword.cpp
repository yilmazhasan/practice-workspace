/**
* https://codeforces.com/contest/1392/problem/A
* @author github.com/yilmazhasan
* 8/17/2020
**/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include<bits/stdc++.h> 

using namespace std;

bool isAllSame(vector<int> vec) {
	for(int i = 1; i < vec.size(); i++) {
		if(vec[i-1] != vec[i]) {
			return false;
		}
	}

	return true;
}

int main(){

	int numOfTest;
	int n;
	int t;
	vector<int> p;


	cin >> numOfTest;

	for(int i = 0; i < numOfTest; i++) {
		cin >> n;
		p.clear();
		for(int j = 0; j < n; j++) {
			cin >> t;
			p.push_back(t);
		}

		if(isAllSame(p)) {
			cout << n << endl;
		} else {
			cout << 1 << endl;
		}

	}

	return 0;
}

