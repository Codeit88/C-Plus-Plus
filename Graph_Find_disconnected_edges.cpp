/*You are given an integer n.There is an undirected graph with n nodes, numbered from 0 to n - 1. You are given a 2D integer array edges where edges[i] = [ai, bi] denotes that there exists an undirected edge connecting nodes ai and bi.
Return the number of pairs of different nodes that are unreachable from each other.*/
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
		T  data;
		node* next;
		bool status;
		node(T data) {
			this->next = NULL;
			this->data = data;
			this->status = false;
		}
		node(T data, node* p) { this->data = data; next = p; }
		friend class list<T>;
	};
	void wrapper_dfs(node* curr);
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
	//Iterator returned that points to First Node 
	listiterator begin() { return head; }
	//Iterator returned that points to Last Node  
	listiterator end() { return NULL; }

//Other Functions of Link list
void  printList();
void  InsertatTail(T value);
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
//insertnode at tail
template <typename T>
void list<T>::wrapper_dfs(node* curr) {
	curr->status = true;
	cout << curr->data;
	wrapper_dfs(curr->next);
}
template <typename T>
void list<T>::InsertatTail(T value)
{
	v1.push_back(value);
	node* nnode = new node(value, NULL);
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
	Graphs(int vertices, bool isDirected) {
		this->vertices = vertices;
		this->isDirected = isDirected;
		this->Matrix = new list<int> *[this->vertices];
		for (int i = 0; i < this->vertices; i++) {
			Matrix[i] = new list<int>;
			Matrix[i]->InsertatTail(i);
		}
	}
	bool addEdge(int x, int y) {
		if (isDirected) {
			Matrix[x]->InsertatTail(y);
			return true;
		}
		else {
			Matrix[x]->InsertatTail(y);
			Matrix[y]->InsertatTail(x);
			return true;
		}
	}
	void DFS(int start, int visit[]) {
		cout << start << " ";
		visit[start] = 1;
		for (list<int>::listiterator x(Matrix[start]->get_head());x != NULL;x++) {
			if (visit[*x] == 1);
			else {
				DFS(*x, visit);
			}
		}
	}
	int dis_con(int start) {
		int count = 0;
		queue<int>q1;
		int* visit = new int[vertices];
		q1.push(start);
		visit[start] = 1;
		while (!q1.empty()) {
			int node = q1.front();
			q1.pop();
			visit[node] = 1;
			for (list<int>::listiterator x(Matrix[node]->get_head());x != NULL;x++) {
				if (visit[*x] != 1) {
					visit[*x] = 1;
					q1.push(*x);
				}
			}
		}
		for (int i = 0; i < vertices; i++){
			if (visit[i] != 1){
				count += 1;
				cout << i << " is univisted from " << start << endl;
            }
		}
		return count;
	}
	int all_discon() {
		int counter=0;
		for (int i = 0; i < vertices; i++){
			counter+=dis_con(i);
		}
		return counter;
	}
	void printGraph() {
		for (int i = 0; i < this->vertices; i++) {
			Matrix[i]->printList();
			cout << endl;
		}
	}// print the whole Matrix
	
};
int main() {
	Graphs g1(6, 1);
	g1.addEdge(3, 2);
	g1.addEdge(3, 1);
	g1.addEdge(1, 0);
	g1.addEdge(2, 1);
	g1.addEdge(0, 2);
	g1.addEdge(1, 3);
	g1.addEdge(4, 5);
	g1.addEdge(2, 5);
	g1.addEdge(5, 3);
	g1.printGraph();

	cout << endl;

	int visit[6];
	cout<<" Total un_conn edges are : "<<g1.all_discon();
	return 0;
}