#include <iostream>
#include <string>

using namespace std;

bool canEnd(int a, int b) {

    int rem = (a + b) % 3;

    if(rem > 0) {
        return false;
    }

    int div = (a+b) / 3;
    if(div > a || div > b) {
        return false;
    }

    return true;

}

int main(){

    int t, a, b;
    cin >> t;

    for(int i = 0; i < t; i++) {
        cin >> a >> b;
        cout << (canEnd(a, b) ? "YES" : "NO") << endl;
    }

	return 0;
}