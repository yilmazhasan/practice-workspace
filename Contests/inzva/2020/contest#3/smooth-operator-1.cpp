#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;
template <class T>
void print(vector<vector<T>> vec) {

	for(int i = 0; i < vec.size(); i++) {
		for(int j = 0; j < vec[i].size(); j++) {
			cout <<  vec[i][j] << " ";
		}
		cout << endl;
	}
}

template <class T>
void print(vector<T> vec) {
	for(int i = 0; i < vec.size(); i++) {
		cout << vec[i] << " ";
	}
	cout << endl;
}

int getKth(vector<int> laps, int K) {
    int size = laps.size();
    int minLap = 0;
    sort(laps.begin(), laps.end());
    vector<int> rankings = {1};

    for(int i = 1; i < size; i++) {
        if(laps[i] == laps[i-1]) {
            rankings.push_back(rankings[i-1]);
        } else {
            rankings.push_back(i+1);
        }
    }

    size = rankings.size();
    for(int i = 0; i < size; i++) {
        if(K == rankings[i]) {
            if(i > 0) {
                minLap = laps[i-1]+1;
            } else {
                minLap = laps[0]-1;
            }
            break;
        } else if(K < rankings[i]) {
            minLap = -1;
        }
    }

    if(minLap == 0) {
        if(K < size) {
            minLap = -1;
        }
        else if(K == size) {
            if(rankings[size-1] == rankings[size-2]) {
                minLap = -1;
            } else {

            minLap = rankings[size-1];
            }
        }
         else if(K == size+1) {
            minLap = laps[size-1]+1;
        }
    }

    return minLap;
}

vector<int> getLapTimesOfSainz(vector<vector<int>> grid, int K) {
    vector<int> lapsCum(grid.size(), 0);

    int sainsTimesCum = 0;

    vector<int> laptimesOfSainz;

    int N = grid.size();
    int L = grid[0].size();
    for(int j = 0; j < L; j++) {
        for(int i = 0; i < N; i++) {
            lapsCum[i] += grid[i][j];
        }
        int minLapTimeForKth = getKth(lapsCum, K);
        if(minLapTimeForKth == -1) {
            return vector<int>();
        }
        laptimesOfSainz.push_back(minLapTimeForKth - sainsTimesCum);
        sainsTimesCum = minLapTimeForKth;
    }

    return laptimesOfSainz;
}

int main(){

    int N, L, K, t;
    vector<vector<int>> grid;

    cin >> N >> L >> K;

    for(int i = 0; i < N-1; i++) {
        vector<int> vec;
        for(int j = 0; j < L; j++) {
            cin >> t;
            vec.push_back(t);
        }
        grid.push_back(vec);

    }

    auto res = getLapTimesOfSainz(grid, K);

    if(res.size() == 0) {
        cout << -1 << endl;
    } else
    print(res);

	return 0;
}