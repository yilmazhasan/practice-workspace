#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// wrong answer on test2

vector<int> indexes1; // indexes of lone W's
vector<int> indexes2; // indexes of WLW's

void prepareIndex1ToChangeToWin(string &s) {
	int size = s.size();
	if(s[1] == 'W' && s[0] == 'L') {
		indexes1.push_back(0);
	}

	for(int i = 2; i < size; i++) {
		if(s[i] == 'W' && s[i-1] == 'L') {
			indexes1.push_back(i-1);
		}
	}
	return ;
}

void prepareIndex2ToChangeToWin(string &s) {
	int size = s.size();

	for(int i = 2; i < size; i++) {
		if(s[i] == 'W' && s[i-1] == 'L' && s[i-2] == 'W') {
			indexes2.push_back(i-1);
		}
	}

	return ;
}

void fillIndexes2(string& s, int &k) {
	for(int i = 0; i < indexes2.size() & k > 0; i++) {
		// cout << i << endl; 
		s[indexes2[i]] = 'W';
		k--;
	}
}

void fillIndexes1(string& s, int &k) {
	for(int i = 0; i < indexes1.size() & k > 0; i++) {
		// cout << i << endl; 
		s[indexes1[i]] = 'W';
		k--;
	}
}

int getScore(string& s) {
	int score = 0;
	if(s[0] == 'W') {
		score =1;
	}

	for(int i = 1; i < s.size(); i++) {
		if(s[i] == 'W') {

			if(s[i-1] == 'W') {
				score += 2;
			} else {
				score += 1;
			}
		}
	}

	return score;
}

void fillRemaining(string &s, int k) {
	for(int i = 0; i < s.size() && k > 0; i++) {
		if(s[i] != 'W') {
			s[i] = 'W';
			k--;
		}
	}
}

int getMaxScore(string &s, int k) {

	prepareIndex2ToChangeToWin(s);
	fillIndexes2(s, k);
	prepareIndex1ToChangeToWin(s);
	fillIndexes1(s, k);

	fillRemaining(s, k);
	return getScore(s);
}


int main(){

	int t;
	int n, k;
	string s;

	vector<int> nums;

	cin >> t;

	for(int i = 0; i < t; i++) {
		cin >> n >> k;
		cin >> s;
		indexes1.clear();
		indexes2.clear();
		cout << getMaxScore(s, k) << endl;
	}


	return 0;
}
