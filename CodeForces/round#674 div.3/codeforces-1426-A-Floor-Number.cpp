/**
* http://codeforces.com/contest/1426/problem/A
* @author github.com/yilmazhasan
**/

#include <iostream>

using namespace std;

int getFloor(int aptNo, int x) {
	
	if(x == 1) {
		if(aptNo > 2) {
			return aptNo - 1;
		} else {
			return 1;
		}
	}
	
	// -2 for first floor, then add x-1 to divide exactly
	int floor = (aptNo - 2 + x - 1 ) / x;
	
	return floor + 1;
	
}


int main(){

	int numOfInput;
	int aptNo;
	int x;

	cin >> numOfInput;

	for(int i = 0; i < numOfInput; i++) {
		cin >> aptNo >> x;
		
		cout << getFloor(aptNo, x) << endl;
	}

	return 0;
}