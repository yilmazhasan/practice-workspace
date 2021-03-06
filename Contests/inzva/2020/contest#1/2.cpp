#include <iostream>
#include <vector>
#include <algorithm>
#include<map>

using namespace std;
template <class T>
void print(vector<T> vec) {
	for(int i = 0; i < vec.size(); i++) {
		cout << vec[i] << " ";
	}
	cout << endl;
}

bool isItTriangle(int a, int b, int c) {
    if(a > abs(b-c) && a < b+c) {
        return true;
    }

    else return false;
}


int howManyDifferentTriangle (vector<int> logs) {
    sort(logs.begin(), logs.end());
	// map<string, bool> triangleMap;
    int triangleCount = 0;
    int size = logs.size();
    for(int i = 0; i < size; i++) {
        for(int j = i+1; j < size; j++) {
            for(int k = j+1; k < size; k++) {
                // string key = to_string(logs[i]) + "-" + to_string(logs[j]) + "-" + to_string(logs[k]);
                // if(triangleMap[key]) {
                //     continue;
                // }

                if(isItTriangle(logs[i], logs[j], logs[k])) {
                    triangleCount++;
                }
                // triangleMap[key] = true;
            }
        }
    }


    return triangleCount;
}

int main(){

    int n, l;
    vector<int> logs;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> l;
        logs.push_back(l);
    }

    cout << howManyDifferentTriangle(logs) << endl;


	return 0;
}