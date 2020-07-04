/**
* https://codeforces.com/contest/1374/problem/A
* @author github.com/yilmazhasan
* 06/28/2020
**/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include<bits/stdc++.h> 

using namespace std;




int findMaxNumber(int x, int y, int n) {
	int rem = n % x;

	int max = n - rem + y;

	if(max > n) {
		max -= x;
	}

	return max;
}

int main(){

	int numOfTest;
	int x, y, n;

	cin >> numOfTest;

	for(int i = 0; i < numOfTest; i++) {
		cin >> x >> y >> n;
		int res = findMaxNumber(x, y, n);
		cout << res << endl;
	}

	return 0;
}

