#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

string getTheMaxNum(int numOfSegments);
string getOnes(int num);

int main(){

	int numOfInput;
	int numOfSegments;

	cin >> numOfInput;
	vector<int> segments;// = new vector<int>();

	for(int i = 0; i < numOfInput; i++) {
		cin >> numOfSegments;
		segments.push_back(numOfSegments);
	}

	for(int i = 0; i < numOfInput; i++) {
		cout << getTheMaxNum(segments[i]) << endl;
	}

	return 0;
}

string getTheMaxNum(int numOfSegments) {

	int numOfOnes = numOfSegments / 2;
	int remainings = numOfSegments % 2;
	int lastDigit = -1;

	if(remainings == 1) {	// since there is no number consisting of one segment
		numOfOnes -= 1;
		lastDigit = 7; // which consists of 3 segments
	}

	string res = getOnes(numOfOnes);

	// for(int i = 0; i < numOfOnes; i++) {
	// 	res = res + "1";
	// }

	if(lastDigit == 7) {
		res = "7" + res;
	}

	if(res.size() > 0) {
		return res;
	}

	return "";
}

string getOnes(int num) {
	if(num == 0) {
		return "";
	}

	if(num == 1) {
		return "1";
	}

	string half = getOnes(num/2);

	return half + half + getOnes(num % 2);
}