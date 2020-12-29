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

class MyStack {
public:
	Node* top;
	int size;

	MyStack() {
		this->top = NULL;
		this->size = 0;
	}

	void Push(int X) {
		Node* newNode = new Node(X);
		this->size++;
		if (this->top == NULL) {
			this->top = newNode;	
		}
		else {
			newNode->next = this->top;
			this->top = newNode;
		}
	}

	int Pop() {
		if (this->top == NULL) return -1;

		Node* tmpNode = this->top;
		int X = this->top->N;
		this->top = this->top->next;
		delete tmpNode;
		this->size--;
		return X;
	}

	int Size() {
		return this->size;
	}

	int Empty() {
		return (this->size == 0) ? 1 : 0;
	}

	int Top() {
		return Empty() ? -1 : (this->top->N);
	}
};

int main() {
	int T, X;
	string cmd;
	MyStack ms;

	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> cmd;
		if (cmd == "push") {
			cin >> X;
			ms.Push(X);
		}
		else if (cmd == "pop") cout << ms.Pop() << "\n";
		else if (cmd == "size") cout << ms.Size() << "\n";
		else if (cmd == "empty") cout << ms.Empty() << "\n";
		else if (cmd == "top") cout << ms.Top() << "\n";
	}
	return 0;
}
