#include <iostream>
#include <vector>

using namespace std;


// 3 5 8 9 
// 4 6 8 10
bool areArraysWellMatched(vector<int> vec1, vector<int> vec2) {

	int diff = 0;

	if (vec1.size() == 1) {
		if (vec1[0] != vec2[0])
			return false;
		else return true;
	}

	for (int i = 0; i < vec1.size(); i++) {

		if (vec1[i] == vec2[i]) {
			if (diff != 0) {
				diff = INT_MAX;
			}
			continue;
		}
		else {

			if (diff == 0) {	// init diff
				diff = vec1[i] - vec2[i];
			}
			else if (diff == vec1[i] - vec2[i]) {
				continue;
			}
			else return false;
		}
	}

	return true;

}

int main()
{
	int numOfTestCase;
	int size;
	cin >> numOfTestCase;
	int n;
	while (numOfTestCase > 0) {

		cin >> size;
		vector<int> arr1;
		vector<int> arr2;

		for (int i = 0; i < size; i++) {
			cin >> n;
			arr1.push_back(n);
		}

		for (int i = 0; i < size; i++) {
			cin >> n;
			arr2.push_back(n);
		}

		if (areArraysWellMatched(arr1, arr2))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
		numOfTestCase--;
	}

}