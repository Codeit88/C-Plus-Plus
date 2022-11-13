#include<iostream>
#include<stack>
#include<vector>
using namespace std;
void swapval(int &x, int &y) {
	int temp = x;
	x = y;
	y = temp;
}
template<class T>
struct Node {
	T data;
	Node* right, * left,*prev;
	Node() {
		this->left = this->right = this->prev=NULL;
	}
	Node(T data);
};
template<class T>
Node<T>::Node(T data){
	this->data = data;
	this->left = this->right = this->prev = NULL;
}
template<class T>
class BST {
	Node<T>* root;
    int lh, rh;    //LEFT AND RIGHT SUBTREE HEIGHT
public:
	BST();
	int sumOfSubtree(Node<T>* root);
	bool isDifferenceBinaryTree(Node<T>* root);
	bool wrapper_isDifferenceBinaryTree();
	void ite_insert(T v);
	void rec_insertion(Node<T>*&curr,T data, Node<T>* prev);
	void wrapper_rec_insertion(T data);
	void rec_inorder_print(Node<T>* curr);
	void wrapper_rec_inorder_print();
	bool ite_search(Node<T>*curr,T key);
	bool wrapper_ite_search(T data);
	int wrapper_height();
	Node<T>* rec_search(Node<T>* curr, T key);
	Node<T>* wrapper_rec_search(T data);
	void ite_delete_node(Node<T>* &curr,T data);
	void wrapper_ite_delete_node(T data);
	void ite_inorder_print(Node<T>* curr);
	void wrapper_ite_inorder_print();
	void rec_preorder_print(Node<T>* curr);
	void wrapper_rec_preorder_print();
	void rec_postorder_print(Node<T>* curr);
	void wrapper_rec_postorder_print();
	void ite_postorder_print(Node<T>* curr);
	void wrapper_ite_postorder_print();
	void ite_preorder_print(Node<T>* curr);
	void wrapper_ite_preorder_print();
	void rec_levelorderPrint(Node<T>* curr, int level);
	void rec_delete_node(Node<T>* curr, T data);
	void wrapper_rec_delete_node(T data);
	void wrapper_rec_levelprint();
	bool operator==(const BST& b);
	bool wrapper_equality(Node<T>* src, Node<T>*& dest);
	void operator=(const BST&b);
	void wrapper_assignment(Node<T>* src, Node<T>* &dest);
	void Mirror_BST(Node<T>* root);
	void wrapper_mirror();
	int Count_Nodes(Node<T>* root);
	void PathSum(vector<T>& sums, Node<T>* curr, stack<int>s1);
	void wrapper_Pathsum();
	void make_skew(Node<T>* curr,vector<int>&s1);
	BST* wrapper_makeskew(int x);
	int wrapper_nodes_counter();
	bool IsBST(Node<T>* root);
	bool wrapper_isBST();
	int wrapper_rec_Count_Nodes();
	int rec_Count_Nodes(Node<T>* root);
	void Common_Ancestors(Node<T>* curr,Node<T>* n1,Node<T>* n2);
	void wrapper_Common_Ancestors(int data1,int data2);
	int getsum_nodes(Node<T>* curr);
	int wrapper_getsum_nodes();
	int rec_leaf_counter(Node<T>* curr);
	int wrapper_rec_leaf_counter();
	void Update_Key(Node<T>*curr,T x,T y);
	void wrapper_Update_Key(T x, T y);
	void wrapper_destructor(Node<T>* curr);
	~BST();
};
template<class T>
BST<T>::BST() {
	this->root = NULL;
	this->lh = this->rh = 0;
}
template<class T>
void BST<T>::wrapper_Update_Key(T x, T y){
	Node<T>* temp = wrapper_rec_search(x);
	if (temp == NULL) {
		cout << " Value not found ! \n";
	}
	else {
		wrapper_ite_delete_node(temp->data);
	}
	wrapper_rec_insertion(y);
 }
template<class T>
void BST<T>::Update_Key(Node<T>* curr, T x, T y){}
template<class T>
int BST<T>::rec_leaf_counter(Node<T>* curr){
	static int counter;
	if (curr == NULL)
		return counter;
else if(curr->left==NULL && curr->right==NULL){
		counter++;
}
	rec_leaf_counter(curr->left);
	rec_leaf_counter(curr->right);
}
template<class T>
int BST<T>::wrapper_rec_leaf_counter() {
	return rec_leaf_counter(this->root);
}
template<class T>
bool BST<T>::wrapper_isDifferenceBinaryTree(){
	return isDifferenceBinaryTree(this->root);
}
template<class T>
bool BST<T>::isDifferenceBinaryTree(Node<T>* root)
{
	if (root)
	{
		int leftSum = sumOfSubtree(root->left);
		int rightSum = sumOfSubtree(root->right);
		if (leftSum - rightSum == root->data)
			return isDifferenceBinaryTree(root->left) && isDifferenceBinaryTree(root->right);
		else return false;
	}
	else return true;
}
template<class T>
int BST<T>::sumOfSubtree(Node<T>* root)
{
	if (root)
		return (root->data + sumOfSubtree(root->left) + sumOfSubtree(root->right));
	else return 0;
}
template<class T>
int BST<T>::wrapper_getsum_nodes() {
	return getsum_nodes(this->root);
}
template<class T>
int BST<T>::getsum_nodes(Node<T>* curr) {
	static int sumv;
	if (curr == NULL) {
		return sumv;
	}
	else {
		sumv += curr->data;
		getsum_nodes(curr->left);
		getsum_nodes(curr->right);
	}
}
template<class T>
void BST<T>::wrapper_Common_Ancestors(int data1,int data2) {
	Node<T>*a=wrapper_rec_search(data1),*b=wrapper_rec_search(data2);
	Common_Ancestors(this->root,a, b);
}
template<class T>
void BST<T>::Common_Ancestors(Node<T>* curr,Node<T>* n1, Node<T>* n2) {
	if (n1->data > curr->data && n2->data > curr->data) {
		cout << curr->data<<" ";
		return Common_Ancestors(curr->right, n1, n2);
	}
	else if (n1->data < curr->data && n2->data < curr->data) {
		cout << curr->data << " ";
		return Common_Ancestors(curr->left, n1, n2);
	}
	else
		return ;
}
template<class T>
int BST<T>::wrapper_rec_Count_Nodes() {
	return rec_Count_Nodes(this->root);
}
template<class T>
int BST<T>::rec_Count_Nodes(Node<T>* curr) {
	static int counter = 0;
	if (curr == NULL) {
		return counter;
	}
	else {
		counter++;
		rec_Count_Nodes(curr->left);
		rec_Count_Nodes(curr->right);
	}
}
template<class T>
bool BST<T>::wrapper_isBST() {
	return IsBST(this->root);
}
template<class T>
bool BST<T>::IsBST(Node<T>* curr) {
	static bool flag=true;
	if (curr == NULL)
		return flag;
	else if (curr->left!=NULL && curr->left->data > curr->data) {
			flag = false;
		}

	else if (curr->right != NULL && curr->right->data  < curr->data) {
		flag = false;
	}
	if (flag) {
		IsBST(curr->left);
		IsBST(curr->right);
	}
}
template<class T>
BST<T>* BST<T>::wrapper_makeskew(int x) {
	vector<int>s1;
	make_skew(this->root,s1);
	if (x == 1) {
		for (int i = 0; i < s1.size(); i++) {
			for (int j = 0; j < s1.size(); j++) {
				if (s1[i] < s1[j]) {
					swapval(s1[i], s1[j]);
				}
			}
		}
		BST<T>*b1=new BST<T>;
		int i = 0;
		while (i<s1.size()) {
			b1->ite_insert(s1[i]);
			i++;
		}
		return b1;
	}
	else {
		for (int i = 0; i < s1.size(); i++) {
			for (int j = 0; j < s1.size(); j++) {
				if (s1[i] > s1[j]) {
					swapval(s1[i], s1[j]);
				}
			}
		}
		BST<T>*b1=new BST<T>;
		int i = 0;
		while (i < s1.size()) {
			b1->ite_insert(s1[i]);
				i++;
		}
		return b1;
	}
}
template<class T>
void BST<T>::make_skew(Node<T>*curr,vector<int>&s1) {
	if (curr) {
		s1.push_back(curr->data);
		make_skew(curr->left,s1);
		make_skew(curr->right,s1);
	}
}
template<class T>
void BST<T>::wrapper_Pathsum(){
		vector<T>sums;
		stack<int>s1;
		 PathSum(sums, this->root,s1);
		 int i = 0;
		 while (i<sums.size()) {
			 cout << " Path "<<i+1<<" sum is : "<<sums[i] << endl;
			 i++;
		 }
	}
template<class T>
void BST<T>::PathSum(vector<T>& sums,Node<T>*curr,stack<int>s1) {
	int s2 = 0;
	if (curr == NULL)
		return;
	else {
		s1.push(curr->data);
		PathSum(sums, curr->left, s1);
		if (curr->left == NULL && curr->right == NULL) {
			stack<int>s3 = s1;
			while (!s3.empty()) {
				s2 += s3.top();
				s3.pop();
			}
			sums.push_back(s2);
		}
		PathSum(sums, curr->right, s1);
		s1.pop();
	}

}
template<class T>
void BST<T>::wrapper_mirror() {
	Mirror_BST(this->root);
}
template<class T>
void BST<T>::Mirror_BST(Node<T>* curr) {
	if (curr) {
		Mirror_BST(curr->left);
		Mirror_BST(curr->right);
		Node<T>* temp = curr->left;
		curr->left = curr->right;
		curr->right = temp;
	}
}
template<class T>
int BST<T>::wrapper_nodes_counter() {
	return Count_Nodes(this->root);
}
template<class T>
int BST<T>::Count_Nodes(Node<T>* curr){
	int counter = 0;
	stack<Node<int>*>s1;
	if (this->root == NULL)
		return 0;
	while (true) {
		if (curr != NULL) {
			s1.push(curr);
			counter += 1;
			curr = curr->left;
		}
		else {
			if (s1.empty()) {
				break;
			}
			curr = s1.top();
			s1.pop();
			curr = curr->right;
		}
	}
	return counter;
}
template<class T>
bool BST<T>::operator==(const BST& b) {
	return	wrapper_equality(b.root, root);
}
template<class T>
bool BST<T>::wrapper_equality(Node<T>* src, Node<T>*& dest) {
	static bool flag = true;
	if (src == NULL) {
		return true;
	}
	else if (src != NULL && dest == NULL) {
		flag = false;
	}
	else if (src == NULL && dest != NULL) {
		flag = false;
	}
	else if (src->data != dest->data) {
		return false;
	}
	else  {
		wrapper_equality(src->left, dest->left);
		if (flag == true)
		wrapper_equality(src->right, dest->right);
	}
}
template<class T>
void BST<T>::operator=(const BST& b) {
	if (b.root)
		wrapper_assignment(b.root, root);
	else
		root = NULL;
}
template<class T>
void BST<T>::wrapper_assignment(Node<T>* src, Node<T>* &dest) {
	if (src == NULL)
		return;
	dest = new Node<T>(src->data);
	wrapper_assignment(src->left,dest->left);
	wrapper_assignment(src->right,dest->right);
}
template<class T>
void BST<T>::wrapper_rec_delete_node(T data) {
	Node<T>* temp = wrapper_rec_search(data);
	if (temp != NULL)
		rec_delete_node(temp, data);
	else
		cout << "\nNode not found! \n";
}
template<class T>
void BST<T>::rec_delete_node(Node<T>* curr, T data) {
	if (curr->data > data) {
		rec_delete_node(curr->left, data);
	}
	else if (curr->data<data) {
		rec_delete_node(curr->left, data);
	}
	else {
		Node<T>* temp = curr;
		if (curr->right == NULL) {
			curr = curr->left;
			delete temp;
		}
		else if (curr->left == NULL) {
			curr = curr->left;
			delete temp;
		}
		else {
			Node<T>* temp2 = curr->left;
			while (temp2 != NULL) {
				temp2 = temp->right;
			}
			int temp = temp2->data;
			temp2->data = curr->data;
			curr->data = temp;
			if (curr->prev->right == curr)
				curr->prev->right = NULL;
			else
				curr->prev->left = NULL;
			delete curr;
		}
	}
}
template<class T>
int BST<T>::wrapper_height() {
	if (lh > rh)
		return lh;
	return rh;
}
template<class T>
void BST<T>::rec_levelorderPrint(Node<T>* curr, int level) {
	if (curr == NULL)
		return;
	if (level == 0)
		cout << curr->data << " ";
	else {
		rec_levelorderPrint(curr->left, level - 1);
		rec_levelorderPrint(curr->right, level - 1);
	}
}
template<class T>
void BST<T>::wrapper_rec_levelprint() {
	for (int i = 0; i < wrapper_height(); i++) {
		rec_levelorderPrint(root, i);
	}
}
template<class T>
void BST<T>::ite_insert(T v) {
	Node<T>* nnew = new Node<T>(v);
	if (root == NULL) {
		root = nnew;
		return;
	}
	else {
		Node<T>* curr = root, * prev = NULL;
		if (root->data > v) {
			lh += 1;
		}
		else
			rh += 1;
		while (curr != NULL) {
			prev = curr;
			if (curr->data > v) {
				prev = curr;
				curr = curr->left;
			}
			else if (curr->data < v) {
				prev = curr;
				curr = curr->right;
			}
			else {
				cout << " Element already exist ! ";
				return;
			}
		}
		if (prev->data > v) {
			prev->left = nnew;
			nnew->prev = prev;
			return;
		}
		else {
			nnew->prev = prev;
			prev->right = nnew;
			return;
		}
	}
}
template<class T>
void BST<T>::wrapper_ite_preorder_print() {
	ite_preorder_print(this->root);
}
template<class T>
void BST<T>::ite_preorder_print(Node<T>* curr) {
	stack<Node<int>*>s1;
	if (this->root == NULL)
		return;
	while (true) {
		if (curr != NULL) {
			s1.push(curr);
			cout << curr->data << " ";
			curr = curr->left;
		}
		else {
			if (s1.empty()) {
				break;
			}
			curr = s1.top();
			s1.pop();
			curr = curr->right;
		}
	}
}
template<class T>
void BST<T>::ite_postorder_print(Node<T>* curr) {
	/*stack<Node<int>*>s1;
	while (!s1.empty()) {
		if (curr != NULL)
			curr = curr->left;
		else {
			Node<int>temp = s1.pop()->right;
			if (temp == NULL) {
				temp = s1.top();
				s1.pop();
				cout << temp->data << " ";
				while (!s1.empty() && temp == s1.pop()->right) {
					temp = s1.top();
					s1.pop();
					cout << temp->data << " ";
				}
			}
		else
		curr = temp;
		}
	}*/
}
template<class T>
void BST<T>::wrapper_ite_postorder_print() {
	ite_postorder_print(this->root);
}
template<class T>
void BST<T>::rec_postorder_print(Node<T>* curr) {
	if (curr) {
		rec_postorder_print(curr->left);
		rec_postorder_print(curr->right);
		cout << curr->data << " ";
	}
}
template<class T>
void BST<T>::wrapper_rec_postorder_print() {
	rec_postorder_print(this->root);
}
template<class T>
void BST<T>::rec_preorder_print(Node<T>* curr){
	if (curr) {
		cout << curr->data<<" ";
		rec_preorder_print(curr->left);
		rec_preorder_print(curr->right);
    }
}
template<class T>
void BST<T>::wrapper_rec_preorder_print() {
	rec_preorder_print(this->root);
}
template<class T>
void BST<T>::wrapper_ite_inorder_print() {
	ite_inorder_print(this->root);
}
template<class T>
void BST<T>::ite_inorder_print(Node<T>*curr) {
	stack<Node<int>*>s1;
	if (this->root == NULL)
		return;
	while (true) {
		if (curr != NULL) {
			s1.push(curr);
			curr = curr->left;
	  }
		else {
			if (s1.empty()) {
				break;
			}
			curr=s1.top();
			s1.pop();
			cout << curr->data << " ";
			curr = curr->right;
		}
	}
}
template<class T>
void BST<T>::wrapper_rec_insertion(T data) {
	rec_insertion(this->root,data,NULL);
}
template<class T>
void BST<T>::rec_insertion(Node<T>*&curr,T data, Node<T>* prev) {
	if (curr == NULL) {
		curr = new Node<T>(data);
		curr->prev = prev;
		return;
	}
	else if (curr->data > data){
		rec_insertion(curr->left,data,curr);
	}
	else {
		rec_insertion(curr->right, data,curr);
	}
}
template<class T>
void BST<T>::wrapper_rec_inorder_print() {
	rec_inorder_print(this->root);
}
template<class T>
void BST<T>::rec_inorder_print(Node<T>* curr) {
	if (curr == NULL)
		return;
	else {
		rec_inorder_print(curr->left);
		cout << curr->data << " ";
		rec_inorder_print(curr->right);
	}
}
template<class T>
bool BST<T>::wrapper_ite_search(T data) {
	return ite_search(this->root,data);
}
template<class T>
bool BST<T>::ite_search(Node<T>* curr,T key) {
	while (curr != NULL) {
		if (curr == NULL)
			return false;
		else if (curr->data == key)
			return true;
		else if(curr->data > key) {
			curr = curr->left;
		}
		else {
			curr = curr->right;
		}
	}
}
template<class T>
Node<T>* BST<T>::wrapper_rec_search(T data) {
	return rec_search(this->root, data);
}
template<class T>
Node<T>* BST<T>::rec_search(Node<T>* curr, T key) {
	if (curr == NULL)
		return NULL;
	else if (curr->data == key) {
		return curr;
	}
	else if (curr->data > key) {
		rec_search(curr->left, key);
	}
	else
	{
		rec_search(curr->right, key);
	}
}
template<class T>
void BST<T>::wrapper_ite_delete_node(T data) {
	Node<T>*temp = wrapper_rec_search(data);
	if (temp != NULL)
		ite_delete_node(temp, data);
	else
		cout << "\nNode not found! \n";
}
template<class T>
void BST<T>::ite_delete_node(Node<T>* &curr,T data) {
	bool cond1 = curr->right == NULL && curr->left == NULL,
		cond2 = curr->left == NULL && curr->right != NULL,
		cond3 = curr->right == NULL && curr->left != NULL,
		cond4 = curr->right != NULL && curr->left != NULL;
	if (cond1){
		if (curr->prev->right == curr)
			curr->prev->right = NULL;
		else
			curr->prev->left = NULL;
		delete curr;
	}
	else if (cond2 || cond3) {
		if (cond2) {
			if (curr == curr->prev->right) {
				curr->prev->right = curr->right;
				delete curr;
			}
			else {
				curr->prev->left = curr->right;
				delete curr;
			}
		}
		else if (cond3) {
			if (curr == curr->prev->right) {
				curr->prev->right = curr->left;
				delete curr;
			}
			else {
				curr->prev->left = curr->left;
				delete curr;
			}
		}
	}
	else if (cond4) {
		Node<T>* pre = NULL, * pprev = root;
		if (curr->data > root->data) {
			pre = curr->left;
			while (pre != NULL) {
				pprev = pre;
				if (pre->right != NULL) {
					pre = pre->right;
				}
				else
					pre = pre->left;
			}
		}
		else if (curr->data < root->data) {
			pre = curr->right;
			while (pre != NULL) {
				pprev = pre;
				if (pre->left != NULL) {
					pre = pre->left;
				}
				else
					pre = pre->right;
			}
		}
			int temp = curr->data;
			curr->data = pprev->data;
			pprev->data = temp;
			curr = pprev;
			if (curr->prev->right == curr)
				curr->prev->right = NULL;
			else
				curr->prev->left = NULL;
			delete curr;
	}
}
template<class T>
void BST<T>::wrapper_destructor(Node<T>*curr) {
	if (curr) {
		wrapper_destructor(curr->left);
		wrapper_destructor(curr->right);
		delete curr;
	}
}
template<class T>
BST<T>::~BST() {
	wrapper_destructor(this->root);
}
void startup() {
	cout << "    .............................. Binary Search Tree ......................................\n";
	cout << "                .......................................................\n";
	cout << "                         ...................................\n\n";
}
int main() {
	startup();
	BST<int>b1,*b2=new BST<int>;
	b1.ite_insert(32);
	b1.ite_insert(54);
	b1.ite_insert(13);
	b1.ite_insert(12);
	b1.ite_insert(73);
	b1.ite_insert(64);
	b1.ite_insert(27);
	b1.ite_insert(45);
	cout << " In_order  is : ";
	b1.wrapper_rec_inorder_print();
	cout << endl;
	cout << " Pre_order  is : ";
	b1.wrapper_ite_preorder_print();
	cout << endl;
	cout << " Post_order  is : ";
	b1.wrapper_rec_postorder_print();
	cout << endl;
	cout << " Level_order is : ";
	b1.wrapper_rec_levelprint();
	//cout << b1.wrapper_getsum_nodes();
	return 0;
}
