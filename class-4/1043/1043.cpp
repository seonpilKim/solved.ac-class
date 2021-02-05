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

	// 진실을 아는 사람 입력 및 세팅
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> person;
		people[person].know = true;
	}

	Person* prev = nullptr;
	bool flag;
	
	// 파티 입력 및 세팅
	for (int i = 1; i <= M; i++) {
		cin >> n;
		flag = false;
		
		// 각 파티에 참가한 사람들 입력 및 세팅
		for (int j = 0; j < n; j++) {
			cin >> person;
			party[i][person] = 1;

			// 현재 파티에 있는 사람들 합집합연산
			if (j > 0) Union(prev, &people[person]);	
			prev = &people[person];	
		}
	}
	
	// M개의 파티를 돌면서 진실을 아는 사람이 속한 경우, cnt--
	for (int i = 1; i <= M; i++) {
		for (person = 1; person <= N; person++) {
			if (party[i][person] == 1) {
				if (Find(&people[person])->know == true) {
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

		// 한 집합이 진실을 아는 집합일 경우 다른 한 집합도 전염
		if (par1->know || par2->know) par1->know = par2->know = true;
	}
}