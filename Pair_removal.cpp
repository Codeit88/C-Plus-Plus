#include<iostream>
#include<stack>
#include<string>
using namespace std;
class Stack {
	char* arr;
	int top;
	int size;
public:
	Stack(int size) {
		this->top = -1;
		this->size = size;
		arr = new char[this->size];
	//	arr = {};
	}
	Stack(string &str,int size) {
		this->top = -1;
		this->size = size;
		arr = new char[size];
		for (int i = 0; i < size; i++){
			arr[i] = str[i];
			top++;
		}
	}
	void emplace(int &x,int y){
		int temp = arr[x];
		arr[x] = arr[y];
		arr[y] = temp;
	}
	char access(int &x){
		return arr[x];
	}
	void push(char val){
		top++;
		arr[top] = val;
	}
	char get_top() {
		return arr[top];
	}
	bool empty() {
		return  (top == -1);
	}
	char pop(){
		int z = arr[top];
		top--;
		return z;
	}
	void print() {
		for (int i = 0; i < top; i++)
		{
			cout << arr[i] << " ";
		}
	}
};
int main() {
	string s1("assassin");
	int i = 0;
	Stack s2(s1, 8),s3(8);
		while (!s2.empty()) {
			int counter = 0;
			for (int i = 0;i < 8;i++) {
				if (s2.get_top() == '0')
					s2.pop();
				else if (s2.get_top() == s2.access(i)) {
					counter++;
					if (counter > 1) {
						s2.emplace(i, '0');
						s2.pop();
						break;
					}
				}
			}
			if (counter == 1) {
				s3.push(s2.get_top());
				s2.pop();
			}
		}
	s3.print();
	return 0;
}
