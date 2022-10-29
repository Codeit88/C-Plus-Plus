#include<iostream>
using namespace std;
template<class T>
class Linklist {
	class Node {
		T data;
		Node* next, * prev;
		friend class Linklist<T>;
	public:
		Node() {}
		Node(T data) {
			this->next = this->prev = NULL;
			this->data = data;
		}
	};
private:
	Node* head, * tail, * current, * tailend;
public:
	Linklist() {
		//current = head;
		this->head = new Node;
		this->tail = new Node;
		this->head->next = this->tail;
		this->tail->prev = this->head;
		this->head->prev = NULL;
		this->tail->next = NULL;
	}
	//Linklist(Node head, Node tail) {
	//	this->head = head;
	//	this->tail = tail;
	//}
	class Iterator {
		Node* current;
		friend class Linklist<T>;
	public:
		Iterator() {
			current = NULL;
		}
		Iterator(Node* current) {
			this->current = current;
		}
		T& operator*() const {
			return current->data;
		}
		Iterator& operator++() {
			if (current != NULL)
				this->current = this->current->next;
			return *this;
		}
		Iterator operator++ (int)
		{
			Iterator old = *this;
			++(*this);
			return old;
		}
		Iterator& operator--() {
			if (current != NULL)
				this->current = this->current->prev;
			return *this;
		}
		Iterator& operator--(int) {
			Node* old = *this;
			--(*this);
			return old;
		}
		bool operator==(const Iterator& rhs) const {
			return current == rhs.current;
		}
		bool operator!=(const Iterator& rhs) const {
			return !(*this == rhs);
		}
	};
	Iterator Begin() const {
		return head->next;
	}
	Iterator getNode(int& a) {
		int count = 0;
		Node* temp = head;
		while (count < a) {
			temp = temp->next;
			count++;
		}
		this->current = temp;
		return current;
	}
	Iterator End() const {
		return NULL;
	}
	Iterator Insert(Iterator& x, T val) {
		Node* temp = new Node(val);
		temp->next = x.current->next;
		x.current->next->prev = temp;
		x.current->next = temp;
		temp->prev = x.current;
		x.current = temp;
		return x.current;
	}
	Iterator Insert_Multiple(Iterator& x, T val1, T val2, T val3) {
		Node* temp1 = new Node(val1), * temp2 = new Node(val2), * temp3 = new Node(val3);
		temp3->next = x.current->next;//last node retaining the next of current ptr
		x.current->next = temp1;//current ptr poiting to the node of first data
		temp1->next = temp2;
		temp1->prev = x.current;
		temp2->next = temp3;
		temp2->prev = temp1;
		temp3->prev = temp2;
		this->current = temp3;
		return current;
	}
	Iterator Delete(Iterator& x, int& val) {
		int count = 0;
		Node* temp = head->next;
		while (count < val - 1) {   //searching the deletion index
			temp = temp->next;
			count++;
		}
		Node* temp2 = temp;
		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
		delete temp2;
		this->current = temp->next;
		return current;
	}
	Iterator Delete_Multiple(Iterator& x, int& val) {
		x=Begin();
		int counter = 0;
		while (counter < val) {
			Node* temp = x.current;
			x.current = x.current->next;
			delete temp;
			counter++;      //counting numbers upto deletion
		}
		//x.current = x.current->next;
		head->next = x.current;
		x.current->prev = head;
		return x.current;
	}
	Iterator Search_First(int& val) {
		Node* temp = head->next;
		int count = 1, flag = 0;
		while (temp->data != val) {
			temp = temp->next;
			count++;
		}/*
		while (temp->data != NULL) {
			if (temp->data == val) {
				flag++;
			}
			temp = temp->next;
		}
		if (flag == 0) {
			cout << "Element doesnot exist \n ";
		}*/
		this->current=temp;
		return current;
	}
	void Delete_in_Range(Iterator& x, Iterator& y) {
		Node* retain = x.current->prev;//to retain the staring index of range
		while (x.current->next != y.current->next) {
			Node* temp = x.current;
			x.current = x.current->next;
			delete temp;
		}
		retain->next = x.current->next; //this will link the startig deletion node to the -> next of last updated node
		x.current->next->prev = retain;
		x.current->next = y.current->next;
		y.current->next->prev = x.current;
	}
	void Search_All(int val) {
		int flag = 0, count = 1;
		Node* temp = head->next;
		while (temp->data != NULL) {
			if (temp->data == val) {
				flag++;
			}
			temp = temp->next;
		}
		if (flag == 0) {
			cout << "Element doesnot exist \n ";
		}
		temp = head->next;
		while (temp != NULL) {
			if (temp->data == val) {
				cout << count << endl;
			}
			temp = temp->next;
			count++;
		}
	}
	void Insertat_at_Head(T val) {
		Node* temp = new Node(val),
			* temp2 = tailend;
		this->current = temp;//pointer referring to the current node added
		temp->next = this->head->next;//putting head,s next to the new Node
		temp->prev = this->head;
		head->next = temp;
		current->next->prev = head->next;//last current,s previous pointer setup
		tailend = current;//pointer to maintain the tail node
		while (tailend != tail) {//loop to move tail maintaining pointer at tail 
			temp2 = tailend;//to secure the last tail data
			tailend = tailend->next;
		}
		tail->prev = temp2;//setting up tail
	}
	void Delete_from_Head() {
		Node* temp = this->head->next;
		this->head->next = this->head->next->next;
		this->head->next->prev = this->head;
		delete temp;
	}
	void Delete_All(T val) {
		Node* temp = this->head->next;
		while (temp != tail) {
			if (temp->data == val) {
				temp->prev->next = temp->next;
				temp->next->prev = temp->prev;
			}
			temp = temp->next;
		}
	}
	void Replace_All(T val, T val2) {
		Node* temp = this->head->next;
		while (temp != tail) {
			if (temp->data == val) {
				temp->data = val2;
			}
			temp = temp->next;
		}
	}
	void Swap(int left, int right) {
		int counter1, counter2;
		counter1 = counter2 = 0;
		Node* temp1, * temp2, * t1prev, * t2prev;
		temp1 = temp2 = t1prev = t2prev = head->next;

		while (counter1 < (left - 1)) {
			t1prev = temp1;
			temp1 = temp1->next;
			counter1++;
		}
		while (counter2 < (right - 1)) {
			t2prev = temp2;
			temp2 = temp2->next;
			counter2++;
		}

		Node* nnew = new Node(temp1->data);//temp node made for storing value
		t2prev->next = nnew;//right integer will point to this node
		nnew->prev = t2prev;
		nnew->next = temp2->next;
		temp2->next->prev = nnew;

		t1prev->next = temp2;//this is working for swapiing left node value with right one
		temp2->prev = t1prev;
		temp2->next = temp1->next;
		temp1->next->prev = temp2;
	}
	void printfor() {
		Node* temp = head->next;
		while (temp != tail) {
			cout << temp->data << " -> ";
			temp = temp->next;
		}
		cout << " Null " << endl;
	}
	void printbac() {
		Node* temp = tail->prev;
		while (temp != head) {
			cout << temp->data << " -> ";
			temp = temp->prev;
		}
		cout << " Null " << endl;
	}
};
int main() {

	int x, y, node, node2, cons, freq1;
	Linklist<char>l1;
	l1.Insertat_at_Head('A');
	l1.Insertat_at_Head('B');
	l1.Insertat_at_Head('C');
	l1.Insertat_at_Head('E');
	l1.Insertat_at_Head(12);
	l1.Insertat_at_Head(90);
	l1.Insertat_at_Head(41);
	l1.Insertat_at_Head(40);
	l1.Insertat_at_Head(12);
	l1.Insertat_at_Head(94);
	l1.Insertat_at_Head(41);
	l1.Insertat_at_Head(78);
	l1.printfor();
	cout << ".....................................................................\n";
	l1.Delete_from_Head();
	l1.printfor();
	cout << ".....................................................................\n";
	l1.Delete_All(41);
	l1.printfor();
	cout << ".....................................................................\n";
	l1.Replace_All(2, 300);
	l1.printfor();
	cout << ".....................................................................\n";
	l1.Swap(3, 7);
	l1.printfor();
	cout << "\n\n\n...............................Using Iterators......................................\n\n\n";

	Linklist<char>::Iterator I, I1, I2;
	I = l1.Begin();
	cout << " Enter the node after which you want to enter the value : ";
	cin >> node;//for insertion
	I = l1.getNode(node);
	l1.Insert(I, 8);
	l1.printfor();
	cout << ".....................................................................\n";
	I = l1.Insert_Multiple(I, 44, 77, 65);
	l1.printfor();
	cout << ".....................................................................\n";
	cout << "Enter the node you want to delete : ";
	cin >> node2;//fr deletion
	I1 = l1.Delete(I, node2);
	l1.printfor();
	cout << ".....................................................................\n";
	cout << " Enter the number of consecutive values you want to delete : \n";
	cin >> cons;
	I2 = l1.Delete_Multiple(I, cons);
	l1.printfor();
	cout << ".....................................................................\n";
	cout << " Enter the indexes as range for deleting nodes : \n";
	cin >> x >> y;
	I1 = l1.getNode(x);
	I2 = l1.getNode(y);
	l1.Delete_in_Range(I1, I2);
	l1.printfor();
	cout << ".....................................................................\n";
	cout << " Enter the value you are looking for : ";
	cin >> freq1;
	I = l1.Search_First(freq1);
	cout << *(I);
	cout << ".....................................................................\n";
	l1.Search_All(40);
	return 0;
}

