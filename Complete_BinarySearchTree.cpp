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
	int* arr;
	int rear, front;
public:
	Queue();
	void Enqueue(int &v);
	Node dequeue();
	void print();
	int getrear() { return this->rear; }
};
Queue::Queue() {
	arr = new int[1000];
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
		cout << arr[k]<< " ";
		k++;
	}
	cout << arr[rear] << endl;
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
	Node* search(Node*curr,int key,int flag) {
		if (curr == NULL) {
			return NULL;
		}
		else if(curr->data==key) {
			flag = 1;
			cout << "\n Element do exist ! \n";
			return curr;
		}
		else {
			search(curr->left, key,flag);
			search(curr->right, key,flag);
		}
	}
	int wrapper_search(int key) {
		if (search(root, key, 0) == NULL)
			return 0;
		return 1;
	}
	void countNodes(Node*curr,Queue*q1) {
		if (curr) {
			countNodes(curr->left,q1);
			q1->Enqueue(curr->data);
			countNodes(curr->right,q1);
		}
	}
	int wrapper_counter() {
		Queue* q1 = new Queue;
		countNodes(this->root,q1);
		int a = 0;
		while (a != q1->getrear()) {
			a++;
		}
		return a+1;
	}
	int leafCount(Node* curr) {
		if (curr == NULL)
			return 0;
		if (curr->left == NULL && curr->right == NULL)
			return 1;
		return leafCount(curr->left) + leafCount(curr->right);
	}
	int wrapper_leafcounter() {
		return leafCount(this->root);
	}
	void wrapper_del(Node*curr) {
		if (curr) {
			wrapper_del(curr->left);
			wrapper_del(curr->right);
			delete curr;
	}
	}
	~BST() {
		wrapper_del(this->root);
}
};
int main() {
	BST b1;
	b1.insert(43);
	b1.insert(54);
	b1.insert(22);
	b1.insert(10);
	b1.insert(66);
	b1.insert(21);
	b1.insert(49);
	b1.wrapper_print();
	BST b2(b1);
	cout << "\n After Deep Copy : \n";
	b2.wrapper_print();
	cout << endl<<" Level order print is : ";
	b1.wrapper_level();
	int a=b1.wrapper_search(101);
	if (a == 0) {
		cout << "\n Element doesnot exist !\n";
	}
	cout << " Total Nodes are : ";
	cout<<b1.wrapper_counter()<<endl;
	cout << " Leaf Nodes are :" << b1.wrapper_leafcounter() << endl;
	return 0;
}
