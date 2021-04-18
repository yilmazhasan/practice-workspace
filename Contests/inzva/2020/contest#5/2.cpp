#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <climits>

using namespace std;


queue<int> cars;


template <class T>
void print(queue<T> Q) {
	while(!Q.empty()){
		cout<<" "<<Q.front();
		Q.pop();
	}

	cout<<endl;
}


void removeOldestCar() {
    cars.pop();
}

void addNewCar(int car) {
    cars.push(car);
}

template<class T>
int getMin(queue<T> Q) {
    T minEl = INT_MAX;
	while(!Q.empty()){
        if(minEl > Q.front()) {
    		minEl = Q.front();
        }
		Q.pop();
	}

    return minEl;
}

template<class T>
int getMax(queue<T> Q) {
    T maxEl = INT_MIN;
	while(!Q.empty()){
        if(maxEl < Q.front()) {
    		maxEl = Q.front();
        }
		Q.pop();
	}

    return maxEl;
}

int main(){

    int q, op, car;
    cin >> q;
    int maxScore = -1;
    int minEl = 0;
    int maxEl = 0;

    for(int i = 0; i < q; i++) {
        cin >> op;

        if(op == 1) {
            cin >> car;
            addNewCar(car);
        } else if(op == 2) {
            removeOldestCar();
        }

        minEl = getMin(cars);
        maxEl = getMax(cars);

        if(maxEl - minEl > maxScore) {
            maxScore = maxEl - minEl;
        }

    }

    cout << maxScore <<  endl;

	return 0;
}
