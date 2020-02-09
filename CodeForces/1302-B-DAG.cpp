/**
* https://codeforces.com/contest/1302/problem/B
* @author github.com/yilmazhasan
**/

#include <iostream>
#include <map>
#include <vector>

using namespace std;

bool existInArray(int element, vector<int> vec) {
	for(int i = 0; i < vec.size(); i++) {
		if(element == vec[i]) {
			return true;
		}
	}

	return false;
}

bool canBeAddedAsPath(int from, int to, vector<int> vec) {
	bool toExist = false;
	bool fromExist = false;

	for(int i = 0; i < vec.size(); i++) {
		if(to == vec[i]) {
			toExist = true;
		}

		if(from == vec[i]) {
			fromExist = true;
		}
	}

	return fromExist && !toExist;
}

// void printVec(vector<int> vec) {
// 	for(int i = 0; i < vec.size(); i++) {
// 		cout << vec[i] << " ";
// 	}
// }

int main(){

	int numOfNode;
	int numOfEdge;

	std::map <int, vector<int>> fromTos;

	cin >> numOfNode >> numOfEdge;

	int from;
	int to;
	vector<int> tos;

	for(int i = 0; i < numOfEdge; i++) {
		cin >> from >> to;

		if(!existInArray(to, fromTos[from])) {
			fromTos[from].push_back(to);
		}

		fromTos[to] = fromTos[to];	// to initialize an empty vector

		for(std::map<int, vector<int>>::iterator it = fromTos.begin(); it != fromTos.end(); ++it) {
			// if(existInArray(from, it->second) && !existInArray(to, it->second)) {
			if(canBeAddedAsPath(from, to, it->second)) {
				it->second.push_back(to);
			}
		}

	}


	int res = 0;

	for(auto it = fromTos.begin(); it != fromTos.end(); it++) {
		res += ((it->second.size()+1) * (it->second.size()+1));	// one for itself
	}
	cout << res << endl;
	return 0;
}

