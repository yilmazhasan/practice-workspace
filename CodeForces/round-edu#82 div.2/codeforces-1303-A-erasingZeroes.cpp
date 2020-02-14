/**
* https://codeforces.com/contest/1303/problem/A
* @author github.com/yilmazhasan
* 12 Feb 2020
**/

#include <iostream>
#include <string>

using namespace std;

int getMinNumOfZeroToErase(string bin) {
	int count = 0;
	bool firstOneSeen = false;
	int lastCounter = 0;
	for(int i = 0; i < bin.size(); i++) {
		if(bin[i] == '1') {
			firstOneSeen = true;
			count += lastCounter;
			lastCounter = 0;
		} else {
			if(firstOneSeen) {
				lastCounter++;
			}
		}
	}

	return count;
}

int main(){

	int numOfTest;
	string binary;

	cin >> numOfTest;

	for(int i = 0; i < numOfTest; i++) {
		cin >> binary;
		int res = getMinNumOfZeroToErase(binary);
		cout << res << endl;

	}

	return 0;
}

