#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> vec;

void f() {
	if(vec.size() == M) {
		for(int i : vec) cout << i << " ";
		cout << "\n";
		return;
	}
	for(int i = 0; i < N; i++) {
		bool isOK = true;
		for(int j : vec) {
			if(j == i) {
				isOK = false;
				break;
			}
		}
		if(isOK) {
			vec.push_back(i);
			f();
			vec.pop_back();
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	f();
	return 0;
}