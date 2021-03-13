#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

template <class T>
void print(vector<T> vec) {
	for(long long i = 0; i < vec.size(); i++)
		cout << vec[i];
		cout << endl;
}

int getArrivalToLastStation(vector<pair<int, int>> abs, vector<int> tms) {

	int n= abs.size();

	int time = 0;

	for(int i = 0; i < n; i++) {
		if(i == 0) {
			time += tms[i] + abs[i].first;
		} else {
			time += tms[i] + abs[i].first - abs[i-1].second;
		}

		if(i == n-1) {
			break;
		}

		time += (abs[i].second - abs[i].first + 1) / 2;

		if(time < abs[i].second) {
			time = abs[i].second;
		}
	}

	return time;
}

int main(){

	int t, n, x , a, b, tm;

	vector<pair<int, int>> abs;
	vector<int> tms;

	cin >> t;

	for(int i = 0; i < t; i++) {
		cin >> n;
		abs.clear();
		tms.clear();
		for(int j = 0; j < n; j++) {
			cin >> a >> b;
			abs.push_back(make_pair(a, b));
		}

		for(int j = 0; j < n; j++) {
			cin >> tm;
			tms.push_back(tm);
		}

		cout << getArrivalToLastStation(abs, tms) << endl;
	}

	return 0;
}