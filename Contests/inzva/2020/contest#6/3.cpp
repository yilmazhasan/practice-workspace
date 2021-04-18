#include <iostream>
#include <cmath>
#include <climits>
#include <map>
#include <vector>

using namespace std;


int main(){

    int N;
    long long ai;

    long needed = -1;
    long elde = 0;
    long digit = -1;

    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> ai;

        while(digit != ai) {
            if(elde % 2 == 0) {
                needed++;
            }

            elde /= 2;
            digit++;
        }

        elde += 1;
    }

    while(elde > 0) {
        if(elde % 2 == 0) {
            needed++;
        }

        elde /= 2;
        digit++;
    }


    cout << needed << endl;

	return 0;
}
