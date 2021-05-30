#include <iostream>

using namespace std;

int main(){
    int n, ai, lastPage;

    cin >> n;
    lastPage = 0;

    for(int i = 0; i < n; i++) {
        cin >> ai;
        if(lastPage < ai) {
            lastPage = ai;
        }
    }

    cout << lastPage << endl;

	return 0;
}
