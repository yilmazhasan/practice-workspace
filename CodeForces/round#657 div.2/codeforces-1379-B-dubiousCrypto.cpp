/**
* https://codeforces.com/contest/1379/problem/B
* @author github.com/yilmazhasan
* 7/19/2020
**/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include<bits/stdc++.h> 

using namespace std;

void findABC(long long l, long long r, long long m) {

	long long minOfBMinusC = l - r;
	long long maxOfBMinusC = r - l;
	long long n = 0;
	long long a = 0;
	long long b = 0;
	long long c = 0;
	long long na = 0;
	bool found = false;

	n = m / r;
	
	if(n <= 0) {
		n = 1;
	}

	for(; ;n++) {

		for(a = l; a <= r; a++) {
			na = n * a;

			if(m - na >= minOfBMinusC && m-na <= maxOfBMinusC) {
				found = true;
				break;
			}
		}

		if(found) {
			break;
		}
	}

	if(m-na > 0) {
		c = l;
		b = m - na + c;
	} else {
		b = l;
		c = b + na - m;
	}

	// cout << n << endl;
	cout << a << " " << b <<" " << c << endl;
}


int main(){

	int numOfTest;

	long long l, r, m;
	cin >> numOfTest;

	for(int i = 0; i < numOfTest; i++) {
		cin >> l >> r >> m;

	// cout << l  << " " << r << " " << m << endl;

		findABC(l, r, m);
	}

	return 0;
}