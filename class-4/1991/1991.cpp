#include <iostream>

using namespace std;

class Node {
public:
	char node;
	Node* left;
	Node* right;

	Node(char node) {
		this->node = node;
		this->left = nullptr;
		this->right = nullptr;
	}
};

class Tree {
public:
	Node* root;
	Node* find;
	int size;

	Tree() {
		this->root = nullptr;
		this->size = 0;
		this->find = nullptr;
	}

	void addNode(char node, char node2, char node3) {
		if (this->size == 0) {
			Node* parNode = new Node(node);
			Node* ch1Node = new Node(node2);
			Node* ch2Node = new Node(node3);
			this->root = parNode;
			this->size++;
			if (node2 != '.') {
				parNode->left = ch1Node;
				this->size++;
			}
			if (node3 != '.') {
				parNode->right = ch2Node;
				this->size++;
			}
		}
		else {
			Find(this->root, node);
			Node* parNode = this->find;
			this->find = nullptr;
			Find(this->root, node2);
			if (node2 != '.') {
				if (this->find != nullptr) {
					parNode->left = this->find;
					this->find = nullptr;
				}
				else {
					Node* ch1Node = new Node(node2);
					parNode->left = ch1Node;
					this->size++;
				}
			}
			if (node3 != '.') {
				if (this->find != nullptr) {
					parNode->right = this->find;
					this->find = nullptr;
				}
				else {
					Node* ch2Node = new Node(node3);
					parNode->right = ch2Node;
					this->size++;
				}
			}
		}
	}

	void Find(Node* curNode, char node) {
		if (curNode->node != node) {
			if (curNode->left != nullptr) Find(curNode->left, node);
			if (curNode->right != nullptr) Find(curNode->right, node);
		}
		else this->find = curNode;
	}

	void print() {
		preorder(this->root); cout << "\n";
		inorder(this->root); cout << "\n";
		postorder(this->root);
	}

	void preorder(Node* curNode) {
		cout << curNode->node;
		if (curNode->left != nullptr) preorder(curNode->left);
		if (curNode->right != nullptr) preorder(curNode->right);
	}

	void inorder(Node* curNode) {
		if (curNode->left != nullptr) inorder(curNode->left);
		cout << curNode->node;
		if (curNode->right != nullptr) inorder(curNode->right);
	}

	void postorder(Node* curNode) {
		if (curNode->left != nullptr) postorder(curNode->left);
		if (curNode->right != nullptr) postorder(curNode->right);
		cout << curNode->node;
	}
};

int main() {
	int N;
	char par, ch1, ch2;
	Tree tree;

	cin >> N;

	while (N--) {
		cin >> par >> ch1 >> ch2;
		tree.addNode(par, ch1, ch2);
	}

	tree.print();

	return 0;
}
