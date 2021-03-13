#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

template <class T>
void print(vector<T> vec) {
	for(long long i = 0; i < vec.size(); i++)
		cout << vec[i] << " ";
		cout << endl;
}

void printLayers(vector<int> &pouredCreams, int ind, int remainingSause) {
	if(ind == -1) {
		return;
	}

	if(pouredCreams[ind] > remainingSause) {
		remainingSause = pouredCreams[ind];
	}

	printLayers(pouredCreams, ind-1, remainingSause-1);

	if(remainingSause > 0) {
		cout << "1 ";
	} else {
		cout << "0 ";
	}

}

void getDrenchedLayers(vector<int> pouredCreams) {
	int size = pouredCreams.size();

	printLayers(pouredCreams, size-1, 0);
	cout << endl;
}

int main(){

	int t, n, x;

	vector<int> pouredCreams;

	cin >> t;

	for(int i = 0; i < t; i++) {
		cin >> n;
		pouredCreams.clear();
		for(int j = 0; j < n; j++) {
			cin >> x;
			pouredCreams.push_back(x);
		}

		getDrenchedLayers(pouredCreams);
	}

	return 0;
}