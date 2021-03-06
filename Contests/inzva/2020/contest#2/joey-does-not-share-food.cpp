#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

// https://www.hackerrank.com/contests/inzva-algorithm-competition-league-3-contest-2/challenges/joey-does-not-share-food

bool isThereAnyOverlap(vector<int> froms, vector<int> tos, int from, int to) {
    int size = tos.size();
    for(int i = 0; i < size; i++) {
        if((from >= froms[i] && from <= tos[i]) || (to >= froms[i] && to <= tos[i]) || (froms[i] >= from && froms[i] <= to) || (tos[i] >= from && tos[i] <= to)) {
            return true;
        }
    }

    return false;
}

bool isItPossible(vector<int> a, vector<int> b) {
    bool possible = true;
    int size = a.size();
    int startDay;
    vector<int> startDays;
    for(int i = 0; i < size; i++) {
        startDay = a[i] - b[i] + 1;
        startDays.push_back(startDay);
    }

    int endDay = INT_MIN;
    vector<int> endDays;
    for(int i = 0; i < size; i++) {
        endDay = startDays[i] + b[i] - 1;
        if(isThereAnyOverlap(startDays, endDays, startDays[i], endDay)) {
            return false;
        }

        endDays.push_back(endDay);
    }

    return possible;
}

int main(){

    int n, t;
    vector<int> as;
    vector<int> bs;

    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> t;
        as.push_back(t);
    }

    for(int i = 0; i < n; i++) {
        cin >> t;
        bs.push_back(t);
    }

    cout << (isItPossible(as, bs) ? "YES" : "NO") << endl;

	return 0;
}