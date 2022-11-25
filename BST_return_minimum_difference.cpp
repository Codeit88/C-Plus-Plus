#include<iostream>
using namespace std;
struct Node {
	int data,diff;
	Node* left, * right;
	Node(int data){
		this->data = data;
		this->diff = 0;
		this->left = this->right = NULL;
	}
};
class BST {
	Node* root;
public:
	BST() {
		this->root = NULL;
	}
	void insert(int data){ 
	Node* nnew = new Node(data);
	if (root == NULL) {
		root = nnew;
		return;
	}
	else {
		Node* curr = root, * prev = NULL;
		while (curr != NULL) {
			prev = curr;
			if (curr->data > data) {
				prev = curr;
				curr = curr->left;
			}
			else if (curr->data < data) {
				prev = curr;
				curr = curr->right;
			}
			else {
				cout << " Element already exist ! ";
				return;
			}
		}
		if (prev->data > data) {
			prev->left = nnew;
			return;
		}
		else {
			prev->right = nnew;
			return;
		}
	}
}
	int wrapper_rec_search(int data) {
		return rec_search(this->root, data);
	}
	int rec_search(Node* curr, int key) {
		if (curr == NULL)
			return 0;
		else if (curr->data == key) {
			return curr->data;
		}
		else if (curr->data > key) {
			rec_search(curr->left, key);
		}
		else
		{
			rec_search(curr->right, key);
		}
	}
	int wrapper_search(int val) {
		if (wrapper_rec_search(val) != 0) {
			return wrapper_rec_search(val);
		}
		else {
			return go_ahead(this->root,val);
		}
	}
	int go_ahead(Node*curr,int val){
		static int min = 100;
		if (curr == NULL) {
			return min;
	    }
		else {
			if (curr->data > val) {
				int diff = curr->data - val;
				if (diff < min)
					min = diff;
				curr->diff = min;
			}
		    go_ahead(curr->left,val);
		    go_ahead(curr->right,val);
		}
	}
};
int main() {
	BST b1;
	b1.insert(25);
	b1.insert(8);
	b1.insert(43);
	b1.insert(3);
	b1.insert(15);
	b1.insert(27);
	b1.insert(65);
	b1.insert(19);

	cout << b1.wrapper_search(26);
	return 0;
}
