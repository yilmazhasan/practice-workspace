/**
* http://codeforces.com/contest/1417/problem/C
* @author github.com/yilmazhasan
**/

// Time limit exceeded on test 2

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;


// map subsequents by size
map<int, vector<int>> subsequentInds;


void printVec(vector<int> vec) {

	for(int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << " ";
	}
	
	cout << endl;	
}

void printMap(map<int, int> freqs) {

	for(auto it = freqs.begin(); it != freqs.end(); it++)
	{
		cout << it->first << " " << it->second << endl;
		
	}
	
}

void print(map<int, vector<int>> m) {
	
	
	for(auto it = m.begin(); it != m.end(); it++)
	{
		cout << "--- " << it->first << " --- "<< endl;
		printVec(it->second);
		cout << "---" << endl;
	}
	
}


void prepareSubsequentInds(int totalSize) {
	
	for(int size = 1; size <= totalSize; size++) {
		
		int end = size-1;
		while( end < totalSize ) {
			subsequentInds[size].push_back(end);
			end += 1;
		}
		
		if(end >= totalSize) {
			if(subsequentInds[size][subsequentInds[size].size()-1] != totalSize-1) {
				subsequentInds[size].push_back(totalSize-1);
			}
		}
		
	}
}

bool doesSubsequentFits(vector<int> &subsequentToCheck, int subSequentSize) {
	vector<int> container = subsequentInds[subSequentSize];
		

	int i = 0, j = 0;
	for(; i < container.size() && j < subsequentToCheck.size();) {
		
		if(subsequentToCheck[j] <= container[i] && subsequentToCheck[j] > container[i]-subSequentSize) {
			
			i++;
		} else {
			j++;
		}
	}
	
	if(i == container.size()-1 && j >= subsequentToCheck.size()) {
		return false;
	}
	
	if(i == container.size()-1) {
		// recheck last elements
		if(subsequentToCheck[j] <= container[i] || subsequentToCheck[j] >= container[i]-subSequentSize) {
			return true;
		} 
		
		return false;
	} else if(i < container.size()-1) {
		return false;
	}
		
	return true;
	
}

int getMinElement(map<int, vector<int>> &elIndices, int subsequentSize) {
	int el = -1;
	for(auto it = elIndices.begin(); it != elIndices.end(); it++)
	{
		if(doesSubsequentFits(it->second, subsequentSize)) {
			return it->first;
		}
	}	
	
	return -1;
}

map<int, vector<int>> getIndicesOfElements(vector<int> &vec) {
	
	map <int, vector<int>> m;
	
	for(int i = 0; i < vec.size(); i++) {
		
		m[vec[i]].push_back(i);
	}
		
	return m;
}

vector<int> getKAmazingNums(vector<int> &vec) {
	auto indices = getIndicesOfElements(vec);
	int minEl = -1;
	vector<int> resVec;
	for(int size = 1; size <= vec.size(); size++) {
		minEl = getMinElement(indices, size);
		resVec.push_back(minEl);
	}
	
	return resVec;
	
}

int main(){

	int numOfInput;
	int numOfNums;
	int d;
	vector<int> nums;


	cin >> numOfInput;

	for(int i = 0; i < numOfInput; i++) {
		cin >> numOfNums;
		nums.clear();
		subsequentInds.clear();
		for(int j = 0; j < numOfNums; j++) {
			cin >> d;

			nums.push_back(d);
		}
		prepareSubsequentInds(nums.size());
		printVec(getKAmazingNums(nums));
	}

	return 0;
}