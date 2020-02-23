/**
* https://codeforces.com/contest/1315/problem/A
* @author github.com/yilmazhasan
* 23 Feb 2020
**/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
 
using namespace std;

int getMaxAreaAtUpOfAPixel(int widthSize, int heightSize, int row, int col) {
	return widthSize * row;
}

int getMaxAreaAtBelowOfAPixel(int widthSize, int heightSize, int row, int col) {
	return widthSize * (heightSize - row - 1);
}

int getMaxAreaAtRightOfAPixel(int widthSize, int heightSize, int row, int col) {
	return heightSize * (widthSize - col - 1);
}

int getMaxAreaAtLeftOfAPixel(int widthSize, int heightSize, int row, int col) {
	return heightSize * col;
}

int getMaxAreaDiscardingAPixel(int widthSize, int heightSize, int pixelRow, int pixelCol) {
	vector<int> areas;
	int area1 = getMaxAreaAtBelowOfAPixel(widthSize, heightSize, pixelRow, pixelCol);
	// areas.push_back(area1);
	int area2 = getMaxAreaAtUpOfAPixel(widthSize, heightSize, pixelRow, pixelCol);
	// areas.push_back(area2);
	int area3 = getMaxAreaAtRightOfAPixel(widthSize, heightSize, pixelRow, pixelCol);
	// areas.push_back(getMaxAreaAtRightOfAPixel(widthSize, heightSize, pixelRow, pixelCol));
	int area4 = getMaxAreaAtLeftOfAPixel(widthSize, heightSize, pixelRow, pixelCol);
	// areas.push_back(getMaxAreaAtLeftOfAPixel(widthSize, heightSize, pixelRow, pixelCol));

	// return std::max(areas.begin(), areas.end());

	return std::max(max(max(area4, area1), area2), area3);

}

int main(){

	int numOfTest;
	int colIndex, rowIndex, widthSize, heightSize;
	cin >> numOfTest;

	for(int i = 0; i < numOfTest; i++) {
		cin >> widthSize >> heightSize >> colIndex >> rowIndex;
		cout << getMaxAreaDiscardingAPixel(widthSize, heightSize, rowIndex, colIndex) << endl;
	}

	return 0;
}