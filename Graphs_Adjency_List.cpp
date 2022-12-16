#include<iostream>
#include<string>
using namespace std;
class List {
	class Node {
		Node* next, * prev;
		int data;
		friend class List;
		Node(int data) {
			this->data = data;
			this->next = this->prev = NULL;
		}
	};
	Node* head, * tail;
public:
	List() {
		this->head = this->tail = NULL;
	}
	void insert(int data) {
		Node* nnew = new Node(data);
		if (head == NULL) {
			head = tail = nnew;
			nnew->prev = NULL;
		}
		else {
			tail->next = nnew;
			nnew->prev = tail;
			tail = nnew;
		}
	}
	bool search(int data) {
		Node* temp = head;
		while (temp) {
			if (temp->data == data)
				return true;
			temp = temp->next;
		}
		return false;
	}
	int get_length() {
		Node* temp = head;
		int counter = 0;
		if (temp) {
			counter++;
			temp = temp->next;
		}
		return counter;
	}
	void print_list() {
		Node* temp = head;
		while (temp != NULL) {
			cout << temp->data<<" -> ";
			temp = temp->next;
		}
		cout << "NULL" << endl;
	}
};
class Graphs{
private:
	List** Matrix;
	int vertices;// total number of vertices
	bool isDirected; // 0 for undirected, 1 for directed
public:
	Graphs(int vertices, bool isDirected) {
		this->vertices = vertices;
		this->isDirected = isDirected;
		this->Matrix = new List*[this->vertices];
		for (int i = 0; i < this->vertices; i++){
			Matrix[i] = new List;
		}
	}
	Graphs(const Graphs& obj);
	Graphs(string fName);
	bool addEdge(int x, int y) {
		if (isDirected){
			Matrix[x]->insert(y);
		return true;
	}
		else {
			Matrix[x]->insert(y);
			Matrix[y]->insert(x);
			return true;
		}
	}
	bool removeEdge(int x, int y);
	bool isConnected(int x, int y) {
		return Matrix[x]->search(y);
	}
	int getIndegree(int x) {
		int counter = 0;
		for (int i = 0; i < this->vertices; i++){
			if (Matrix[i]->search(x))
				counter++;
		}
		return counter;
	}
	int getOutdegree(int x) {
		return Matrix[x]->get_length();
	}
	void printAllAdjc(int x) {
		Matrix[x]->print_list();
	}
	void printGraph() {
		for (int i = 0; i < this->vertices; i++){
			cout << i << " : ";
			Matrix[i]->print_list();
			cout << endl;
		}
	}// print the whole Matrix
	~Graphs() {
		for (int i = 0; i < this->vertices; i++){
			delete[] Matrix[i];
		}
	};
};
int main() {
	Graphs g1(4, 1);
	g1.addEdge(3, 2);
	g1.addEdge(3, 1);
	g1.addEdge(1, 0);
	g1.addEdge(2, 1);
	g1.addEdge(0, 2);
	g1.printGraph();
	cout << endl;
	return 0;
}
