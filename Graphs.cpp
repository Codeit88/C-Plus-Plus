#include<iostream>
using namespace std;
class Graphs {
private:
	int** Matrix;
	int vertices;// total number of vertices
	bool isDirected; // 0 for undirected, 1 for directed
public:
	Graphs(int vertices, bool isDirected) {
		this->vertices = vertices;
		this->isDirected = isDirected;
		this->Matrix = new int* [this->vertices];
		for (int i = 0; i < this->vertices; i++) {
			this->Matrix[i] = new int[this->vertices];
		}
		for (int i = 0; i < this->vertices; i++) {
			for (int j = 0; j < this->vertices; j++) {
				this->Matrix[i][j] = 0;
			}
		}
	}
	Graphs(const Graphs& obj) {
		this->vertices = obj.vertices;
		for (int i = 0; i < this->vertices; i++) {
			for (int j = 0; j < this->vertices; j++) {
				this->Matrix[i][j] = obj.Matrix[i][j];
			}
		}
	}
	Graphs(string fName);
	bool addEdge(int x, int y) {
		if (isDirected) {
			this->Matrix[x][y] = 1;
			return true;
		}
		else {
			this->Matrix[x][y] = 1;
			this->Matrix[y][x] = 1;
			return true;
		}
	}
	bool removeEdge(int x, int y) {
		if (isDirected) {
			this->Matrix[x][y] = 0;
			return true;
		}
		else {
			this->Matrix[x][y] = 0;
			this->Matrix[y][x] = 0;
			return true;
		}
	}
	bool isConnected(int x, int y) {
		if (Matrix[x][y] == 1 || Matrix[y][x] == 1)
			return true;
		else
			return false;
	}
	int getIndegree(int x) {
		int counter = 0;
		for (int i = 0; i < this->vertices; i++) {
			for (int j = 0; j < this->vertices; j++) {
				if (i == x) {
					if (Matrix[i][j] == 1)
						counter++;
				}
			}
		}
		return counter;
	}
	int getOutdegree(int x) {
		int counter = 0;
		for (int i = 0; i < this->vertices; i++) {
			for (int j = 0; j < this->vertices; j++) {
				if (j == x) {
					if (Matrix[i][j] == 1)
						counter++;
				}
			}
		}
		return counter;
	}
	void printAllAdjc(int x) {
		for (int i = 0; i < this->vertices; i++) {
			for (int j = 0; j < this->vertices; j++) {
				if (i == x) {
					if (Matrix[i][j] == 1)
						cout << j << " ";
				}
			}
		}
	}
	bool isComplete() {
		for (int i = 0; i < this->vertices; i++) {
			int counter = 0;
			for (int j = 0; j < this->vertices; j++) {
				if (this->Matrix[i][j] == 1)
					counter++;
			}
			if (counter < (this->vertices-1))
				return false;
		}
		return true;
	}// is every node connected to any other node
	void printGraph() {
		for (int i = 0; i < this->vertices; i++) {
			for (int j = 0; j < this->vertices; j++) {
				cout << this->Matrix[i][j] << " ";
			}
			cout << endl;
		}
	}// print the whole Matrix
	~Graphs() {
		for (int i = 0; i < this->vertices; i++) {
			delete[]this->Matrix[i];
		}
	}
};
int main() {
	Graphs g1(2, true);
	g1.addEdge(0, 1);
	g1.addEdge(1, 0);
	g1.printGraph();
	cout<<endl;
	cout << g1.getIndegree(0);
	
	cout<<endl;
	cout << g1.getOutdegree(0);
	cout<<endl;
	g1.printAllAdjc(3);
	if(g1.isComplete())
	cout<<"han";
	else
	cout<<"fkoff";
	return 0;
}
