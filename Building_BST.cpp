#include<iostream>
using namespace std;
struct Node {
	int data;
	Node* left;
	Node* right;
	Node(){};
	Node(int& data);
};
Node::Node(int &data) {
		this->data = data;
		this->left = this->right = NULL;
}
class Queue {
	Node* arr;
	int rear, front;
public:
	Queue();
	void Enqueue(int &v);
	Node dequeue();
	void print();
};
Queue::Queue() {
	arr = new Node[1000];
	this->rear = this->front = -1;
}
void Queue::Enqueue(int& v){
	this->rear++;
	arr[this->rear] = v;
}
Node Queue::dequeue() {
	this->front++;
	return this->arr[this->front];
}
void Queue::print() {
	int k = front;
	while (k != rear) {
		cout << arr[k].data << " ";
		k++;
	}
	cout << arr[rear].data << endl;
}
class BST {
	Node* root;
	int rh,lh;
public:
	BST() {
		this->root = NULL;
		this->rh = this->lh = 0;
	}
	bool insert(int v) {
		Node* nnew = new Node(v);
		if (root == NULL) {
			root = nnew;
			return true;
		}
		else {
			Node* curr = root,*prev=NULL;
			while (curr != NULL){
				prev = curr;
				if (curr->data > v) {
					lh += 1;
					curr = curr->left;
				}
				else if(curr->data<v){
					rh += 1;
					curr = curr->right;
				}
				else {
					cout << " Element already exist ! ";
					return false;
				}
			}
			if (prev->data > v) {
				prev->left = nnew;
				return true;
			}
			else {
				prev->right = nnew;
				return true;
			}
		}
	}
	BST(const BST &a){
		inorder_copy(a.root,root);
	}
	void inorder_copy(Node*src,Node*&dest) {
		if (src == NULL) {
			dest = NULL;
		}
		else {
			dest = new Node(src->data);
			inorder_copy(src->left,dest->left);
			inorder_copy(src->right,dest->right);
		}
	}
	void inorder_print(Node*curr) {
		if (curr != NULL) {
			inorder_print(curr->left);
			visit(curr);
			inorder_print(curr->right);
	   }
	}
	void visit(Node* curr) { cout << curr->data << " "; }
	void wrapper_print() {
		inorder_print(root);
	}
	int wrapper_height(){
		if (lh > rh)
			return (lh-1);
		return (rh-1);
	}
	void levelorderPrint(Node*curr,int level)  {
		if (curr == NULL)
			return;
		if (level == 0)
			cout << curr->data << " ";
		else {
			levelorderPrint(curr->left,level-1);
			levelorderPrint(curr->right, level - 1);
		}
	}
	void wrapper_level() {
		for (int i = 0; i < wrapper_height(); i++){
			levelorderPrint(root, i);
		}
	}
	/*void levelorderPrint(Node*curr)  {
		curr = root;
		while
	}*/
};
int main() {
	BST b1;
	b1.insert(43);
	b1.insert(54);
	b1.insert(22);
	b1.insert(10);
	b1.insert(66);
	b1.insert(21);
	b1.wrapper_print();
	BST b2(b1);
	cout << "\n\nAfter Deep Copy : \n\n";
	b2.wrapper_print();
	cout << endl<<"Level order print is : ";
	b1.wrapper_level();
	//b1.wrapper_inorder();
	//BST b2 = b1;
	return 0;
}
