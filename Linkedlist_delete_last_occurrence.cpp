#include<iostream>
using namespace std;
#include<iostream>
using namespace std;
class Linklist {
	class Node {
	public:
		int data;
		Node* next;
		friend class Linklist;
		Node() {}
		Node(int data, Node* next) {
			this->data = data;
			this->next = next;
		}
		~Node() {
			delete next;
		}
	};
private:
	Node* head, * tail;
public:
	Linklist() {
		head = tail = NULL;
	}
	void insertathead(int const elem) {
		Node* temp = new Node;
		temp->data = elem;
		if (head == NULL) {
			temp->next = head;
			head = temp;
		}
		else {
			temp->next = head;
			head = temp;
		}
	}
	void printForward() const {
		Node* temp = head;
		while (temp != NULL) {
			cout << temp->data << "->";
			temp = temp->next;
		}
		cout << "NULL";
		cout << endl;
	}
	bool deleteLastOccurrence(int a) {
		Node* temp = head,*prev=head;
		int counter = 0,counter2=0;
		while (temp) {
			if (temp->data == a)
				counter++;
			temp = temp->next;
		}
		temp = head;
		while (temp) {
			if (temp->data == a) {
				counter2++;
				if (counter2 == counter) {
					prev->next = temp->next;
					return true;
				}
			}
			prev = temp;
			temp = temp -> next;
		}
		return false;
	}
};
int main() {
	Linklist L1;
	L1.insertathead(1);
	L1.insertathead(4);
	L1.insertathead(0);
	L1.insertathead(1);
	L1.insertathead(6);
	L1.printForward();
	cout << endl;
	L1.deleteLastOccurrence(1);
	L1.printForward();
	return 0;
}
