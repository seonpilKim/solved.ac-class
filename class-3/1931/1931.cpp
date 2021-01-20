#include <iostream>
#include <algorithm>

using namespace std;

class Conference {
public:
	int start;
	int end;

	Conference() {}

	Conference(int start, int end) {
		this->start = start;
		this->end = end;
	}
};

bool Comp(Conference, Conference);

int main() {
	int N, tmp, max = 0;
	Conference* conference;
	
	cin >> N;
	conference = new Conference[N];

	for (int i = 0; i < N; i++) {
		cin >> conference[i].start >> conference[i].end;
	}

	sort(conference, conference + N, Comp);
	
	tmp = conference[0].end;
	max++;
	for (int i = 1; i < N; i++) {
		if (tmp <= conference[i].start) {
			tmp = conference[i].end;
			max++;
		}
	}

	cout << max;

	return 0;
}

bool Comp(Conference con1, Conference con2) {
	if (con1.end < con2.end) return true;
	else if (con1.end == con2.end) return con1.start < con2.start;
	else return false;
}