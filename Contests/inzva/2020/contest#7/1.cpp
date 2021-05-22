#include <iostream>
#include <vector>
#include <string>

using namespace std;

char getNextCharInd(long ind, string str) {

    ind++;
    return ind % str.size();
}

bool doesWordInclude (string strs, string search) {
    char currentCharInd = 0;

    long size = strs.size();
    for(long i = 0; i < size; i++) {
        if(search[currentCharInd] == strs[i]) {
            currentCharInd = getNextCharInd(currentCharInd, search);
            if(currentCharInd == 0) {
                return true;
            }
        }
    }

    return false;
}

int howManyWordIncludes(vector<string> strs, string search) {
    int count = 0;
    int size = strs.size();
    for(int i = 0; i < size; i++) {
        if(doesWordInclude(strs[i], search)) {
            count++;
        }
    }

    return count;
}

int main(){

    long N;
    cin >> N;
    string str;
    vector<string> strs;

    for(long i = 0; i < N; i++) {
        cin >> str;
        strs.push_back(str);
    }

    cout << howManyWordIncludes(strs, "eren") << endl;

	return 0;
}
