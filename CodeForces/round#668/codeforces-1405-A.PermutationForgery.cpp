/**
* https://codeforces.com/contest/1405/problem/A
* @author github.com/yilmazhasan
* 05.09.2020
**/


/*
Reverse the given vector, since elements order remain same, fingerprint will also be same
*/

#include <iostream>
#include <algorithm>
#include <string>
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

vector<int> getFingerPrint(vector<int> vec) {

	vector<int> vecFp;

	for(int i = 1; i < vec.size(); i++) {
		vecFp.push_back(vec[i-1] + vec[i]);
	}

	sort(vecFp.begin(), vecFp.end());

	return vecFp;
}

vector<int> findAVecWithSameFingerPrint(vector<int> vec) {

	reverse(vec.begin(), vec.end());
	
	return vec;
}

int main(){

	int numOfTest;
	int size = 0;
	int t = 0;
	vector<int> vec;

    cin >> numOfTest;

	for(int i = 0; i < numOfTest; i++) {
		cin >> size;
		vec.clear();
		for(int j = 0; j < size; j++) {
			cin >> t;
			vec.push_back(t);

		}

		// print(getFingerPrint(vec));

		vector<int> alt = findAVecWithSameFingerPrint(vec);
		print(alt);
		// print(getFingerPrint(alt));
	}

	return 0;
}

