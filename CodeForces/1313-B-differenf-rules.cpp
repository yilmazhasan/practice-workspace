/**
* https://codeforces.com/contest/1313/problem/B
* @author github.com/yilmazhasan
* 23 Feb 2020
**/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
 
#include <bits/stdc++.h> 

using namespace std;

int getWorstPlace(int round1Score, int round2Score, int numOfParticipants) {

	vector<bool> round1Scores(numOfParticipants+1);
	vector<bool> round2Scores(numOfParticipants+1);

	int lessOrEqualScoreCount = 0;	

	// start current+1, to make all less or equal
	for(int sumScore = round1Score + round2Score; sumScore >= 2; sumScore--) {

		for(int i = 1; i <= numOfParticipants; i++) {
			if(sumScore-i <= numOfParticipants && sumScore-i >= 1 && !round1Scores[i] && !round2Scores[sumScore-i] ) {
				round1Scores[i] = true;
				round2Scores[sumScore-i] = true;
				lessOrEqualScoreCount++;
			}
		}

	}

	return lessOrEqualScoreCount;	// since place is the num of scores equal or less than tha
}

int getBestPlace(int round1Score, int round2Score, int numOfParticipants) {

	vector<bool> round1Scores(numOfParticipants+1);
	vector<bool> round2Scores(numOfParticipants+1);

	round1Scores[round1Score] = true;
	round2Scores[round2Score] = true;

	int greaterScoreCount = 0;	

	// start current+1, to make all higher
	for(int sumScore = round1Score + round2Score + 1; sumScore <= numOfParticipants+numOfParticipants; sumScore++) {

		for(int i = 1; i <= numOfParticipants; i++) {
			if(sumScore-i <= numOfParticipants && sumScore-i >= 1 && !round1Scores[i] && !round2Scores[sumScore-i] ) {
				round1Scores[i] = true;
				round2Scores[sumScore-i] = true;
				greaterScoreCount++;
			}
		}

	}

	return numOfParticipants - greaterScoreCount;	// since place is the num of scores equal or less than that
}

int main(){

	int numOfTest;
	int numOfParticipants;	// which is the place
	int round1Score;	// which is the place
	int round2Score;
	int bestPlace = -1;
	int worstPlace = -1;

	cin >> numOfTest;

	for(int i = 0; i < numOfTest; i++) {
		cin >> numOfParticipants >> round1Score >> round2Score;
		cout << getBestPlace(round1Score, round2Score, numOfParticipants) << " ";
		cout << getWorstPlace(round1Score, round2Score, numOfParticipants) << endl;
	}

	return 0;
}