/**
* https://codeforces.com/contest/1398/problem/B
* @author github.com/yilmazhasan
* 8/14/2020
**/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include<bits/stdc++.h> 

using namespace std;

template <class T>
void print(vector<T> vec) {
	for(int i = 0; i < vec.size(); i++) {
		cout << vec[i] << " ";
	}
	cout << endl;
} 


int getMaxScoreOfAlice(string str) {

	vector<int> numOfOnes;

	int counter = 0;
	for(int i = 0; i < str.size(); i++) {
		if(str[i] == '1') {
			counter++;
		} else {
			if(counter > 0) {
				numOfOnes.push_back(counter);
				counter = 0;
			}
		}
	}

	// remaining last counter
	if(counter > 0) {
		numOfOnes.push_back(counter);
		counter = 0;
	}

	// sort to ascending
	sort(numOfOnes.begin(), numOfOnes.end());

	int scoreOfAlice = 0;
	// alice selects first, and so every 2 on
	for(int i = numOfOnes.size()-1; i >= 0; i-= 2) {
		scoreOfAlice += numOfOnes[i];
	}

	return scoreOfAlice;
} 

int main(){

	int numOfTest;
	string bin;

	cin >> numOfTest;

	for(int i = 0; i < numOfTest; i++) {
		cin >> bin ;

		cout << getMaxScoreOfAlice(bin) << endl; 
		// print(numOfOnes);
	}

	return 0;
}

