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

int getCostOfPrevStopToCurrent(string stops, int i, int busCost, int tramCost) {
	if(stops[i-1] == stops[i])
		return 0;

	if(stops[i-1] == 'A') {
		return busCost;
	} else { // if stop is B
		return tramCost;
	}
}

int getFirstStopToAffordToReachEndByTransporter(string stops, int busCost, int tramCost, int moneyHas) {
	int costNeeded = 0;

	if(moneyHas < tramCost && moneyHas < busCost) {
		return stops.size();
	}

	for(int i = stops.size()-1; i > 0; i--) {

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
				// since prev can bring me to the current
				if(i != stops.size()-1) {
					if(stops[i] == 'A') {
						costNeeded += busCost;
					} else { // if stop is B
						costNeeded += tramCost;
						}
				}
			} 


		if(costNeeded > moneyHas) {
			int j = i;
			for(; j < stops.size()-1; j++) {
				if(stops[j] == stops[j+1]) {
					continue;
				}
				else {
					j = j+1;	// since j is index, return adding by one
					break;
				}
			}
			// cout << "j: " << j << " i: " << i << " " << costNeeded << " ?<= " << moneyHas<<endl;
			return j+1;	// not index, returning num but not adding since after loop, j will be one more 
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