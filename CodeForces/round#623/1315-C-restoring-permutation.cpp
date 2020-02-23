/**
* https://codeforces.com/contest/1315/problem/C
* @author github.com/yilmazhasan
* 23 Feb 2020
**/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
 
using namespace std;

vector<int> busStops;
vector<int> tramStops;

void print(vector<int> vec) {
	for(int i = 0; i < vec.size() ; i++) {
		cout << vec[i] << " ";
	} 
	cout << endl;
}

int getIndexOfMinGreaterThan(vector<int> vec, int barrier) {
	for(int i = 0; i < vec.size(); i++) {
		if(barrier < vec[i]) {
			return i;
		}
	}

	return -1;
}

vector<int> getRemaining(vector<int> currentList, int size) {
	vector<bool> used(size, false);

	for(int i = 0; i < currentList.size(); i++) {
		used[currentList[i]-1] = true;
	}

	vector<int> remaining;

	for(int i = 0; i < size; i++) {
		if(!used[i]) {
			remaining.push_back(i+1);
		}
	}

	return remaining;
}

int main(){

	int numOfTest;
	int size, permutation;
	int perm;
	vector<int> perms;
	vector<int> remaining;
	cin >> numOfTest;

	vector<int> resVec;

	for(int i = 0; i < numOfTest; i++) {
		cin >> size;
		perms.clear();
		resVec.clear();
		for(int i = 0; i < size; i++) {
			cin >> perm;
			perms.push_back(perm);
		}

		remaining = getRemaining(perms, size*2);

		// print(remaining);

		for(int i = 0; i < size; i++) {
			int ind = getIndexOfMinGreaterThan(remaining, perms[i]);
			if(ind == -1) {
				resVec.clear();
				resVec.push_back(-1);
				break;
			}
			resVec.push_back(perms[i]);
			resVec.push_back(remaining[ind]);
			// cout << perms[i] << " ";
			// cout << remaining[ind] << " ";
			remaining.erase(remaining.begin()+ind);
		}
		print(resVec);
	}


	return 0;
}