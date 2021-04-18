#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

long findMinPossible(long n, long k) {

    // base cases
    if(k == 1) {
        return 1;
    }

    if(n == k) {
        return 1;
    }

    if(n % k == 0) {
        return 1;
    }

    if(n > k) {
        return 2;   // all 1, m times 2, (n+m) -> kx, x-> ceil(n/k)
    }

    if(n < k) {
        return ceil((double)k / (double)n);
    }

    return 0;
}

int main(){

    long n, k;
    cin >> n >> k;

    cout << findMinPossible(n, k) << endl;

	return 0;
}
