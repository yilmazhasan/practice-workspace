/**
* https://codeforces.com/contest/1397/problem/A
* @author github.com/yilmazhasan
* 30.08.2020
**/


#include <iostream>
#include <vector>
#include<bits/stdc++.h>


using namespace std;
map<char, int> chars;

bool isPossible(vector<string> strs) {
	chars.clear();
	int strsSize = strs.size();

	for(int i = 0; i < strs.size(); i++) {
		for(int j = 0; j < strs[i].size(); j++) {
			chars[strs[i][j]] += 1;
		}
	}

	for(std::map<char,int>::iterator it = chars.begin(); it != chars.end(); ++it) {
		if(it->second % strsSize != 0) {
			return false;
		}
	}

	return true;
}

int main(){
	int numOfTest;
	int numOfStrings;
	string str;

	vector<string> strs;

	// chars['a'] = 1;
	// cout <<chars['b'] << endl;
	// chars['c'] += 1;
	// cout <<chars['c'] << endl;

	cin >> numOfTest;

	for(int i = 0; i < numOfTest; i++) {

		strs.clear();
		cin >> numOfStrings;
		for(int j = 0; j < numOfStrings; j++) {

			cin >> str;

			strs.push_back(str);

		}
		if(isPossible(strs)) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}

	return 0;
}

