/**
* http://codeforces.com/contest/1408/problem/A
* @author github.com/yilmazhasan
**/

#include <iostream>
#include <vector>

using namespace std;
template <class T>
void print(vector<T> vec) {
	cout << endl;
	for(int i = 0; i < vec.size(); i++) {
		cout << vec[i] << " ";
	}
	cout << endl;
} 

bool nextInds( vector<int> & inds, int ind) {
	if(ind == 0) {
		if(inds[0] < 2) {
			inds[0]++;
		} else {
			return false;
		}
	}
	else {

		if(inds[ind] < 2) {
			inds[ind]++;
		} else {
			inds[ind] = 0;
			nextInds(inds, ind-1);
		}

	} 

	return true;
}


void getASequence(vector<int> as, vector<int> bs, vector<int> cs) {

	int size = as.size();
	vector<int> res;
	vector<int> inds;

	for(int i = 0; i < size; i++) {
		inds.push_back(0);	// init all as all is taken from as
	}

	for(int i = 0; i < size; i++) {
		int currEl = -1;
		int prevEl = -1;
		int nextEl = -1;

		if(i > 0) {
			prevEl = res[i-1];
		}

		if(i == size-1) {
			nextEl = res[0];
		}

		if(inds[i] == 0 ) {
			currEl = as[i];
		} else if(inds[i] == 1 ) {
			currEl = bs[i];
		} else 
		if(inds[i] == 2 ) {
			currEl = cs[i];
		}

		//cout << prevEl << " " << currEl << " " << nextEl << endl;
		if(prevEl != currEl && currEl != nextEl) {
			res.push_back(currEl);
		} else {
			nextInds(inds, i);
			i--;
		}
	}

	print (res);
}

int main(){

	int t;
	int n;
	int x;
	vector<int> as;
	vector<int> bs;
	vector<int> cs;

	cin >> t;

	for(int i = 0; i < t; i++) {
		cin >> n ;
		as.clear();
		bs.clear();
		cs.clear();
		for(int j = 0; j < n; j++) {
			cin >> x;
			as.push_back(x);
		}
		for(int j = 0; j < n; j++) {
			cin >> x;
			bs.push_back(x);
		}
		for(int j = 0; j < n; j++) {
			cin >> x;
			cs.push_back(x);
		}

		getASequence(as, bs, cs);
	}

	return 0;
}