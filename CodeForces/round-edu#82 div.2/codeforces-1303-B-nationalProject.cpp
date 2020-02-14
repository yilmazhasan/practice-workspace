/**
* https://codeforces.com/contest/1303/problem/B
* @author github.com/yilmazhasan
* 14 Feb 2020
**/

#include <iostream>
#include <string>

using namespace std;

long long getMinNumOfDays(long long highwayLength, long long goodDays, long long badDays) {
	long long halfOfHighway = highwayLength%2 == 0 ? highwayLength/2 : highwayLength/2 + 1;
	long long currentLengthOfHighWay = 0;

	long long countOfPeriod = halfOfHighway / goodDays;

	long long highQualityLength = countOfPeriod * goodDays;
	currentLengthOfHighWay = countOfPeriod * goodDays + (countOfPeriod - 1) * badDays;	// if countOfPeriod is zero then start with minus badDays, it will compansate in below if scope

	if(highQualityLength < halfOfHighway || currentLengthOfHighWay < highwayLength) {
		currentLengthOfHighWay += badDays;
		while(highQualityLength < halfOfHighway || currentLengthOfHighWay < highwayLength) {	// days should be at least highway length so that all highway is covered
			currentLengthOfHighWay++;
			highQualityLength++;
		}
	}

	return currentLengthOfHighWay;

}

int main(){

	long long numOfTest;
	long long highwayLength;
	long long goodDays;
	long long badDays;

	cin >> numOfTest;

	for(long long i = 0; i < numOfTest; i++) {
		cin >> highwayLength >> goodDays >> badDays;
		long long res = getMinNumOfDays(highwayLength, goodDays, badDays);
		cout << res << endl;

	}

	return 0;
}

