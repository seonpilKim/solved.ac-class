#include <iostream>
#include <vector>

using namespace std;

#define EMPTY -1
vector<int> result;

class Heap {
public:
	vector<int> maxheap;
	int root_idx;
	int heap_size;

	Heap() {
		this->maxheap.push_back(EMPTY);
		this->root_idx = 1;
		this->heap_size = 0;
	}

	int par(int idx) { return idx / 2; }
	int right(int idx) { return 2 * idx + 1; }
	int left(int idx) { return 2 * idx; }

	void swap(int idx1, int idx2) {
		int tmp = this->maxheap[idx1];
		this->maxheap[idx1] = this->maxheap[idx2];
		this->maxheap[idx2] = tmp;
	}

	void UpHeap(int idx) {
		if (this->maxheap[idx] > this->maxheap[par(idx)]) {
			swap(idx, par(idx));
			if (par(idx) != 1) UpHeap(par(idx));
		}
	}

	void DownHeap(int idx) {
		if (right(idx) <= this->heap_size) {
			if (this->maxheap[idx] < this->maxheap[left(idx)]) {
				swap(idx, left(idx));
				DownHeap(left(idx));
			}
			else if (this->maxheap[idx] < this->maxheap[right(idx)]) {
				swap(idx, right(idx));
				DownHeap(right(idx));
			}
		}
		else if (left(idx) <= this->heap_size) {
			if (this->maxheap[idx] < this->maxheap[left(idx)]) {
				swap(idx, left(idx));
				DownHeap(left(idx));
			}
		}
	}

	void Insert(int n) {
		this->maxheap.push_back(n);
		this->heap_size++;
		if(this->heap_size != 1) UpHeap(heap_size);
	}

	void Delete() {
		if (this->heap_size == 0) result.push_back(0);
		else {
			result.push_back(this->maxheap[this->root_idx]);
			this->maxheap[this->root_idx] = this->maxheap[this->heap_size];
			this->maxheap.pop_back();
			this->heap_size--;
			DownHeap(this->root_idx);
		}
	}
};

int main() {
	int N, n;
	Heap h;

	cin >> N;

	while (N--) {
		cin >> n;
		if (n == 0) h.Delete();	
		else h.Insert(n);
	}
	cout << "----\n";
	for (int r : result) {
		cout << r << "\n";
	}

	return 0;
}
