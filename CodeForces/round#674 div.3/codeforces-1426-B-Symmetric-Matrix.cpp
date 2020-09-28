/**
* http://codeforces.com/contest/1426/problem/B
* @author github.com/yilmazhasan
**/

#include <iostream>
#include<vector>
using namespace std;


template <class T>
void printVec(vector<T> vec) {

	for(int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << " ";
	}
	
	cout << endl;	
}

bool isTileSymmetric(vector<vector<int>> arr, int size) {

	for(int i = 0; i < size; i++) {
		for(int j = i+1; j < size; j++) {
			if(arr[i][j] != arr[j][i]) {
				return false;
			}
		}
	}
	
	return true;
}

bool areTilesEqual(vector<vector<int>> tile1, vector<vector<int>> tile2) {
	return tile1[0][0] == tile2[0][0] && tile1[0][1] == tile2[0][1] && tile1[1][0] == tile2[1][0] && tile1[1][1] == tile2[1][1];
}

int findTileInd(vector<vector<vector<int>>> tiles, vector<vector<int>> tile) {
	for(int i = 0; i < tiles.size(); i++) {
		auto tile2 = tiles[i];
		if(areTilesEqual(tile2, tile)) {
			return i;
		}
	}
	
	return -1;
}


vector<vector<int>> getTranspose(vector<vector<int>> vec) {
		
	vector<int> row1; 
	vector<int> row2;
	row1.push_back(vec[0][0]);
	row1.push_back(vec[1][0]);
	row2.push_back(vec[0][1]);
	row2.push_back(vec[1][1]);
		
	vector<vector<int>> transpose;
	
	transpose.push_back(row1);
	transpose.push_back(row2);
	
	return transpose;
}

bool isItPossibleToConstructATile(vector<vector<vector<int>>> tiles, int n) {
	bool psbl = false;
	vector<bool> tilesSymmetric;
	vector<int> transposeInds;
	
	for(int i = 0; i < tiles.size(); i++) {
		auto tile = tiles[i];
		tilesSymmetric.push_back(isTileSymmetric(tile,2));
		
		auto transpose= getTranspose(tiles[i]);
		
		int transposeInd = findTileInd(tiles, transpose);
		
		transposeInds.push_back(transposeInd);
	}

	int neededSymmetricTile = n/2;
	
	int symCount = 0;
	for(int i = 0; i < tilesSymmetric.size(); i++) {
		if(tilesSymmetric[i]) {
			symCount++;
		}
	}

	// one can be reused many times
	if(symCount == 0 && neededSymmetricTile > 0) {
		return false;
	}
	
	int notSymmSelfTransposeCount = 0;
	int notSymmDiffTransposeCount = 0;
	int neededTransposeCount = (n/2) *(n/2) - (n/2);
	for(int i = 0; i < transposeInds.size(); i++) {
		if(!tilesSymmetric[i] && transposeInds[i] != -1) {
			if(i != transposeInds[i]) {
				notSymmDiffTransposeCount++;
			} else {
				notSymmSelfTransposeCount++;
			}
		}
	}
	
	if(neededTransposeCount > 0 && notSymmDiffTransposeCount + notSymmSelfTransposeCount + symCount == 0)
			return false;	
	
	return true;
}


int main(){

	int t;
	int m, n;
	int x;

	vector<vector<vector<int>>> tiles;

	cin >> t;

	for(int i = 0; i < t; i++) {
		cin >> m >> n;
		tiles.clear();
		for(int j = 0; j < m; j++) {
			vector<vector<int>> tile; 
			vector<int> row1; 
			vector<int> row2;
			cin >> x;
			row1.push_back(x);
			cin >> x;
			row1.push_back(x);
			cin >> x;
			row2.push_back(x);
			cin >> x;
			row2.push_back(x);
				
			tile.push_back(row1);
			tile.push_back(row2);
			//cout << isTileSymmetric(tile, 2) << endl;
			
			
			tiles.push_back(tile);			
		}
		
		if(n%2 != 0 || !isItPossibleToConstructATile(tiles, n)) {
			cout << "NO" << endl;
		} else {
			cout << "YES" << endl;
		}
		
	}
	return 0;
}