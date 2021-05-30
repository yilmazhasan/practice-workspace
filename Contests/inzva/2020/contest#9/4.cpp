#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool isAnyForXorZero(vector<int> seq) {
    vector<int> xors;
    int size = seq.size();
    for(int i = 0; i < size; i++) {
        for(int j = i + 1; j < size; j++) {
            for(int k = j + 1; k < size; k++) {
                for(int l = k + 1; l < size; l++) {
                    if((seq[i] ^ seq[j] ^ seq[k] ^ seq[l]) == 0) {
                        return true;
                    }
                }
            }
        }
    }

    return false;
}

int main() {

    int n, si;
    long sum = 0;
    cin >> n;
    vector<int> seq;

    for(int i = 0; i < n; i++) {
        cin >> si;
        seq.push_back(si);
    }

    cout << (isAnyForXorZero(seq) ? "Yes" : "No") << endl;

    return 0;
}