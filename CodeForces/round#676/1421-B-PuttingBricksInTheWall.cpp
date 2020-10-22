/**
* https://codeforces.com/contest/1321/problem/C
* @author github.com/yilmazhasan
* 18 Oct 2020
**/

// not submitted, way finding is completed

#include <iostream>
#include <vector>
#include <string>
#include <tuple>
 
using namespace std;

template <class T>
void print(vector<T> vec) {
	for(int i = 0; i < vec.size(); i++) {
		cout << vec[i] << " ";
	}
	cout << endl;
} 

void print(vector<tuple<int, int>> vec) {
	for(int i = 0; i < vec.size(); i++) {
		cout << get<0>(vec[i]) << get<1>(vec[i]) << endl; 
	}
} 

bool findAWay(vector<string> &vec, int currX, int currY, char on, vector<tuple<int, int>> &path) {

	// cout << currX << "," << currY << " " << endl;

	if(currX == vec.size()-1 && currY == vec[0].size()-1) {
		// cout << "A" << endl;
		// path.push_back(make_tuple(currX, currY));
		// print(path);
		return true;
	}

	if(currX < vec.size()-1) {
		// cout << "B" << endl;
		if(vec[currX+1][currY] == on && findAWay(vec, currX+1, currY, on, path)) {
			// cout << "B1" << endl;
			path.push_back(make_tuple(currX+1, currY));
			// print(path);
			return true;
			// return findAWay(vec, currX+1, currY, on, path);
		}
	}
	
	if(currY < vec[0].size()-1) {
		// cout << "C" << endl;
		if(vec[currX][currY+1] == on && findAWay(vec, currX, currY+1, on, path)) {
		// cout << "C1" << endl;
			// return findAWay(vec, currX, currY+1, on, path);
			path.push_back(make_tuple(currX, currY+1));
			// print(path);
			return true;
			// return findAWay(vec)
		}
	}
	

	return false;

}

void putBricksInTheWall(vector<string> &vec) {

	vector<tuple<int, int>> path0;
	vector<tuple<int, int>> path1;
	// make final dest as movable
	int lastX = vec.size()-1;
	int lastY = vec[0].size()-1;
	vec[lastX][lastY] = '0';
	bool with0 = findAWay(vec, 0, 0, '0', path0);
	// cout << findAWay(vec, 0, 0, '0', path) << " way found";
	print(path0);
	cout << "---" << endl;

	vec[lastX][lastY] = '1';
	bool with1 = findAWay(vec, 0, 0, '1', path0);
	print(path1);
}

int main(){

	int t, n;
	int a, b;
	string s;
	vector<string> vec;
	cin >> t;

	for(int i = 0; i < t; i++) {
		vec.clear();
		cin >>n;
		for(int j = 0; j < n; j++) {
			cin >> s ;
			vec.push_back(s);
		}

		putBricksInTheWall(vec);
	}

	return 0;
}