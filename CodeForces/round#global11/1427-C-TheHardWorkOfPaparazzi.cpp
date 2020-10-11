#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<climits>

using namespace std;

int x00 = 1;
int y00 = 1;
// Time limit exceeded on test 5

// vector<bool> isPassed;
vector<int> unPassedInds;

template <class T>
void print(vector<vector<T>> &vec) {

	for(int i = 0; i < vec.size(); i++) {
		for(int j = 0; j < vec[i].size(); j++) {
			cout  << vec[i][j] << " ";
		}
		cout << endl;
	}
} 

int nearestWhereCanIGo(vector<vector<int>> &times, int &currentTime) {
	int dist = 0;
	int bestIndex = -1;
	int minT = INT_MAX;
	int timeWillBe = INT_MAX;
	// for(int i = 0; i < size; i++) {
	int size = unPassedInds.size();
	int i = 0;
	for(int j = 0; j < size; j++) {
		i = unPassedInds[j];
		// if(isPassed[i]) {
		// 	continue;
		// }
		dist = abs(x00-times[i][1]) + abs(y00-times[i][2]);
		int iCanReachAt = currentTime + dist;

		if( iCanReachAt <= times[i][0]) {
			int t = times[i][0]-iCanReachAt;
			if(minT >  t) {
				minT = t;
				bestIndex = i;
			}
			timeWillBe = times[i][0];
		}
	}
	return bestIndex;
}

void removeFrom(int index,vector<int> &unPassedInds) {
	for(int i = 0; i < unPassedInds.size(); i++) {
		if(index == unPassedInds[i]) {
			unPassedInds.erase(unPassedInds.begin()+i);
			return;
		}
	}
}

int goCelebrity(vector<vector<int>> & times) {
	
	int tRequired = abs(x00- times[0][1]) + abs(y00- times[0][2]);
	if(times.size() == 1) {
		int tCelebrity = times[0][0];
		if(tRequired > tCelebrity) {
			return 0;
		} else 
		return 1;
	}

	int count = 0;
	int currentT = 0;

	for(int i = 0; i < times.size(); i++) {
		vector<int> v = times[i];
		int index = nearestWhereCanIGo(times, currentT);
		if(index >= 0) {
			currentT += tRequired;
			if(currentT < times[index][0]) {
				currentT = times[index][0];
			}
			x00 = times[index][1];
			y00 = times[index][2];
			// isPassed[index] = true;
			removeFrom(index, unPassedInds);
			count++;
		}
	}

	return count;
}


int main(){

	int r, n;
	int ti, xi, yi;

	vector<vector<int>> times;

	cin >> r >> n;
	// isPassed.resize(n);

	for(int i = 0; i < n; i++) {
		cin >> ti >> xi >> yi;
		vector<int> v = {ti, xi, yi};
		times.push_back(v);
		unPassedInds.push_back(i);
	}

	cout << goCelebrity(times) << endl; 

	return 0;
}
