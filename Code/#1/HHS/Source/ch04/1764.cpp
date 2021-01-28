#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;

vector<string> vec;

bool binaraySearch(string target) {
	int left = 0, right = vec.size() - 1;
	while(left < right) {
		int mid = (left + right) / 2;
		if(vec[mid] < target) left = mid + 1;
		else right = mid;
	}
	return (vec[(left + right) / 2] == target);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	string tmp;
	for(int i = 0; i < N; i++) {
		cin >> tmp;
		vec.push_back(tmp);
	}

	sort(vec.begin(), vec.end());

	vector<string> vec1;
	for(int i = 0; i < M; i++) {
		cin >> tmp;
		if(binaraySearch(tmp)) {
			vec1.push_back(tmp);
		}
	}

	sort(vec1.begin(), vec1.end());
	cout << vec1.size() << "\n";
	for(string i : vec1) {
		cout << i << "\n";
	}

	return 0;
}