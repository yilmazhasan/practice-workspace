/**
* https://codeforces.com/contest/1388/problem/A
* @author github.com/yilmazhasan
* 7/30/2020
**/

#include <iostream>
#include <vector>
#include<bits/stdc++.h> 

using namespace std;


int main(){

	int numOfTest;
	int size;
	int t;
	int fourth;
	cin >> numOfTest;

	for(int i = 0; i < numOfTest; i++) {
		cin >> t;

	// smallest nearly prime nums are: 6: 2*3, 10: 2*5, 14: 2*7
		if(t > 44) {
			fourth = t - 30;
			cout << "YES" << endl;
			cout << "6 10 14 " << fourth << endl;
		}
		else if(t <= 30) {
			cout << "NO" << endl;
		} else {	// t between 30-44
			int fourth = t - 30;
			if(fourth == 6) {
				cout << "YES" << endl;
				cout << "5 6 10 15" << endl;
			} else if(fourth == 10) {	// t: 40
				cout << "YES" << endl;
				cout << "6 10 15 9" << endl;
			} else if(fourth == 14) {	// t: 44
				cout << "YES" << endl;
				cout << "6 10 21 7" << endl;
			} else {
				cout << "YES" << endl;
				cout << "6 10 14 " << t - 30 << endl;
			}
		}
	}

	return 0;
}

