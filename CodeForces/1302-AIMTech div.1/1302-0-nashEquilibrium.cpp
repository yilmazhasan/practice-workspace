/**
* https://codeforces.com/contest/1302/problem/A
* @author github.com/yilmazhasan
**/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int eqCoords[] = {0,0};

int findMinColIndexInRowIfUnique(vector<int> vec) {
	int minInd = 0;
	bool equality = false;
	for(int i = 1; i < vec.size(); i++) {
		if(vec[i] < vec[minInd]) {
			minInd = i;
		} else if(vec[i] == vec[minInd]) {
			equality = true;
		}
	}

	if(equality) {
		return -2;
	} else {
		return minInd;
	}
}

int findMaxRowIndexInColIfUnique(vector<vector<int>> vec, int indOfCol) {
	int maxInd = 0;
	bool equality = false;

	for(int i = 1; i < vec.size(); i++) {
		if(vec[i][indOfCol] > vec[maxInd][indOfCol]) {
			maxInd = i;
			equality = false;
		} else if(vec[i][indOfCol] == vec[maxInd][indOfCol]) {
			equality = true;
		}
	}
	if(equality) {
		return -2;
	} else {
		return maxInd;
	}
}

// if max is more than one, then return -2
int findMaxColIndexInRowIfUnique(vector<int> vec) {
	int maxInd = 0;
	bool equality = false;
	for(int i = 1; i < vec.size(); i++) {
		if(vec[i] > vec[maxInd]) {
			maxInd = i;
		} else if(vec[i] == vec[maxInd]) {
			equality = true;
		}
	}

	if(equality) {
		return -2;
	} else {
		return maxInd;
	}
}

// if min is more than one, then return -2
int findMinRowIndexInColIfUnique(vector<vector<int>> vec, int indOfCol) {
	int minInd = 0;
	bool equality = false;

	for(int i = 1; i < vec.size(); i++) {
		if(vec[i][indOfCol] < vec[minInd][indOfCol]) {
			minInd = i;
			equality = false;
		} else if(vec[i][indOfCol] == vec[minInd][indOfCol]) {
			equality = true;
		}
	}
	if(equality) {
		return -2;
	} else {
		return minInd;
	}
}


void getEquilibriumCoords(vector<vector<int>> matrix) {
	int coords[] = {0,0};
	bool found = false;
	int colIndOfMaxInARow = 0;
	int rowIndOfMinInACol = 0;
	vector<int> indsOfMinInCols(matrix[0].size(), -1);

	for(int i = 0; i < matrix.size(); i++) {
		colIndOfMaxInARow = findMaxColIndexInRowIfUnique(matrix[i]);
		// cout << i << " " << colIndOfMaxInARow << endl;
		if(indsOfMinInCols[colIndOfMaxInARow] != -1) {
			rowIndOfMinInACol = indsOfMinInCols[colIndOfMaxInARow];
		} else {
			indsOfMinInCols[colIndOfMaxInARow] = rowIndOfMinInACol = findMinRowIndexInColIfUnique(matrix, colIndOfMaxInARow);			
			// cout << i << " - " << rowIndOfMinInACol << endl;
		}

		if(rowIndOfMinInACol == i) {
			eqCoords[0] = rowIndOfMinInACol+1;
			eqCoords[1] = colIndOfMaxInARow+1;
			return;
		}

	}

}

int main(){

	int rowSize;
	int colSize;
	int temp;
	vector<vector<int>> matrix;

	cin >> rowSize >> colSize;

	for(int i = 0; i < rowSize; i++) {
		vector<int> row;
		for(int j = 0; j < colSize; j++) {
			cin >> temp;
			row.push_back(temp);
		}
		matrix.push_back(row);
	}

	getEquilibriumCoords(matrix);

	cout << eqCoords[0] << " " << eqCoords[1] << endl;

	return 0;
}

