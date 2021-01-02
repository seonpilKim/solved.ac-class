#include <iostream>

using namespace std;

class Node {
public:
	int data;
	Node* next;
	Node* prev;

	Node(int data) {
		this->data = data;
		this->next = NULL;
		this->prev = NULL;
	}
};

class MyDeck {
public:
	Node* front;
	Node* back;
	int size;

	MyDeck() {
		this->front = NULL;
		this->back = NULL;
		this->size = 0;
	}

	void Push_front(int X) {
		Node* newNode = new Node(X);

		if (this->size == 0) {
			this->front = this->back = newNode;
		}
		else {
			newNode->next = this->front;
			this->front->prev = newNode;
			this->front = newNode;
		}

		this->size++;
	}

	void Push_back(int X) {
		Node* newNode = new Node(X);

		if (this->size == 0) {
			this->front = this->back = newNode;
		}
		else {
			this->back->next = newNode;
			newNode->prev = this->back;
			this->back = newNode;
		}

		this->size++;
	}

	int Pop_front() {
		if (size == 0) return -1;
		Node* tmpNode = this->front;
		int pop__data = this->front->data;
		this->front = this->front->next;
		delete tmpNode;
		this->size--;
		return pop__data;
	}

	int Pop_back() {
		if (size == 0) return -1;
		Node* tmpNode = this->back;
		int pop__data = this->back->data;
		this->back = this->back->prev;
		delete tmpNode;
		this->size--;
		return pop__data;
	}

	bool Empty() {
		return this->size == 0 ? 1 : 0;
	}

	int Front() {
		return this->size == 0 ? -1 : this->front->data;
	}

	int Back() {
		return this->size == 0 ? -1 : this->back->data;
	}
};


int main() {
	int N, data;
	MyDeck deck;
	string cmd;

	cin >> N;
	
	for (int i = 0; i < N; i++) {
		cin >> cmd;
		if (cmd == "push_front") {
			cin >> data;
			deck.Push_front(data);
		}
		else if (cmd == "push_back") {
			cin >> data;
			deck.Push_back(data);
		}
		else if (cmd == "pop_front") cout << deck.Pop_front() << "\n";
		else if (cmd == "pop_back") cout << deck.Pop_back() << "\n";
		else if (cmd == "size") cout << deck.size << "\n";
		else if (cmd == "empty") cout << deck.Empty() << "\n";
		else if (cmd == "front") cout << deck.Front() << "\n";
		else if (cmd == "back") cout << deck.Back() << "\n";	
	}

	return 0;
}