/**
* https://codeforces.com/contest/1315/problem/B
* @author github.com/yilmazhasan
* 23 Feb 2020
**/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
 
using namespace std;

int getFirstStopToAffordToReachEndByTransporter(string stops, int busCost, int tramCost, int moneyHas) {
	int costNeeded = 0;

	for(int i = stops.size()-2; i > 0; i--) {

		// can come here free, since prev is same
		if(stops[i] == stops[i-1]){
			if(i == 1) {
				if(stops[1] == 'A') {
					costNeeded += busCost;
				} else {
					costNeeded += tramCost;
				}
			} else {
				;
			}
		} else {
				if(stops[i] == 'A') {
					costNeeded += busCost;
				} else { // if stop is B
					costNeeded += tramCost;
					}
			} 


		if(costNeeded > moneyHas) {
			int j = i;
			for(; j < stops.size(); j++) {
				if(stops[j-1] == stops[j]) {
					continue;
				}
				else {
					j = j+1;	// since j is index, return adding by one
					break;
				}
			}
			// cout << "j" << j << " i " << i << costNeeded << " " << moneyHas<<endl;
			return j;
		}

	}

	// can afford all, then just walk to first stop
	return 1;
}

int main(){

	int numOfTest;
	int busCost, tramCost, moneyHas;
	string stops;
	cin >> numOfTest;

	for(int i = 0; i < numOfTest; i++) {
		cin >> busCost >> tramCost >> moneyHas >> stops;
		cout << getFirstStopToAffordToReachEndByTransporter(stops, busCost, tramCost, moneyHas) << endl;
	}

	return 0;
}