#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;
string reverseString(string str, int start, int end);

bool equilizingTwoString(string str1, string str2) {

	int diffStart = -1;
	int diffEnd = -1;
	vector <int> diffStartVec;
	vector <int> diffEndVec;
	for (int i = 0; i < str1.size(); i++) {
		if (str1[i] != str2[i]) {
			diffStart = i;
			while (i < str1.size() && str1[i] != str2[i]) {
				i++;
			}

			diffEnd = i;
		}

		if (diffStart != -1) {
			diffStartVec.push_back(diffStart);
			diffStart = -1;
		}

		if (diffEnd != -1) {
			diffEndVec.push_back(diffEnd);
			diffEnd = -1;
		}
	}

	string reversedOfStr2 = str2;
	// Reverse all in str2, assuming there may be more than two diff substr
	for (int i = 0; i < diffStartVec.size(); i++) {
		reversedOfStr2 = reverseString(str2, diffStartVec[i], diffEndVec[i]);
	}
	
	for (int i = 0; i < diffStartVec.size(); i++)
	{
		cout << diffStartVec[i] << " ";
		cout << diffEndVec[i] << " ";
	}

	if (str1 == reversedOfStr2) {
		return true;
	}
	else {
		cout << reversedOfStr2 << endl;
		return false;
	}


	return false;
}


string reverseString(string str, int start, int end) {

	// char temp;
	// while (start != end) {
	// 	temp = str[start];
	// 	str[start] = str[end];
	// 	str[end] = temp;
	// 	start++;
	// 	end--;
	// }

	for (int i = start; i < end; i++)
	{
		swap(str[i], str[end-1]);
		end--;
	}
	return str;
}


int main(){

    int number_of_test_case;
    int length;
    string string1;
    string string2;

	cin >> number_of_test_case;

	for (int i = 0; i < number_of_test_case; i++) {
		cin >> length;
		cin >> string1;
		cin >> string2;
		if(equilizingTwoString(string1, string2))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}

	return 0;
}
