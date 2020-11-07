#include<iostream>
#include <numeric>
#include <algorithm>
#include <vector>
#include <math.h>
// Wrong answer on pretest 1
using namespace std;

template <class T>
void print(vector<T> vec) {
	for(int i = 0; i < vec.size(); i++) {
		cout << vec[i] << " ";
	}
	cout << endl;
} 
template <class T>
void print(vector<vector<T>> vec) {

	for(int i = 0; i < vec.size(); i++) {
		for(int j = 0; j < vec[i].size(); j++) {
			cout << vec[i][j] << " ";
		}
		cout << endl;
	}
} 

bool isPrime(int n) {
    int sqrtOfN = sqrt(n);
    for(int i = 2; i <= sqrtOfN; i++) {
        if (n %i == 0)
            return false;
    }

    if(n == 1) {
        return false;
    }

    return true;
}

int getAPrimeGreaterThan(int n) {
    for(int i = n+1; ;i++ ) {
        if(isPrime(i))
            return i;
    }

    return -1;
}

vector<int> findARow(int n) {
    vector<int> vec;
    int sum = 0;

    for(int i = 0; i < n-1; i++) {
        for(int j = 1; ; j++) {
            if(!isPrime(j)) {
                sum += j;
                vec.push_back(j);
                break;
            }
        }
    }

    for(int j = 1; ;j++)
    if(isPrime(j+sum)) {
        vec.push_back(j);

        break;
    }

    return vec;
}

void shiftToLeftByOne(vector<int> &aRow) {
    int first = aRow[0];
    for(int i = 1; i < aRow.size(); i++) {
        aRow[i-1] = aRow[i];
    }

    aRow[aRow.size()-1] = first;
}

vector<vector<int>> buildAMatrix(int n) {
    vector<vector<int>> vec;

    vector<int> aRow = findARow(n);

    for(int i = 0; i < n; i++) {
        vec.push_back(aRow);
        shiftToLeftByOne(aRow);
    }


    return vec;
}


int main(){

	int t;

	cin >> t;

	int n;
    for(int i = 0; i < t; i++) {
        cin >> n;

        auto vec = buildAMatrix(n);
        print(vec);

    }

	return 0;
}
