/**
* https://codeforces.com/contest/1380/problem/C
* @author github.com/yilmazhasan
* 7/12/2020
**/

#include <iostream>
#include <algorithm>
#include <vector>
#include<bits/stdc++.h> 
#include <cstdlib>

using namespace std;

// solution of the problem
void createTheTeams(vector<int> vec, int x);

// solutions for similar problem
void makeTeamsOfAnyPeople (vector<int> &vec, vector<int> &team, int teamSum, int x, vector<vector<int>> &allTeams);
void makeTeamsOf2People (vector<int> &vec, int x);


void createTheTeams(vector<int> vec, int x) {
	sort(vec.begin(), vec.end());

	vector<vector<int>> teams;
	vector<int> team;

	int teamSize = 0;
	for(int i = vec.size()-1; i >= 0; i-- ) {
		team.push_back(vec[i]);
		teamSize++;
		if(teamSize * vec[i] >= x) {
			teams.push_back(team);
			team.clear();
			teamSize = 0;
			continue;
		}
	}

	cout << teams.size() << endl;

	// print(teams);

}

// create teams whose members ai sum is not less than x
void createTheTeamsByAiSum(vector<int> vec, int x) {
	int numOfTeams = 0;
	vector<int> indsToDel;
	for(int i = 0; i < vec.size(); i++) {
		if(vec[i] >= x) {
			numOfTeams++;
			indsToDel.push_back(i);
		}
	}

	vector<int> team;
	vector<vector<int>> allTeams;
	sort(vec.begin(), vec.end());
	// makeTeamsOf2People(vec, x);
	makeTeamsOfAnyPeople(vec, team, 0, x, allTeams) ;
}

// teams of max 2 poeple, those's ai's sum is not less than x
void makeTeamsOf2People(vector<int> &vec, int x) {

	int start = 0;
	int end = vec.size()-1;

	vector<pair<int, int>> teams;

	while(start < end) {
		if(vec[start] + vec[end] >= x) {
			teams.push_back(make_pair(vec[start], vec[end]));
			start++;
			end--;
		} else {
			start++;
		}
	}

	cout << teams.size() << endl;

	cout << "all teams: " << teams.size() << endl;
	for(int i = 0; i < teams.size(); i++) {
		cout << "A team : " ;
		cout << teams[i].first << " " << teams[i].second << endl;
	}
}

// teams of any people, those's ai's sum is not less than x
void makeTeamsOfAnyPeople(vector<int> &vec, vector<int> &team, int teamSum, int x, vector<vector<int>> &allTeams) {

	if(vec.size() == 0) {
		cout << allTeams.size() << endl;
		cout << "Teams: " << endl;
		print(allTeams);
		return;
	}

	if(teamSum >= x) {
		if(team.size() < 2) {
			team.push_back(vec[0]);
			teamSum += vec[0];
			vec.erase(vec.begin());
		}

		// cout << "One team with sum " << teamSum << endl;
		// print(team);
		allTeams.push_back(team);
		teamSum = 0;
		team.clear();
		makeTeamsOfAnyPeople(vec, team, teamSum, x, allTeams);
		return;
	}

	int minNeeded = x - teamSum;
	int indOfDiffToTake = 0;
	int diff = 0;
	int diffToTake = INT_MAX;

	for(int i = vec.size() - 1; i >= 0; i--) {
		
		diff = minNeeded - vec[i];
		
		if(diff == 0){
			indOfDiffToTake = i;
			break;
		} else {
			// if diff is negative, take max else min
			int absDiff = abs(diff);
			if(diffToTake > absDiff) {
				diffToTake = absDiff;
				indOfDiffToTake = i;
			} 
		}
		
	}

	if(indOfDiffToTake < vec.size()) {

		team.push_back(vec[indOfDiffToTake]);
		teamSum += vec[indOfDiffToTake];

		vec.erase(vec.begin() + indOfDiffToTake);
	} else {
		// cout <<"indOfDiffToTake is less " << indOfDiffToTake << " size " << vec.size() << endl;
	}

	makeTeamsOfAnyPeople(vec, team, teamSum, x, allTeams);
}

int main(){

	int numOfTest;
	int numOfNums;
	int x;
	vector<int> nums;
	int t;

	cin >> numOfTest;

	for(int i = 0; i < numOfTest; i++) {
		cin >> numOfNums >> x;
		nums.clear();

		for(int j = 0; j < numOfNums; j++) {
			cin >> t;
			nums.push_back(t);
		}
		createTheTeamsByAiSum(nums, x);
	}

	return 0;
}

