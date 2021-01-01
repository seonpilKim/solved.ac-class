#include <iostream>
#include <algorithm>

using namespace std;

class Member {
public:
	int age;
	string name;

	Member() {
		this->age = 0;
		this->name = "";
	}

	Member(int age, string name) {
		this->age = age;
		this->name = name;
	}
};

bool sort__by_age(Member, Member);

int main() {
	int N;
	int age;
	string name;
	Member* member;

	cin >> N;
	member = new Member[N];

	for (int i = 0; i < N; i++) {
		cin >> age >> name;
		member[i] = Member(age, name);
	}

	sort(member, member + N, sort__by_age);

	for (int i = 0; i < N; i++) {
		cout << member[i].age << " " << member[i].name << "\n";
	}

	return 0;
}

bool sort__by_age(Member A, Member B) {
	return A.age < B.age;
}