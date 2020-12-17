#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int getMin(int a, int b, int c) {
    int arr[] = {a, b, c};
    auto min = min_element(arr, arr+3);

    return *min;
}

bool isItPossible(int f, int s, int t) {
    int sum = f + s + t;

    int rem = sum % 9;

    if(rem == 0) {
        int div = sum / 9;
        int min = getMin(f, s, t);
        // cout << div << " " << min << endl;
        if (div <= min) {
            return true;
        } 
    }

    return false;
}

int main() {

    int f, s, t, n;

    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> f >> s >> t ;

        if(isItPossible(f, s, t)) {
            cout << "YES" << endl; 
        } else {
            cout << "NO" << endl; 
        }
    }

    return 0;
}