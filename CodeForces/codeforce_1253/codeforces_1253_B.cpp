#include <iostream>
#include <vector>

using namespace std;

bool areArraysWellMatched(vector<int> events) {

    int sum = 0;
    vector<int> numOfevents;
    int count = 0;

    for(int i = 0; i < events.size(); i++) {
        sum += events[i];
        count++;

        if(sum == 0) {
            numOfEvents.push_back(count);
            count = 0;
        }
    }

}

int main()
{
	int numOfEvents;
	cin >> numOfEvents;
    vector<int> events;
    int event;

	while (numOfEvents > 0) {

        cin >> event;
        events.push_back(event);

	}

    if (areArraysWellMatched(arr1, arr2))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

}
