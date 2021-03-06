#include <iostream>
#include <string>

using namespace std;

int main(){

    char c;

	while(cin >> c) {
        // cout << (char)(c-1);
        if(c == 'A') {
            cout << 'Z';
        } else {
            cout << (char)(c-1);
        }
	}
    cout << endl;
	return 0;
}