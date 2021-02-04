#include <iostream>
#include <string.h>

using namespace std;

class Person {
public:
	Person* par;
	int number;
	bool know;

	Person() {}
	Person(int number) {
		this->number = number;
		this->par = nullptr;
		this->know = false;
	}
};

int N, M;
int n, person, cnt;
Person* people;
int** party;

Person* Find(Person*);
void Union(Person*, Person*);

int main() {
	cin >> N >> M;

	cnt = M;
	people = new Person[N + 1];
	for (int i = 1; i <= N; i++) {
		people[i] = Person(i);
	}
	party = new int*[M + 1];
	for (int i = 1; i <= M; i++) {
		party[i] = new int[N + 1];
		memset(party[i], 0, sizeof(int) * (N + 1));
	}

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> person;
		people[person].know = true;
	}

	Person* root = nullptr;
	Person* prev = nullptr;
	bool flag;
	for (int i = 1; i <= M; i++) {
		cin >> n;
		flag = false;
		for (int j = 0; j < n; j++) {
			cin >> person;
			party[i][person] = 1;
			if (people[person].know == true) {
				flag = true;
				root = &people[person];
			}
			if (j > 0) Union(prev, &people[person]);		
			prev = &people[person];
		}
		if (flag) {
			for (int j = 1; j <= N; j++) {
				if (party[i][j] == 1) Union(root, &people[j]);
			}
		}
	}
	
	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			if (party[i][j] == 1) {
				if (Find(&people[j])->know == true) {
					cnt--;
					break;
				}
			}
		}
	}

	cout << cnt;

	return 0;
}


Person* Find(Person* cur) {
	if (cur->par == nullptr) return cur;
	else return Find(cur->par);
}

void Union(Person* p1, Person* p2) {
	Person* par1 = Find(p1);
	Person* par2 = Find(p2);
	if (par1 != par2) {
		if (par1->number < par2->number) par2->par = par1;
		else par1->par = par2;
	}
}