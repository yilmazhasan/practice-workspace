/**
* https://codeforces.com/contest/1388/problem/B
* @author github.com/yilmazhasan
* 7/30/2020
**/

// Wrong answer on pretest 2

#include <iostream>
#include <vector>
#include<bits/stdc++.h> 

using namespace std;

string giveBin(int n) {
	string res = "";
	for(int i = 0; n > 0; i++) {
		if(n % 2 == 0) {
			res = "0" + res;
		} else {
			res = "1" + res;
		}
		n = n/2;
	}

	return res;
}

int convertToDecimal(string str) {
	int res = 0;

	for(int i = 0; i < str.size(); i++){
		res *= 2;
		if(str[i] == '1') {
			res++;
		}
	}

	return res;
}

// finds bits first and re-converts to decimal later, slow on big numbers
string findMinValueThatGivesMax2(int n) {
	string maxBin = "";

	for(int i = 0; i < n; i++) {
		maxBin += "1001"; // 9
	}

	// cout << maxBin << endl;

	// delete last n digit to minimize number
	for(int i = 0; i < n; i++) {
		maxBin[n * 4 - 1 - i] = '0';
	}

	// cout << maxBin << endl;

	string fourDigit;
	string min="";
	
	for(int i = maxBin.size()-4; i>=0; i-=4) {
		fourDigit = maxBin.substr(i, 4);

		int digit = convertToDecimal(fourDigit);
		min = (char)(digit + '0') + min;
	}

	return min;
}

// without converting, it determines according to n, very fast
string findMinValueThatGivesMax(int n) {
	string str = "";

	for(int i = 0; i < n; i++) {
		str += "9";
	}

	// cout << "max: " << str << endl;

	int counter = 0;
	while(n > 0) {

		if(n <= 3) {	// since max digit 9 is: 1001; if n is 1,2 or 3 digit will be 1000 (8) else 0000 (0) 
			str[str.size()-1 - counter] = '8';
		} else {
			str[str.size()-1-counter] = '0';
		}

		n -= 4;
		counter++;
	}
	// cout << "after deleting : " << str << endl;

	return str;
}


int main(){
	int numOfTest;
	cin >> numOfTest;

	int n;
	for(int i = 0; i < numOfTest; i++) {
		cin >> n;


		cout << findMinValueThatGivesMax2(n) << endl;
	}

	return 0;
}

