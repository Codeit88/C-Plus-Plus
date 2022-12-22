#include<iostream>
using namespace std;
class Linklist {
	class Node {
		int data;
		Node*next;
		friend class Linklist;
		Node(int data) {
			this->data = data;
			this->next = NULL;
		}
		Node(int data,Node*next) {
			this->data = data;
			this->next = next;
		}
	};
	Node* head;
public:
	Linklist() {
		this->head = NULL;
	}
	void insert(int data) {
		Node* nnew = new Node(data);
		if (!head)
			head = nnew;
		else {
			nnew->next = head;
			head = nnew;
		}
	}
	Node* get_head() {
		return this->head;
	}
	void wrapper_deep(Linklist&l2) {
		deep_copy(l2.get_head());
	}
	void deep_copy(Node*curr){
		if (!curr)
			return;
		else {
			Node* nnew = new Node(curr->data,curr->next);
			deep_copy(curr->next);
			insert(nnew->data);
		}
	}
	void print_list() {
		Node* temp = head;
		while (temp) {
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}
};
int main() {
	Linklist l1,l2;
	l1.insert(32);
	l1.insert(53);
	l1.insert(643);
	l1.insert(21);
	l1.insert(41);
	l1.print_list();
	l2.wrapper_deep(l1);
	l2.print_list();
	return 0;
}
