#include <iostream>
#include <vector>

using namespace std;

template <class T>
void print(vector<T> vec) {
    int size = vec.size();
	for(int i = 0; i < size; i++) {
		cout << vec[i] << " ";
	}
}

void process(vector<int> & cluster) {
    int size = cluster.size();
    for(int i = 0; i < size; i++) {
        cluster[i] %= size;
    }
}

int main(){
    int n, ai;
    vector<int> cluster;

    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> ai;

        if(ai == 0) {
            process(cluster);
            print(cluster);
            cluster.clear();
        } else {
            cluster.push_back(ai);
        }
    }

    process(cluster);
    print(cluster);


	cout << endl;

	return 0;
}
