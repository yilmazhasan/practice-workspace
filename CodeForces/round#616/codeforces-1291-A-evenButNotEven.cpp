/**
* http://codeforces.com/contest/1291/problem/A
* @author github.com/yilmazhasan
**/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


void printNum(vector<char> digitsOfNum) {
	for(int i = 0; i < digitsOfNum.size(); i++)
		cout << digitsOfNum[i];
		cout << endl;
}

int main(){

	int numOfInput;
	int numOfDigits;
	char digit;
	vector<char> digitsOfNum;
	vector<char> digitsOfNumAfterDeleting;

	cin >> numOfInput;

	for(int i = 0; i < numOfInput; i++) {
		cin >> numOfDigits;
		digitsOfNum.clear();
		for(int j = 0; j < numOfDigits; j++) {
			cin >> digit;
			if((digit - '0') %2 == 0)
				continue;
			digitsOfNum.push_back(digit);
		}

		if(digitsOfNum.size() <= 1) {
			cout << -1 << endl;
		} else{
			if (digitsOfNum.size() %2 == 1){
				digitsOfNum.erase(digitsOfNum.begin());
			}

			printNum(digitsOfNum);
		} 
	}

	return 0;
}