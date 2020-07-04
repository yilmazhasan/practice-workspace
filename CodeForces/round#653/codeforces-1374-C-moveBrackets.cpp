/**
* https://codeforces.com/contest/1374/problem/C
* @author github.com/yilmazhasan
* 06/28/2020
**/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include<bits/stdc++.h> 

using namespace std;

vector<char> vec;

int checkForMinMove(stack<char> &s) {

	vec.clear();
	vec.resize(s.size());

	int i = 0;
	int last = s.size() - 1;

    while (!s.empty()) 
    { 
		vec[last - i++] = s.top();

		s.pop();
    } 
	
	return 0;
}

void showVec(vector<char> vec) {
	for(int i = 0; i < vec.size(); i++) {
		cout << vec[i] << " ";
	}
	cout << endl;
} 

// void showstack(stack <char> s) 
// { 
// 	cout << "--> " << s.size() << endl;
//     while (!s.empty()) 
//     { 
//         cout << '\t' << s.top(); 
// 		s.pop();
//     } 
//     cout << '\n'; 
// } 

int main(){

	int numOfTest;
	int numOfBrackets;
	char bracket;
	stack <char> s;

	cin >> numOfTest;

	for(int i = 0; i < numOfTest; i++) {
				
		cin >> numOfBrackets;
		for(int j = 0; j < numOfBrackets; j++) {
			cin >> bracket;
			if(bracket == ')') {
				if(s.size() > 0 && s.top() == '(') {
					s.pop();
				} else {
					s.push(bracket);
				}
			} else {
				s.push(bracket);
			}
		}

		checkForMinMove(s);
		cout << vec.size() / 2 << endl;
	}

	return 0;
}

