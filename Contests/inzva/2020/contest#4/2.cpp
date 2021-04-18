#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
#include <climits>

using namespace std;


template <class T>
void print(vector<T> vec) {
	for(int i = 0; i < vec.size(); i++) {
		cout << vec[i] << " ";
	}
	cout << endl;
}


long getMinFuelReuqired(vector<long>::iterator  it_first, vector<long>::iterator  it_last) {

    if(*it_first < 0 && *it_last < 0) {
        return abs(*it_first);
    }

    if(*it_first < 0 && *it_last > 0) {
        if(abs(*it_first) < *it_last) {
            return abs(*it_first) * 2 + *it_last;
        } else {
            return abs(*it_first) + 2**it_last;
        }
    }

    return *it_last;

}

int main() {

    int N, k;

    cin >> N >> k;

    long x;

    vector<long> xs;

    for(int i = 0; i < N; i++) {
        cin>> x;
        xs.push_back(x);
    }


    sort(xs.begin(), xs.end());

    long minFuel = INT_MAX;

    for(vector<long>::iterator it=xs.begin(); it+k <= xs.end(); it++) {
         int fuel = getMinFuelReuqired(it, it+k-1);


         if(minFuel > fuel) {
             minFuel = fuel;
         }

    }
         cout << minFuel << endl;


    return 0;
}