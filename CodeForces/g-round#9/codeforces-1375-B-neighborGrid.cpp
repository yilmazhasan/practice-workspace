/**
* https://codeforces.com/contest/1375/problem/B
* @author github.com/yilmazhasan
* 04.07.2020
**/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include<bits/stdc++.h> 

using namespace std;

int getNumOfPositiveNeighbor(vector<vector<double>> vec, int row, int col, int& numOfNeighbor) {
	int num = 0;

	if(row > 0) {
		numOfNeighbor++;
		if(vec[row-1][col] > 0) {
			num++;
		}
	}
	if(row < vec.size()-1) {
		numOfNeighbor++;
		if(vec[row+1][col] > 0) {
			num++;
		}
	}

	if(col > 0) {
		numOfNeighbor++;
		if(vec[row][col-1] > 0) {
			num++;
		}
	}
	
	if(col < vec[row].size()-1) {
		numOfNeighbor++;
		if(vec[row][col+1] > 0) {
			num++;
		}
	}

	return num;
}

int getNumOfZeroNeighbor(vector<vector<double>> vec, int row, int col) {
	int num = 0;

	if(row > 0) {
		if(vec[row-1][col] == 0) {
			num++;
		}
	} else if(row < vec.size()-1) {
		if(vec[row+1][col] == 0) {
			num++;
		}
	}

	if(col > 0) {
		if(vec[row][col-1] == 0) {
			num++;
		}
	} else if(col < vec.size()-1) {
		if(vec[row][col+1] == 0) {
			num++;
		}
	}

	return num;
}

void print(vector<vector<double>> vec) {
	for(int i = 0; i < vec.size(); i++) {
		for(int j = 0; j < vec[i].size(); j++) {
			cout << vec[i][j] << " ";
		}

		cout << endl;
	}
}

bool continueToCheck(vector<vector<double>> vec) {
	for(int i = 0; i < vec.size(); i++) {
		for(int j = 0; j < vec[i].size(); j++) {
			int numOfNeighbor = 0;
			int n = getNumOfPositiveNeighbor(vec, i, j, numOfNeighbor);
			
			if(vec[i][j] > numOfNeighbor) {
				// cout << vec[i][j] << " " << numOfNeighbor << endl;
				return false;
			}

			if(vec[i][j] != 0 && n != vec[i][j]) {
				return true;
			}
		}
	}

	return true;
}

void findZeroNeighborOf(vector<vector<double>> vec, int row, int col, int& foundRow, int& foundCol) {

	bool found = false;

	foundCol = col;
	foundRow = row;

	if(row > 0) {
		if(vec[row-1][col] == 0) {
			foundRow = row-1;
			found = true;
		}
	} else if(row < vec.size()-1) {
		if(vec[row+1][col] == 0) {
			foundRow = row+1;
			found = true;
		}
	}

	if(!found && col > 0) {
		if(vec[row][col-1] == 0) {
			foundCol = col-1;
			found = true;
		}
	} else if(col < vec.size()-1) {
		if(vec[row][col+1] == 0) {
			foundCol = col+1;
			found = true;
		}
	}



}

void scanVec(vector<vector<double>> &vec) {
	for(int i = 0; i < vec.size(); i++) {
		for(int j = 0; j < vec[i].size(); j++) {
			int numOfNeighbor = 0;
			int numOfPositiveNeighbor = getNumOfPositiveNeighbor(vec, i, j, numOfNeighbor);
			// cout << "numOfPositiveNeighbor: " << numOfPositiveNeighbor <<  "numOfNeighbor: " << numOfNeighbor << " i,j: " << i << j << endl; 
			if(vec[i][j] > 0 && vec[i][j] < numOfPositiveNeighbor) {
				while(numOfPositiveNeighbor > vec[i][j]) {
					vec[i][j]++;
				}
			} else if(numOfPositiveNeighbor < vec[i][j]) {
				int foundRow = 0;
				int foundCol = 0;
				while(numOfPositiveNeighbor < vec[i][j]) {
					findZeroNeighborOf(vec, i, j, foundRow, foundCol);
					if(foundRow == i && foundCol == j) {
						break;
					}
					vec[foundRow][foundCol]++;
					numOfPositiveNeighbor++;
				}
			}
		}
	}

}

bool isVecOk(vector<vector<double>> vec) {
	bool ok = true;
	for(int i = 0; i < vec.size(); i++) {
		int numOfNeighbor = 0;
		for(int j = 0; j < vec[i].size(); j++) {
			int n = getNumOfPositiveNeighbor(vec, i, j, numOfNeighbor);
			
			if(vec[i][j] != 0 && n != vec[i][j]) {
				ok = false;
			}			
		}
	}

	return ok;
}

void neighborGrid(vector<vector<double>> vec) {

	char c;

	int count = 0;

	while(continueToCheck(vec)) {
		if(count++ >= vec.size() * vec.size()) {
			break;
		}

		scanVec(vec); 

	}

	if(isVecOk(vec)) {
		cout << "YES" << endl;
		print(vec);
	} else {
		cout << "NO" << endl;
	}

}

int main(){

	int numOfTest;
	int row, col;
	int n;

	vector<vector<double>> vec;

	cin >> numOfTest;

	for(int i = 0; i < numOfTest; i++) {
		cin >> row >> col;

		vec.clear();
		for(int j = 0; j < row; j++) {
			vector<double> vecR;
			for(int k = 0; k < col; k++) {
				cin >> n;
				vecR.push_back(n);
			}
			vec.push_back(vecR);
		}
		// cout << "neighbor, vecSize: " << vec.size() << endl;
		neighborGrid(vec);
	}

	return 0;
}

