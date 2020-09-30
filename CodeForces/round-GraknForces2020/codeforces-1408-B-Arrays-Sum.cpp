/**
* http://codeforces.com/contest/1408/problem/A
* @author github.com/yilmazhasan
**/

// wrong answer on test2

#include <iostream>
#include <vector>
#include <set>

using namespace std;

int getMinM(vector<int> as, int k) {
//    sort(as.begin(), as.end());
//    set<int> mySet;
//    mySet.insert(as[i]);

	int size = as.size();
    int setSize = 0;

    int prev = -1;  // since elements are non-negative, set first to be different than all other elements
    int current;

    for(int i = 0; i < size; i++) {
        current = as[i];
        if(prev != current) {
            setSize++;
        }
        prev = current;
    }

//    cout << setSize << endl;

    if(k == 1) {
        // if all not same
        if(setSize != 1) {
            return -1;
        } else 
        return 1;
    }

    return (setSize + k - 1) / k;
}

int main(){

	int t;
	int n;
    int k;
	int x;
	vector<int> as;

	cin >> t;

	for(int i = 0; i < t; i++) {
		cin >> n >> k;
		as.clear();
		for(int j = 0; j < n; j++) {
			cin >> x;
			as.push_back(x);
		}
		cout << getMinM(as, k) << endl;
	}

	return 0;
}