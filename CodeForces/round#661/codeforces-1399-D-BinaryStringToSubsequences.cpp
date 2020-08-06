/**
* https://codeforces.com/contest/1399/problem/D
* @author github.com/yilmazhasan
* 8/6/2020
**/

// Time limit exceeded on test 4

#include <iostream>
#include <vector>
#include <stack>
#include<bits/stdc++.h> 

using namespace std;

vector<int> indsOfVecsPlaced;
stack<int> zeros;
stack<int> ones;

template <class T>
void print(vector<T> vec) {
	for(int i = 0; i < vec.size(); i++) {
		cout << vec[i] << " ";
	}
	cout << endl;
} 


void printStacks() {
    cout  << "---------" << endl;;

    for (std::stack<int> dump = ones; !dump.empty(); dump.pop())
        std::cout << dump.top() << ' ';
        cout << endl;
    for (std::stack<int> dump = zeros; !dump.empty(); dump.pop())
        std::cout << dump.top() << ' ';
        cout << endl;
    cout  << "---------";
}

vector<string> binaryStringToSubsequences(string str) {
    vector<string> subStrs;
    for(int i = 0; i < str.size(); i++) {
        int ind = -1;

        // printStacks();
        if(str[i] == '0') {
            if(ones.size() > 0) {
                ind = ones.top();
                ones.pop();
                zeros.push(ind);
            } else {
                ind = -1;
                zeros.push(subStrs.size()); // a new substring starting with zero
            }
        } else {
            if(zeros.size() > 0) {
                ind = zeros.top();
                zeros.pop();
                ones.push(ind);
            } else {
                ind = -1;
                ones.push(subStrs.size()); // a new substring starting with one
            }
        }

        if(ind >= 0) {
            subStrs[ind].push_back(str[i]);
            indsOfVecsPlaced.push_back(ind+1);
        } else {
            string s = "";
            s.push_back(str[i]);
            subStrs.push_back(s);
            indsOfVecsPlaced.push_back(subStrs.size());
        }
    }

    return subStrs;
}

int main(){
	int numOfTest;
	cin >> numOfTest;
	
    stack<int> st;

	int l;
    string s;

	for(int i = 0; i < numOfTest; i++) {
		cin >> l;
		cin >> s;
        ones = stack<int>();
        zeros = stack<int>();
        indsOfVecsPlaced.clear();
        vector<string> subStrs = binaryStringToSubsequences(s);
        cout << subStrs.size() << endl;
        print(indsOfVecsPlaced);
	}

	return 0;
}

