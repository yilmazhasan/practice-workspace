#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool isPrime(long s) {
    long sqrtS = sqrt(s);
    for(int i = 2; i <= sqrtS; i++) {
        if(s % i == 0) {
            return false;
        }
    }

    return true;
}

bool isComposite(long s) {
    if(s == 1) {
        return false;
    }

    return !isPrime(s);
}

bool isSequenceComposite(vector<long> seq) {
    if(seq.size() == 2) {
        if(!isComposite(seq[0]) && !isComposite(seq[1]) && isPrime(seq[0] + seq[1])) {
            return false;
        } else {
            return true;
        }
    } else if(seq.size() == 3) {
        if(seq[0] == 1 && seq[0] == 1 && seq[0] == 1) {
            return false;
        } else {
            return true;
        }
    }

    return true;
}

int main(){

    int n;
    long si;
    long sum = 0;
    cin >> n;
    vector<long> seq;

    if (n == 1){
        cin >> si;
        cout << (isComposite(si) ? "Yes" : "No") << endl;
    } else {
        for(int i = 0; i < n; i++) {
            cin >> si;
            seq.push_back(si);
        }
        cout << (isSequenceComposite(seq) ? "Yes" : "No") << endl;
    }

	return 0;
}
