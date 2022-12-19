//Written by Muhammad Sami Khokher
#include<iostream>
#include<string>
#include<vector>
#include<queue>
using namespace std;
vector<int>v1;
template <typename T>
class list {
public:
	class node {
	public:
		T  data;int time;
		node* next;
		node(T data, int time) {
			this->next = NULL;
			this->data = data;
			this->time = time;
		}
		node(T data, node* p) { this->data = data; next = p; }
		friend class list<T>;
	};
	node* search(int data) {
		node* temp = head;
		while (temp) {
			if (temp->data == data)
				return temp;
			temp = temp->next;
		}
		return NULL;
	}
	node* get_head() {
		return this->head;
	}
	class listiterator {
	protected:
		node* current;
		friend class list<T>;
	public:
		//Default Constructor
		listiterator() { current = NULL; }
		//Parameterized Constructor used in begin and end functions
		listiterator(node* p) { current = p; }
		//Dereference operation to provide access of data to user
		node* get_node() {
			return this->current;
		}
		int get_time() {
			return this->current->time;
		}
		node* get_next_node() {
			return this->current->next;
		}
		T& operator* () const { return current->data; }
		//Move forward Pre-increment
		listiterator& operator++ ()
		{
			if (current != NULL)
				this->current = this->current->next;
			return *this;
		}
		//Move forward Post-increment
		listiterator operator++ (int)
		{
			listiterator old = *this;
			++(*this);
			return old;
		}
		//If two iterators point to same node
		bool operator== (const listiterator& rhs) const { return current == rhs.current; }
		//If two iterators point to different nodes
		bool operator!= (const listiterator& rhs) const { return !(*this == rhs); }
	};
	void DFS_list(int start);
	//Iterator returned that points to First Node 
	listiterator begin() { return head; }
	//Iterator returned that points to Last Node  
	listiterator end() { return NULL; }

	//Other Functions of Link list
	void  printList();
	void  InsertatTail(T value, int time);
	list() { head = NULL; tail = NULL; }
private:
	node* head;
	node* tail;
};
//print list
template <typename T>
void list<T>::printList()
{
	node* current;
	current = head;
	while (current != NULL)
	{
		cout << current->data << " -> ";
		current = current->next;
	}
	cout << "NULL" << endl;
}
template <typename T>
void list<T>::InsertatTail(T value, int time)
{
	v1.push_back(value);
	node* nnode = new node(value, time);
	if (head == NULL)
	{
		head = nnode;
		tail = nnode;
	}
	else {
		tail->next = nnode;
		tail = nnode;
	}

}
class Graphs {
private:
	list<int>** Matrix;
	int vertices;// total number of vertices
	bool isDirected; // 0 for undirected, 1 for directed
public:
	Graphs(int vertices, bool isDirected, int* time) {
		this->vertices = vertices;
		this->isDirected = isDirected;
		this->Matrix = new list<int> *[this->vertices];
		for (int i = 0; i < this->vertices; i++) {
			Matrix[i] = new list<int>;
			Matrix[i]->InsertatTail(i, time[i]);
		}
	}
	bool addEdge(int x, int y, int xtime, int ytime) {
		Matrix[x]->InsertatTail(y, ytime);
		Matrix[y]->InsertatTail(x, xtime);
		return true;
	}
	void get_cases(int start) {
		queue<int>q1;
		int* visit = new int[vertices];
		q1.push(start);
		visit[start] = 1;
		while (!q1.empty()) {
			int node = q1.front();
			q1.pop();
			cout << node << " ";
			visit[node] = 1;
			for (list<int>::listiterator x(Matrix[node]->get_head());x != NULL;x++) {
				if (visit[*x] != 1) {
					visit[*x] = 1;
					if (x.get_time() > Matrix[node]->get_head()->time) {
						q1.push(*x);
						//x.get_node()->time = x.get_time();
					}
				}
			}
		}
	}
	void printGraph() {
		for (int i = 0; i < this->vertices; i++) {
			Matrix[i]->printList();
			cout << endl;
		}
	}
};
int main() {
	int* time1{ new int [3] {2,4,7} };
	Graphs g1(3, 0, time1);
	g1.addEdge(0, 1, 2, 1);
	g1.addEdge(1, 2, 4, 6);
	g1.get_cases(0);
	return 0;
}
