#include<iostream>
#include<vector>
using namespace std;

int getMinStartDay(long long P, int D) {
    int week = 28;
    P %= week;

    if(P == 0) {
        return D;
    }

    int days[] = {0, 1, 2, 3, 4, 5, 6, 7, 1, 2, 3, 4, 5, 6};

    for(int i = 1; i <= 7; i++) {
        int total = 0;
        for(int j = i; j < 14; j++) {
            if(total < P && total + days[j] >= P && days[j] == D) {
                return i;
            }

            total += days[j];
        }
    }

    return 0;
}

int main() {

    int T, D;
    long long P;
    
    cin >> T;

    for(int i = 0; i < T; i++) {
        cin >> P >> D;
        int res = getMinStartDay(P, D);
        if(res > 0 ) {
            cout << res << endl;
        } else {
            cout << "IMPOSSIBLE" << endl;
        }
    }

    return 0;
}