/**
* http://codeforces.com/contest/1430/problem/A
* @author github.com/yilmazhasan
**/

// wrong answer Integer -1 violates the range [0, 10^18] (test case 3): No such requirement

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


void printNum(vector<char> digitsOfNum) {
	for(int i = 0; i < digitsOfNum.size(); i++)
		cout << digitsOfNum[i];
		cout << endl;
}

void giveAPossibleApartment(int n) {
	int mod = 3*5*7;

	int threes = 0;
	int fives = 0;
	int sevens = 0;

	int division = n / mod;

	// add all to sevens

	int remaining = n % mod;

	if(remaining == 1 || remaining == 2 || remaining == 4) {
		// cout << remaining << " " << division << endl;
		if(division > 0 ) {
			division--;
			remaining += mod;
		}
	}

	sevens += division * 15;

	for(int i = 0; i < 35; i++) {
		for(int j = 0; j < 21; j++){
			for(int k = 0; k < 15; k++) {
				int mult = i * 3 + j * 5 + k * 7;
				if(mult == remaining) {
					cout << i << " "<< j << " "<< k + sevens<< endl;
					return;
				}
				if(mult > mod) {
					break;
				}
			}
			int mult = i * 3 + j * 5 ;
			if(mult > mod) {
				break;
			}
		}
	}

	cout << -1 << endl;

} 

int main(){

	int t;
	int n;


	cin >> t;

	for(int i = 0; i < t; i++) {
		cin >> n;

		giveAPossibleApartment(n);
	}

	return 0;
}