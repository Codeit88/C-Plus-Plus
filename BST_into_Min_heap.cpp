#include<iostream>
#include<vector>
using namespace std;
struct Node {
	Node* right, * left,*prev;
	int data;
public:
	Node() {
		this->data = 0;
		this->left = this->right = this->prev = NULL;
	}
	Node(int data){
		this->data=data;
		this->left = this->right = this->prev = NULL;
	}
};
class BST {
	Node* root;
	vector<int> heap;
public:
	BST() {
		this->root = NULL;
		heap.resize(0);
	}
	bool wrapper_insert(int data) {
		return insert(this->root,this->root,data);
	}
	bool insert(Node*&root,Node*prev,int data) {
		if (!root) {
			root = new Node(data);
			root->prev = prev;
			return true;
		}
		else {
			if (data > root->data) {
				insert(root->right,root, data);
			}
			else if (data < root->data) {
				insert(root->left,root, data);
			}
		}
	}
	void wrapper_inorder() {
		inorder(this->root);
	}
	void inorder(Node* root) {
		if (root) {
			inorder(root->left);
			cout << root->data << " ";
			inorder(root->right);
		}
	}
	vector<int>* wrapper_store() {
		vector<int>* v1 = new vector<int>;
		return store(this->root,v1);
	}
	vector<int>* store(Node* root, vector<int>*&v1) {
		if (root) {
			v1->push_back(root->data);
			store(root->left, v1);
			store(root->right, v1);
		}
		else
			return v1;
	}
	void insert_in_heap(int &val){
		heap.resize(heap.size() + 1);
		int index = heap.size() - 1;
		heap[index] = val;
		while (index != 0 && heap[index] < heap[(index-1)/ 2]) {
			swap(heap[index], heap[(index-1)/2]);
			index = (index-1)/ 2;
		}
	}
	void build_heap() {
		int i = 0;
		while(i<heap.size()){
			cout << heap[i] << " ";
			i++;
		}
	}
};
int main() {
	BST b1;
	b1.wrapper_insert(43);
	b1.wrapper_insert(421);
	b1.wrapper_insert(51);
	b1.wrapper_insert(61);
	b1.wrapper_insert(23);
	b1.wrapper_insert(22);
	b1.wrapper_insert(53);
	b1.wrapper_inorder();
	cout << endl;
	vector<int>* v2 = b1.wrapper_store();
	while (!v2->empty()) {
		b1.insert_in_heap(v2->back());
		v2->pop_back();
	}
	b1.build_heap();
	return 0;
}
