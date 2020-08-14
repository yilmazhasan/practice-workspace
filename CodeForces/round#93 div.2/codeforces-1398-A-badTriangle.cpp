/**
* https://codeforces.com/contest/1398/problem/A
* @author github.com/yilmazhasan
* 8/14/2020
**/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include<bits/stdc++.h> 

using namespace std;

map<tuple<int, int>, tuple<int, int>> minMaxEdges;



bool isPossibleToConstructATriangle(int a, int b, int c) {
	if(a > abs(b-c) && a < b+c) {
		return true;
	}

	return false;
}

int getMinEdge(int a, int b) {
	return abs(a-b);
}

int getMaxEdge(int a, int b) {
	return a+b;
}

int getIndexOfMinEl(vector<int> edges) {
	int indOfM = 0;
	for(int i = 1; i < edges.size(); i++) {
		if(edges[indOfM] > edges[i]) {
			indOfM = i;
		}
	}

	return indOfM;
}

int getIndexOfMaxEl(vector<int> edges) {
	int indOfM = 0;
	for(int i = 1; i < edges.size(); i++) {
		if(edges[indOfM] < edges[i]) {
			indOfM = i;
		}
	}

	return indOfM;
}

void printInOrder(int a, int b, int c) {
	int bigger ;
	int smaller;
	int mid;

	if(a > b && a > c) {
		bigger = a;
		if(b > c) {
			mid = b;
			smaller = c;
		} else {
			smaller = b;
			mid = c;
		}
	}
	else if(b > a && b > c) {
		bigger = b;
		if(a > c) {
			mid = a;
			smaller = c;
		} else {
			smaller = a;
			mid = c;
		}
	} else {
		bigger = c;
		if(b > a) {
			mid = b;
			smaller = a;
		} else {
			smaller = b;
			mid = a;
		}
	}

	// print indexes starting from 1 
	cout << smaller+1 << " " << mid+1 << " " << bigger+1 << endl;
}

void getIndexesOfANonDegenerateTriangle(vector<int> edges) {

	int indOfMin = getIndexOfMinEl(edges);
	int indOfMax = getIndexOfMaxEl(edges);

	int minEl = edges[indOfMin];
	int maxEl = edges[indOfMax];

	int sum = minEl + maxEl;
	int diff = maxEl - minEl;

	for(int i = 0; i < edges.size(); i++) {
		if(i != indOfMin && i != indOfMax) {

			if(edges[i] <= diff || edges[i] >= sum) {
				printInOrder(indOfMin, indOfMax, i);
				return;
			}
		} 
	}

/*
	for(int i = 0; i < edges.size(); i++) {
		for(int j = i+1; j < edges.size(); j++) {

			auto edgeOneTwo = make_tuple(edges[i], edges[j]);
			auto edgeThreeMinMax = make_tuple(getMinEdge(edges[i], edges[j]), getMaxEdge(edges[i], edges[j]));

			minMaxEdges[edgeOneTwo] = edgeThreeMinMax;

			for(int k = j+1; k < edges.size(); k++) {

				if(edges[k] > get<0>(edgeThreeMinMax) && edges[k] < get<1>(edgeThreeMinMax)) {
					continue; // degenerate
				} else {

					cout << i+1 << " " << j+1 << " " << k+1 << endl;
					return;
				}

				// if(!isPossibleToConstructATriangle(edges[i], edges[j], edges[k])) {
				// 	// cout << edges[i] << edges[j] << edges[k] << endl;
				// 	return;
				// }
			}
		}
	}
*/
	cout << "-1" << endl;


}


int main(){

	int numOfTest;
	int size;
	int t;
	vector<int> edges;


	cin >> numOfTest;

	for(int i = 0; i < numOfTest; i++) {
		cin >> size;
		edges.clear();
		for(int j = 0; j < size; j++) {
			cin >> t;

			edges.push_back(t);
		}

		getIndexesOfANonDegenerateTriangle(edges);

	}

	return 0;
}

