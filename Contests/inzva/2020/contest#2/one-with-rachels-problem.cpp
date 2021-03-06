#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

long maxRaise(long n) {


    if(n % 2 == 0) {
        return n/2;
    }

    else return (n-1) / 2;
}

int main(){

    long n;
    cin >> n;
    cout << maxRaise(n) << endl;

	return 0;
}