/**
* http://codeforces.com/contest/1291/problem/B
* @author github.com/yilmazhasan
**/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool isArraySharpenable(vector<int> &array, vector<int>::iterator it, int indexOfMax);
bool isArraySharpenable(vector<int> &array);

bool isArraySharpenable(vector<int> &array) {
	vector<int>::iterator it = max_element(std::begin(array), std::end(array));
	bool res = false;

	int threshold = it[0];
	int numsOfMax = 0;

	for(int i = 0; i < array.size(); i++) {
		if(array[i] == it[0]) {
			if(isArraySharpenable(array, next(array.begin(), i), i)) {
				return true;
			}
		}
	}

	return false;
}

bool isArraySharpenable(vector<int> &array, vector<int>::iterator it, int indexOfMax) {
	bool res = false;
	int threshold = it[0];

	// Check for next of max
	for(int i = 0; i < array.size()-1; i++) {
		if(next(it, i+1) == array.end()) {
			break;
		}
		
		if(threshold > next(it, i+1)[0]) {
			threshold = next(it, i + 1)[0];
		} else {
			threshold--;
		}

		if(threshold < 0) {
			return false;
		}
	}

	// Check for prev of max
	threshold = it[0];

	for(int i = 0; i < array.size()-1; i++) {
		if(prev(it, i) == array.begin()) {
			break;
		}

		if(threshold > prev(it, i+1)[0]) {
			threshold = prev(it, i + 1)[0];
		} else {
			threshold--;
		}

		if(threshold < 0) {
			return false;
		}
	}

	return true;
}

int main(){

	int numOfInput;
	int size;
	int digit;
	vector<int> array;

	cin >> numOfInput;

	for(int i = 0; i < numOfInput; i++) {
		cin >> size;
		array.clear();
		for(int j = 0; j < size; j++) {
			cin >> digit;
			array.push_back(digit);
		}

		if(isArraySharpenable(array)) {
			cout << "yes" << endl;
		} else {
			cout << "no" << endl;
		}
	}


	return 0;
}