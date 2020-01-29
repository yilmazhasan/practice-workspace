#include<iostream>
#include <algorithm>

using namespace std;

int main(){

	int ar[3];

	cin >> ar[0] >> ar[1] >> ar[2];

	int min, mid, max;

	std::sort(ar, ar+3);

	min = ar[0];
	mid = ar[1];
	max = ar[2];


	int diff = max - mid - min;

	if(diff < 0)
		cout << 0 << endl;

	else{
		cout << diff + 1 << endl;
	}

	return 0;
}
