#include <iostream>
#include <vector>

using namespace std;

enum STATE {
	DIDNOTENTER = 0,
	ENTER = 1,
	LEAVE = 2
};

#define MAX_NUM 1000000
void clearArray(STATE arr[]) {
	for (int i = 0; i < 1000000; i++) {
		arr[i] = DIDNOTENTER;
	}
}

// 1  girdi, 0, girmedi, 2 girdi-çıktı


vector<int> canBeSeperatedIntoArrays(vector<int> events) {

	vector<int> numOfEventsEachDays;
	int count = 0;

	STATE events_track[MAX_NUM];
	clearArray(events_track);

	int sum = 0;

	int event;

	for (int i = 0; i < events.size(); i++) {

		if (i > 0) {
			if (sum == 0) {
				numOfEventsEachDays.push_back(count);
				count = 0;
				clearArray(events_track);
			}
		}

		event = events[i];

		if (event > 0) {
			if (events_track[event] == DIDNOTENTER) {
				events_track[event] = ENTER;
			}
			else if (events_track[event] == ENTER) {
				return vector<int>();
			}
			else if (events_track[event] == LEAVE) {
				if (sum == 0) {
					numOfEventsEachDays.push_back(count);
					count = 0;
					clearArray(events_track);
					events_track[event] = ENTER;
				}
				else
					return vector<int>();
			}

		}
		else if (event < 0) {
			if (events_track[-event] == DIDNOTENTER) {
				return vector<int>();
			}
			else if (events_track[-event] == ENTER) {
				events_track[-event] = LEAVE;
			}
			else if (events_track[-event] == LEAVE) {
				return vector<int>();
			}

		}

		sum += event;
		count++;

	}
	if (sum == 0 && count > 0) {
				numOfEventsEachDays.push_back(count);
				count = 0;
				clearArray(events_track);
	}

	return numOfEventsEachDays;
}


int main()
{
	int numOfEventsEachDays;
	cin >> numOfEventsEachDays;
	vector<int> events;
	int event;

	while (numOfEventsEachDays > 0) {

		cin >> event;
		events.push_back(event);

		numOfEventsEachDays--;
	}

	vector<int> numOfEventsEachDaysRes = canBeSeperatedIntoArrays(events);
	cout << numOfEventsEachDaysRes.size() << endl;
	if (numOfEventsEachDaysRes.size() == 0) {
		cout << -1 << endl;
	}
	else {
		for (int i = 0; i < numOfEventsEachDaysRes.size(); i++) {
			cout << numOfEventsEachDaysRes[i] << " ";
		}
		cout << endl;
	}

}