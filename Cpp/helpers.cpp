#include<vector>
using namespace std;

template <class T>
void printPadded(vector<T> vec) {
	for(int i = 0; i < vec.size(); i++) {
		cout << std::setw (3) << vec[i] << " ";
	}
	cout << endl;
} 

template <class T>
void print(vector<T> vec) {
	for(int i = 0; i < vec.size(); i++) {
		cout << vec[i] << " ";
	}
	cout << endl;
} 

template <class T>
void print(stack<T> st) {
    for (std::stack<int> dump = st; !dump.empty(); dump.pop())
        std::cout << dump.top() << ' ';
        cout << endl;
}

template <class T>
void print(vector<vector<T>> vec) {

	for(int i = 0; i < vec.size(); i++) {
		for(int j = 0; j < vec[i].size(); j++) {
			cout << std::setw (3) << vec[i][j] << " ";
		}
		cout << endl;
	}
} 

template <class T>
void print(T arr[], int n) {
	for(int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;
} 


vector<vector<double>> getCopy(vector<vector<double>> vec) {
	vector<vector<double>> copy;
	for(int i = 0; i < vec.size(); i++) {
		vector<double> copyR = vec[i];

		copy.push_back(vec[i]);
	}

	return copy;
}


template <class T>
T lastEl(vector<T> vec) {
	if(vec.size() == 0) {
		return INT_MIN;
	}

	else return vec[vec.size()-1];
}


int getOrderOf(vector<int> scores, int score) {
	int order = 0;

	for(int i = 0; i < scores.size(); i++) {
		if(scores[i] <= score) {
			order++;
		}
	}

	return order;
}


int getSum(vector<int> vec) {
	int sum = 0;
	for(int i = 0; i < vec.size(); i++) {
		sum += vec[i];
	}

	return sum;
}


int getMaxIndex(vector<int> vec) {
	if(vec.size() == 0) {
		return -1;
	}

	int indexOfMax = 0;
	for(int i = 0; i < vec.size(); i++) {
		if(vec[indexOfMax] < vec[i]) {
			indexOfMax = i;
		}
	}

	return indexOfMax;
}


/*
usage: 
	void (*fn)();
	fn = &findPrimeNums;

	printTimes(fn);

*/

void printTimes(void (*fn)()) {

	auto start = std::chrono::high_resolution_clock::now();

	// Portion of code to be timed
	fn();
	// Record end time
	auto finish = std::chrono::high_resolution_clock::now();

	std::chrono::duration<double> elapsed = finish - start;	

	std::cout << " fn -> Elapsed time: " << elapsed.count() << " s\n";

}