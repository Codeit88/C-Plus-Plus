#include<iostream>
#include<vector>
using namespace std;
class Min_Heap {
	vector<int>v1;
public:
	Min_Heap() {
		v1.resize(0);
	}
	void insert(int x){
		v1.resize(v1.size() + 1);
		int index = v1.size() - 1;
		v1[index] = x;
		while (index != 0 && v1[index] < v1[(index-1) / 2]) {
			swap(v1[index], v1[(index-1)/ 2]);
			index =(index-1)/2;
		}
	}
	void extract_min() {
		swap(v1[0],v1[v1.size()-1]);
		v1.resize(v1.size() - 1);
		heapify(0);
	}
	void heapify(int x) {
		int smallest = x,
			left=2*x+1,
			right=2*x+2;
		if (left < v1.size() && v1[left] < v1[smallest])
			smallest = left;
		if (right < v1.size() && v1[right] < v1[smallest])
			smallest = right;
		if (smallest != x) {
			swap(v1[smallest], v1[x]);
			heapify(smallest);
		}
	}
	void swap_val(int x,int y){
		int index = 0;
		for (int i = 0; i < v1.size(); i++){
			if (v1[i] == x) {
				v1[i] = y;
				index = i;
				break;
			}
		}
		heapify(index);
	}
	void print() {
		int temp = v1.size();
		for (int i = 0; i < temp; i++){
			cout << v1[i] << " ";
		}
		cout<<endl;
	}
};
int main() {
	Min_Heap m1;
	m1.insert(19);
	m1.insert(12);
	m1.insert(9);
	m1.insert(7);
	m1.insert(5);
	m1.insert(2);
	m1.print();
	return 0;
}
