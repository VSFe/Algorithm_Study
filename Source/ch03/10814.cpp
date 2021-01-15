#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;

struct Person {
	int age;
	string name;
};

bool compare(const Person &x, const Person &y) {
	return x.age < y.age;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	vector<Person> vec;
	int age; string name;
	for(int i = 0; i < N; i++) {
		cin >> age >> name;
		vec.push_back({age, name});
	}

	sort(vec.begin(), vec.end(), compare);

	for(auto i : vec) {
		cout << i.age << " " << i.name << "\n";
	}
	return 0;
}