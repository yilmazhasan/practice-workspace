#include <iostream>
#include <vector>
#include <climits>

using namespace std;

long getHappiness(vector<long> series) {
    long totalH = 0;

    bool isCurrentLecture = series[1] < 0;
    bool isPrevLecture = series[0] < 0;
    long maxH = series[0];

    for(int i = 1; i < series.size(); i++) {
        isCurrentLecture = series[i] < 0;

        if((isPrevLecture && !isCurrentLecture) || (!isPrevLecture && isCurrentLecture)) {
            totalH += maxH;
            maxH = INT_MIN;
        }

        if(maxH < series[i]) {
            maxH = series[i];
        }

        isPrevLecture = isCurrentLecture;
    }

    totalH += maxH;

    return totalH;
}

int main(){

    int n;
    long h;
    vector<long> series;
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> h;
        series.push_back(h);
    }
    cout << getHappiness(series) << endl;

	return 0;
}