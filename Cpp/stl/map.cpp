#include <iostream>
#include <map>

using namespace std;

template <class T1, class T2>
void print(map<T1, T2> myMap) {
	for(typename map<T1,T2>::iterator it = myMap.begin(); it != myMap.end(); ++it) {
		cout << it->first << " : " << it->second << endl;
	}
}

int main(){

	map<int, bool> m;

	m[0] = true;
	m[3] = true;

	print(m);
	cout << 0 << " " << m[0] << endl;
	cout << 2 << " " << m[2] << endl;
	cout << 3 << " " << m[3] << endl;
	print(m);

	return 0;
}
