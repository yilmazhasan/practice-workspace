#include <iostream>

using namespace std;

int main(){

    int n, t;
    cin >> n;

    int evens = 0;
    int odds = 0;

    for(int i = 0; i < n+5; i++) {
        cin >> t;
        if(t % 2 == 0) {
            evens++;
        } else {
            odds++;
        }
    }

    if(evens == 0 || odds == 0) {
        cout << 0 << endl;
    } else cout << 1 << endl;

	return 0;
}
