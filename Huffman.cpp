#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;
struct Node {
	char data;
	int frequency;
	Node* left, * right;
	Node(){}
	Node(char &data,int &frequency) {
		this->data = data;
		this->frequency = frequency;
		this->left = this->right = NULL;
	}
	Node(int& frequency) {
		this->frequency = frequency;
		this->left = this->right = NULL;
	}
};
string open_file(string s1) {
	string s2;
	ifstream obj(s1);
	if (!obj.is_open())
		cout << " File is not opened ! \n";
	else {
		obj >> s2;
	}
	obj.close();
	return s2;
}
vector<char> seperate_unique_chars(string& s2, vector<char>& v1) {
	for (int i = 0; i < s2.size(); i++) {
		for (int j = 0; j < s2.size(); j++)
		{
			if (s2[i] < s2[j]) {
				char temp = s2[i];
				s2[i] = s2[j];
				s2[j] = temp;
			}
		}
	}
	for (int i = 0; i < s2.size(); i++) {
		if (s2[i] == s2[i + 1])
			continue;
		v1.push_back(s2[i]);
	}
	return v1;
}
vector<char> unique_chars(string& s2, vector<char>& v1) {
	//v1.push_back(s2[0]);
	for (int i = 0; i < s2.size(); i++) {
		int counter = 0;
		v1.push_back(s2[i]);
		for (int j = 0; j < v1.size(); j++) {
			if (s2[i] == v1[j]) {
				counter++;
			}
			if (counter > 1) {
				v1.pop_back();
				break;
			}
		}
	}
	return v1;
}
int* freq_counter(string& s2, vector<char>& v1, int* arr) {
	for (int i = 0, k = 0; i < v1.size(); i++, k++) {
		int counter = 0;
		for (int j = 0; j < s2.size(); j++) {
			if (v1[i] == s2[j]) {
				counter++;
				continue;
			}
			continue;
		}
		arr[k] = counter;
	}
	return arr;
}
void swap_val(Node*&x, Node*& y) {
	Node* temp = x;
	x = y;
	y = temp;
}
Node* getnodes(vector<char>&v1,int*freq){
	Node* n1=new Node[v1.size()];
	for (int i = 0; i < v1.size(); i++) {
		n1[i] = Node(v1[i], freq[i]);
	}
	return n1;
}
class Min_heap {
	vector<Node*>vec1;
	int size;
public:
	Min_heap() {
		this->size = 0;
		vec1.resize(size);
	}
	void insert(Node* val) {
		size++;
		vec1.resize(vec1.size()+1);
		int index = vec1.size() - 1;
		vec1[index] = val;
		while (index != 0 && vec1[(index - 1) / 2]->frequency > vec1[index]->frequency) {
			swap_val(vec1[(index - 1) / 2], vec1[index]);
			index = (index - 1) / 2;
		}
	}
	vector<Node*>& getvec() {
		return this->vec1;
	}
	void heapify(int i) {
		int l = 2 * i+1;
		int r = 2 * i + 2;
		int smallest = i;
		if (l < size && vec1[l]->frequency < vec1[smallest]->frequency)
			smallest = l;
		if (r < size && vec1[r]->frequency < vec1[smallest]->frequency)
			smallest = r;
		if (smallest != i) {
			swap_val(vec1[i], vec1[smallest]);
			heapify(smallest);
		}
	}
	Node* extract_min() {
		if (vec1.size() == 0) {
			return NULL;

		}
		else if(vec1.size()==1){
			Node *temp=new Node(vec1[0]->data, vec1[0]->frequency);
			temp->left = vec1[0]->left;
			temp->right = vec1[0]->right;
			vec1.resize(vec1.size()-1);
			return temp;
		}
		else {
			Node *root = vec1[0];
			swap_val(vec1[0], vec1[vec1.size() - 1]);
			vec1.resize(vec1.size() - 1);
			size--;
			heapify(0);
			return root;
		}
	}
	Min_heap* huffman_tree() {
		Node* n1, * n2,*n3;
		int freq;
		char a='-';
		while (vec1.size() > 1) {
			 n1 = extract_min();
			 n2 = extract_min();
			 freq = n1->frequency + n2->frequency;
			 n3=new Node(freq);
			 n3->left = n1;
			 n3->right = n2;
			 insert(n3);
		}
		wrapper_inorder();
		return this;
	}
	void inorder(Node*root){
		if (root) {
			inorder(root->left);
			cout << root->data << " ";
			inorder(root->right);
		}
	}
	void wrapper_nameit(vector<char>&v3) {
		vector<int>v2;
		for (int i = 0; i < v3.size(); i++){
			tree_nameit(vec1[0], v2,v3[i]);
		}
	}
	void tree_nameit(Node*curr, vector<int>&v2,char&key) {
		//if (curr) {
		//	/*if (curr->left)
		//		v2.push_back(0);
		//	else if(curr->right)
		//		v2.push_back(1);
		//	if (curr->data == key) {
		//		for (int i = 0; i < v2.size(); i++) {
		//			cout << v2[i] << " ";
		//		}
		//	}*/
		//	if (curr->data == key) {
  //                 return;
		//	}
		//	else {
		//		v2.push_back()
		//		tree_nameit(curr->left, v2, key);
		//		tree_nameit(curr->right, v2, key);
		//	}
		//}
		
	}
	void wrapper_inorder() {
		inorder(vec1[0]);
	}
	void print_heap() {
		for ( int i = 0; i <vec1.size(); i++) {
			cout << vec1[i]->data <<" ";
		}
	}
};
//Min_heap huffman_tree(Min_heap&m1) {
//	while(m1)
//}
int main() {
	string *s1=new string,s2;
	vector<char> v1, v2,v3;
	cout << " Enter the filename you want to open : ";
	cin >> *s1;
	s2=open_file(*s1);
	//''''''''''''''''''''''''''''''''''''''''''''''''''''''
	cout << " My string is : ";
	for (int i = 0; i < s2.size(); i++){
		cout << s2[i] << " ";
	}
	//''''''''''''''''''''''''''''''''''''''''''''''''''''''
	cout << endl;
	cout << " Unique chars : ";
	v3 = unique_chars(s2, v1);
	for (int i = 0; i < v3.size(); i++) {
		cout << v3[i] << " ";
	}
	//;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	cout << endl;
	cout << " Unique freqs : ";
	int* freq = new int[v3.size()],*freq2;
	freq2 = freq_counter(s2,v3,freq);
	for (int i = 0; i < v3.size(); i++) {
		cout << freq2[i] << " ";
	}
	cout << "\n";
	Node* n2 = getnodes(v3, freq2);
	Min_heap m1,*m2;
	for (int i = 0; i < v3.size(); i++) {
		m1.insert(&n2[i]);
	}
	m1.getvec();
	cout << " My_heap/Prior: ";
	m1.print_heap();
	cout << endl;
	cout << " Huffman tree is : ";
	m2=m1.huffman_tree();
	cout<<endl;
	m2->wrapper_nameit(v3);
	cout << endl;
	return 0;
}
