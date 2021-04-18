#include <iostream>
#include <vector>
#include <algorithm>    // std::find
#include <climits>
#include <cmath>

using namespace std;


bool isInside(vector<long> &nums, long l) {
     std::vector<long>::iterator it = find (nums.begin(), nums.end(), l);

    if(it != nums.end()) {
        return true;
    }

    return false;
}

long getLowestNineSum(vector<long> all) {

    vector<long> lowest_nine_inds = {};
    vector<long> used(all.size(), false);
    long sum = 0;
    long lowest = LONG_MAX;

    int allSize = all.size();
    for(int j = 0; j < 9; j++) {
        long lowestInd = 0;
        while(used[lowestInd]) {
            lowestInd++;
        }

        for(int i = 1; i < allSize; i++) {
            if(!used[i]) {
                if(all[lowestInd] > all[i]) {
                    lowestInd = i;
                }
            }
        }

        used[lowestInd] = true;
        sum += all[lowestInd];
        lowest_nine_inds.push_back(lowestInd);
    }

    return sum;

}

int main(){
    int n, ni;
    vector<long> all;

    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> ni;
        all.push_back(ni);
    }

    cout << getLowestNineSum(all) << endl;

	return 0;
}
