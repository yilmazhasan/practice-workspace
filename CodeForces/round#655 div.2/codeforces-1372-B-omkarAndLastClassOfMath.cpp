/**
* https://codeforces.com/contest/1372/problem/B
* @author github.com/yilmazhasan
* 7/13/2020
**/

#include <iostream>
#include <vector>
#include<bits/stdc++.h> 

using namespace std;

int getNextPrimeNumGreaterThan(int n) {
	bool prime = false;
	for(int next = n + 1; ; next++) {		
		prime = true;
		for(int i = 2; i < next/2; i++) {
			if(next % i == 0) {
				prime = false;
				break;
			}
		}

		if(prime) {
			return next;
		}

	}

	return 1;
}

// just check for prime nums
int findMinDivisor(int n) {

	int minDivisor = 1;

	int sqrt_n = sqrt(n);

	// cout << sqrt_n << endl;

	while(minDivisor < sqrt_n) {
		minDivisor = getNextPrimeNumGreaterThan(minDivisor);
		// cout << minDivisor << endl;
		if(n % minDivisor == 0) {
			return minDivisor;
		}
	}

	return 1;
}

/*
First num: max divisor less than num
Second: subtracted from the number remaining 
*/
int main(){

	int numOfTest;
	int n;

	cin >> numOfTest;

	for(int i = 0; i < numOfTest; i++) {
				
		cin >> n;

		int minDivisor = findMinDivisor(n);
		int maxDivisor = 1;	// if min divisor 1 than max divisor less than number is again 1

		if(minDivisor > 1) {
			maxDivisor = n / minDivisor;
		}
		cout << maxDivisor << " " << n - maxDivisor << endl;

	}

	return 0;
}


// Surplus

int getNextPrimeNumLessThan(int n) {
	bool prime = false;
	for(int next = n - 1; next > 1; next--) {		
		prime = true;
		for(int i = 2; i < next/2; i++) {
			if(next % i == 0) {
				prime = false;
				break;
			}
		}

		if(prime) {
			return next;
		}
	}

	return 1;
}

