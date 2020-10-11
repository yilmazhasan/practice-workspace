#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

template <class T>
void print(vector<T> vec) {
	for(int i = 0; i < vec.size(); i++) {
		cout << vec[i] << " ";
	}
	cout << endl;
} 

int makeAllEqual(int ones, int twos, int threes) {

	vector<int> counts = {ones, twos, threes};
	sort(counts.begin(), counts.end());

	return counts[0] + counts[1];
}


int main(){

	int t;
	int n;
	int ones = 0;
	int twos = 0;
	int threes = 0;

	cin >> t;

	for(int i = 0; i < t; i++) {
		cin >> n ;

		// nums.push_back(n);

		if(n == 1) {
			ones++;
		} else if(n == 2) {
			twos++;
		} else if(n == 3) {
			threes++;
		} 

	}

	cout << makeAllEqual(ones, twos, threes) << endl;

	return 0;
}
