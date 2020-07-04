/**
* https://codeforces.com/contest/1374/problem/B
* @author github.com/yilmazhasan
* 06/28/2020
**/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include<bits/stdc++.h> 

using namespace std;

int numOf2s = 0;
int numOf3s = 0;
int numOfDividerExceptFor2And3 = 0;

void find2sAnd3s(int n) {
	if(n % 2 == 0) {
		numOf2s++;
		find2sAnd3s(n/2);		
	} else if(n % 3 == 0) {
		numOf3s++;
		find2sAnd3s(n/3);		
	} else	if(n == 1){
		return;
	} else if(n != 1) {
		numOfDividerExceptFor2And3++;
	}
}

int findMinMove(int n) {

	if(numOfDividerExceptFor2And3 > 0) {
		return -1;
	}

	if(n == 1) {
		return 0;
	}

	if(numOf3s < numOf2s) {
		return -1;
	}

	int threesWithout2s = numOf3s - numOf2s;
	int twosWith3s = numOf2s;

	int minMove = 2 * threesWithout2s + twosWith3s; // 2 times 3s without 2s: 1 for multiplying by two and 1 for dividing by 6

	return minMove;
}

int main(){

	int numOfTest;
	int n;

	cin >> numOfTest;

	for(int i = 0; i < numOfTest; i++) {
		cin >> n;
		numOf2s = 0;
		numOf3s = 0;
		numOfDividerExceptFor2And3 = 0;
		find2sAnd3s(n);
		int res = findMinMove(n);
		cout << res << endl;
	}

	return 0;
}

