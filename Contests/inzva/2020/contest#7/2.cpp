#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<long> negatives;

long makeSmallestZero(vector<long> &v) {
    // long minElementIndex = std::min_element(v.begin(),v.end()) - v.begin();
    auto minElementIt = std::min_element(v.begin(),v.end());
    long minElement = *minElementIt;

    // v[minElementIndex] = 0;
    v.erase(minElementIt);
    return -1 * minElement;
}

int main(){

    long T, N, num;

    cin >> T;

    for(long i = 0; i < T; i++) {
        long long sum = 0;
        long count = 0;
        cin >> N;
        negatives.clear();
        for(long j = 0; j < N; j++) {
            cin >> num;
            if(num < 0) {
                negatives.push_back(num);
            }

            sum += num;

            if(sum < 0) {
                sum += makeSmallestZero(negatives);
                count++;
            }
        }
        cout << count << endl;
    }


	return 0;
}
