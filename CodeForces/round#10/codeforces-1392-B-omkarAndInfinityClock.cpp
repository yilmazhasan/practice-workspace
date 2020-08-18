/**
* https://codeforces.com/contest/1392/problem/B
* @author github.com/yilmazhasan
* 8/17/2020
**/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include<bits/stdc++.h> 

using namespace std;

template <class T>
void print(vector<T> vec) {
	for(int i = 0; i < vec.size(); i++) {
		cout << vec[i] << " ";
	}
	cout << endl;
} 

template<class ForwardIt, class Compare>
ForwardIt min_element(ForwardIt first, ForwardIt last, Compare comp)
{
    if (first == last) return last;
 
    ForwardIt smallest = first;
    ++first;
    for (; first != last; ++first) {
        if (comp(*first, *smallest)) {
            smallest = first;
        }
    }
    return smallest;
}

template<class ForwardIt, class Compare>
ForwardIt max_element(ForwardIt first, ForwardIt last, Compare comp)
{
    if (first == last) return last;
 
    ForwardIt biggest = first;
    ++first;
    for (; first != last; ++first) {
        if (*first > *biggest) {
            biggest = first;
        }
    }
    return biggest;
}

void applyOperations(vector<int> vec, unsigned long long k) {

    if(k == 0) {
        print (vec);
    } else {
        int min = *min_element(vec.begin(), vec.end());
        int max = *max_element(vec.begin(), vec.end());
        if(k %2 == 1) {
            for(int i = 0; i < vec.size(); i++) {
                vec[i] = max - vec[i];
            }
        } else {
            for(int i = 0; i < vec.size(); i++) {
                vec[i] = vec[i] - min;
            }

        }
    } 
    print (vec);

}

int main(){

	int numOfTest;
	int n;
	unsigned long long k;
	int t;
	vector<int> p;


	cin >> numOfTest;

	for(int i = 0; i < numOfTest; i++) {
		cin >> n >> k;
		p.clear();
		for(int j = 0; j < n; j++) {
			cin >> t;
			p.push_back(t);
		}

        applyOperations(p, k);

	}

	return 0;
}

