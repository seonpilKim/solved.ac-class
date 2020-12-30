#include <iostream>

using namespace std;

class Node {
public:
	int N;
	Node* next;

	Node(int N) {
		this->N = N;
		this->next = NULL;
	}
};

class MyQueue {
public:
	Node* front;
	Node* back;
	int size;

	MyQueue() {
		this->front = NULL;
		this->back = NULL;
		this->size = 0;
	}

	void Push(int X) {
		Node* newNode = new Node(X);
		if (this->size == 0) this->front = this->back = newNode;
		else {
			this->back->next = newNode;
			this->back = newNode;
			if (this->size == 1) this->front->next = newNode;
		}
		size++;
	}

	int Pop() {
		if (this->size == 0) return -1;
		int X = this->front->N;
		Node* tmpNode = this->front;
		this->front = this->front->next;
		delete tmpNode;
		size--;
		if (this->size == 0) this->front = this->back = NULL;
		return X;
	}

	bool Empty() {
		return this->size == 0 ? 1 : 0;
	}

	int Front() {
		return this->size == 0 ? -1 : this->front->N;
	}

	int Back() {
		return this->size == 0 ? -1 : this->back->N;
	}
};

int main() {
	int T, N;
	string cmd;
	MyQueue mq;

	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> cmd;
		if (cmd == "push") {
			cin >> N;
			mq.Push(N);
		}
		else if (cmd == "pop") cout << mq.Pop() << "\n";
		else if (cmd == "empty") cout << mq.Empty() << "\n";
		else if (cmd == "size") cout << mq.size << "\n";
		else if (cmd == "front") cout << mq.Front() << "\n";
		else if (cmd == "back") cout << mq.Back() << "\n";
	}

	return 0;
}
