#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

map<long long, long long> multipliers;

void factorize(long long N) {
    if(N == 1) {
        multipliers[1] = 1;
    }
    for(long long i = 2; i <= N; i++) {
        if(N == 1) {
            return;
        }
        while(N%i == 0) {
            N = N/i;
            multipliers[i] += 1;
        }
    }
}

template <class T1, class T2>
long long findBaseOfNumber(map<T1, T2> myMap) {
    long long base = 1;
	for(auto it = myMap.begin(); it != myMap.end(); ++it) {
		base *= it->first;
	}

    return base;
}

long long findNearestNumberPowerOf2(long long n) {
    if(n == 1) {
        return 0;
    }

    return n % 2 == 0 ? (1 + findNearestNumberPowerOf2(n/2)) : (2 + findNearestNumberPowerOf2(n/2));
}

int main(){
    long long N;

    cin >> N;

    factorize(N);

    cout << findBaseOfNumber(multipliers) << " ";

    vector<long long> powers;

	for(auto it = multipliers.begin(); it != multipliers.end(); ++it) {
        powers.push_back(it->second);
	}

    auto it = max_element(powers.begin(), powers.end());

    int nearestPowerOf2 = findNearestNumberPowerOf2(*it);
    int maxPower = pow(2, nearestPowerOf2);
    int willMultiply  = 0;

    for(int i = 0; i < powers.size(); i++) {
        if(powers[i] != maxPower) {
            willMultiply = 1;
        }
    }

    cout << willMultiply + nearestPowerOf2 << endl;

	return 0;
}
