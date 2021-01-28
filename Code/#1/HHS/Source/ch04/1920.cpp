#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;

vector<int> vec;

bool binaraySearch(int num) {
	int left = 0, right = vec.size() - 1;
	while(left < right) {
		int mid = (left + right) / 2;
		if(vec[mid] < num) left = mid + 1;
		else right = mid;
	}
	return (vec[(left + right) / 2] == num);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	int tmp;
	for(int i = 0; i < N; i++) {
		cin >> tmp;
		vec.push_back(tmp);
	}

	sort(vec.begin(), vec.end());

	cin >> M;

	for(int i = 0; i < M; i++) {
		cin >> tmp;
		cout << binaraySearch(tmp) << "\n";
	}

	return 0;
}