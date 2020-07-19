/**
* https://codeforces.com/contest/1385/problem/A
* @author github.com/yilmazhasan
* 7/17/2020
**/

#include <iostream>
#include <vector>
#include<bits/stdc++.h> 

using namespace std;

bool isAllSame(int a, int b, int c) { 
	return a == b && b == c;
}

bool isAllDifferent(int a, int b, int c) { 
	return a != b && b != c && a != c;
}

bool isAnyTwoEqAndOtherBig(int a, int b, int c, int &sameOne, int &bigger) {
	if(a == b) {
		sameOne = a;
		bigger = c;
	} else if (a == c) {
		sameOne = a;
		bigger = b;
	} else if(b == c) {
		sameOne = c;
		bigger = a;
	}

	if(sameOne == a) {
		return sameOne < b || sameOne < c;
	} else if(sameOne == b) {
		return sameOne < a || sameOne < c;
	} else if(sameOne == c) {
		return sameOne < a || sameOne < b;
	}

	return false;
}

bool isAnyTwoEqAndOtherSmall(int a, int b, int c, int &sameOne, int &smaller) {
	if(a == b) {
		sameOne = a;
		smaller = c;
	} else if (a == c) {
		sameOne = a;
		smaller = b;
	} else if(b == c) {
		sameOne = c;
		smaller = a;
	}

	if(sameOne == a) {
		return sameOne > b || sameOne > c;
	} else if(sameOne == b) {
		return sameOne > a || sameOne > c;
	} else if(sameOne == c) {
		return sameOne > a || sameOne > b;
	}

	return false;

}


void checkThreePairs(int a, int b, int c) {
	int same = 0;
	int bigger = 0;
	int smaller = 0;
	if(isAllDifferent(a, b, c)) {
		cout << "NO" << endl;
	} else if(isAllSame(a, b, c)) {
		cout << "YES" << endl;
		cout << a << " " << b  << " " << c << endl;
	} else if(isAnyTwoEqAndOtherBig(a, b, c, same, bigger)) {
		cout << "NO" << endl;
	} else if(isAnyTwoEqAndOtherSmall(a, b, c, same, smaller)) {
		cout << "YES" << endl;
		cout << same << " " << smaller << " " << smaller << endl;

	}

}

int main(){

	int numOfTest;
	int x, y, z;

	cin >> numOfTest;

	for(int i = 0; i < numOfTest; i++) {
		cin >> x >> y >> z;

		checkThreePairs(x, y, z);
	}

	return 0;
}

