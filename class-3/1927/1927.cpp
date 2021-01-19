#include <iostream>
#include <vector>

using namespace std;

enum order { MIN = 1, MAX = -1 };

class Heap {
private:
	int heap_size;
	int root_index;
	int order;
	vector<int> v;

	int parent(int i) {
		return i / 2;
	}

	int left(int i) {
		return 2 * i;
	}

	int right(int i) {
		return (2 * i) + 1;
	}

	void swap(int idx1, int idx2) {
		int temp = v[idx1];
		v[idx1] = v[idx2];
		v[idx2] = temp;
	}

	void upHeap(int idx) {
		if (idx != root_index) {
			if (v[parent(idx)] * order >= v[idx] * order) {
				swap(parent(idx), idx);
				upHeap(parent(idx));
			}
			else {
				return;
			}
		}
	}

	void downHeap(int idx) {
		if (right(idx) <= heap_size) {
			if (v[left(idx)] * order <= v[right(idx)] * order) {
				if (v[left(idx)] * order < v[idx] * order) {
					swap(left(idx), idx);
					downHeap(left(idx));
				}
				else return;
			}
			else {
				if (v[right(idx)] * order < v[idx] * order) {
					swap(right(idx), idx);
					downHeap(right(idx));
				}
				else return;
			}
		}
		else if (left(idx) <= heap_size) {
			if (v[left(idx)] * order < v[idx] * order) {
				swap(left(idx), idx);
				downHeap(left(idx));
			}
			else return;
		}
		else return;
	}

public:
	Heap(int order) {
		v.push_back(EOF);
		this->heap_size = 0;
		this->root_index = 1;
		this->order = order;
	}

	~Heap() {
		vector<int>().swap(v);
	}

	void insert(int data) {
		v.push_back(data);
		heap_size++;
		upHeap(heap_size);
	}

	void pop() {
		v[root_index] = v[heap_size];
		heap_size--;
		v.pop_back();
		downHeap(root_index);
	}

	int front() {
		return this->v[root_index];
	}
	bool empty() {
		return this->heap_size == 0 ? true : false;
	}
};


int main() {
	int N, x;
	Heap minheap(MIN);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> x;
		if (x == 0) {
			if (minheap.empty()) cout << "0\n";
			else {
				cout << minheap.front() << "\n";
				minheap.pop();
			}
		}
		else minheap.insert(x);
	}

	return 0;
}