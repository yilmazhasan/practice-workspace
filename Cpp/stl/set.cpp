#include <iostream>
#include<set>
#include<string>

/*Set is a sorted array by default*/

using namespace std;

template <class T>
void print(set<T> mySet) {
    for(auto it = mySet.begin(); it != mySet.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

int main(){

    set<int> mySet;
    mySet.insert(2);
    mySet.insert(3);
    mySet.insert(1);
    print(mySet);

    set<string> mySet2;
    mySet2.insert("yilmaz");
    mySet2.insert("ali");
    mySet2.insert("hasan");
    print(mySet2);

	return 0;
}