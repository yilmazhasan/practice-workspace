/**
* https://codeforces.com/contest/1379/problem/A
* @author github.com/yilmazhasan
* 7/19/2020
**/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include<bits/stdc++.h> 

/*
edge tests: 
11 abacab?caba
11 aba?a??bacaba
11 aca?ac?bacaba

*/

using namespace std;

string keyStr = "abacaba";

bool isKeyStrMatchesWithThisPos(string str, int sPos) {
	for(int i = 0; i < keyStr.size(); i++) {
		if(keyStr[i] == str[i+sPos] || str[i+sPos] == '?') {
			continue;
		} else {
			return false;
		}
	}

	return true;
}

int howManyKeyStrIsThere(string str) {
	int count = 0;
	bool match = true;

	int end = str.size() - keyStr.size();

	for(int s = 0; s <= end; s++) {
		match = true; 	// assume
		for(int i = 0; i < keyStr.size(); i++) {
			if(str[s + i] != keyStr[i]) {
				match = false;
				break;
			}
		}

		if(match) {
			count++;
		}
	}

	return count;
}

string replaceQuestionMarks(string str, int start) {
	for(int i = 0; i < keyStr.size(); i++) {
		str[start + i] = keyStr[i];
	}

	return str;
}

int getMinIndForAcaisusAndString(string str) {
	int end = str.size() - keyStr.size();
	for(int i = 0; i <= end; i++) {
		if(isKeyStrMatchesWithThisPos(str, i)) {

			string questionsRemovedStr = replaceQuestionMarks(str, i);

			int matchCount = howManyKeyStrIsThere(questionsRemovedStr);
			if(matchCount == 1) {
				return i;
			}
		}
	}

	return -1;
}

string replaceQuestionsWithRandomChar(string resStr) {
	for(int i = 0; i < resStr.size(); i++) {
		if(resStr[i] == '?') {
			resStr[i] = 'd';
		}
	}

	return resStr;
}

int main(){

	int numOfTest;
	int size;

	string str;

	cin >> numOfTest;

	for(int i = 0; i < numOfTest; i++) {
		cin >> size >> str;

		int matchCountWithoutQuestionMark = howManyKeyStrIsThere(str);
		int minIndForAcaisusAndString  = -1;
		
		if(matchCountWithoutQuestionMark > 1) {
			minIndForAcaisusAndString = -1;
		} else if(matchCountWithoutQuestionMark == 1) {
			minIndForAcaisusAndString = str.find(keyStr);
		} else {
			minIndForAcaisusAndString = getMinIndForAcaisusAndString(str);
		}

		if(minIndForAcaisusAndString >= 0) {
			string resStr = str.substr (0, minIndForAcaisusAndString) + keyStr + str.substr(minIndForAcaisusAndString + keyStr.size());

			resStr = replaceQuestionsWithRandomChar(resStr);

			// cout << minIndForAcaisusAndString << endl;
			cout << "Yes" << endl;
			cout << resStr << endl;
		} else {
			cout << "No" << endl;
		}

	}

	return 0;
}

