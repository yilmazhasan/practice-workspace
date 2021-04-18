#include <iostream>
#include <vector>
#include <map>

using namespace std;

template <class T>
map<T, int> getFreq(vector<T> vec) {
    map<T, int> myMap;
    int size = vec.size();
    for(int i = 0; i < vec.size(); i++) {
        myMap[vec[i]] += 1;
    }

    return myMap;
}

int getCombination2(int n) {

    return n * (n-1) / 2;
}

int howManySubList(vector<long> all) {

    map<long, int> myMap = getFreq(all);

    int subListCount = 0;

	for(auto it = myMap.begin(); it != myMap.end(); ++it) {
        subListCount += it->second;

        if(it->second > 1) {
            subListCount += getCombination2(it->second);
        }
	}

    return subListCount;
}

int main(){
    int n, ai;
    vector<long> all;

    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> ai;
        all.push_back(ai);
    }

    cout << howManySubList(all) << endl;

	return 0;
}
