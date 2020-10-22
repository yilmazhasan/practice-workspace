/**
* https://codeforces.com/contest/1321/problem/A
* @author github.com/yilmazhasan
* 18 Oct 2020
**/

#include <iostream>
 
using namespace std;


int getMinValue(int a, int b) {
	int common = a & b;
	
	return (a ^ common) + (b ^ common);
	
}

int main(){

	int t;
	int a, b;
	cin >> t;

	for(int i = 0; i < t; i++) {
		cin >> a >> b;
		cout << getMinValue(a, b) << endl;
	}

	return 0;
}