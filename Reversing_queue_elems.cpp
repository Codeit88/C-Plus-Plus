//Written by Muhammad Sami Khokher
#include<iostream>
#include<queue>
#include<stack>
using namespace std;
int main() {
	queue<int>q1;
	stack<int>s1;
	for (int i = 1; i <= 6; i++){
		q1.push(i * 10);   ///pushing queue elements
	}
	int a = q1.size();
	for (int i = 0; i < 4; i++){
		s1.push(q1.front());
		q1.pop();     ///pushing elems to be reversed into stack
	}
	for (int i = 0;i < 4;i++) {
		q1.push(s1.top());      ///re adding them in queue
		s1.pop();
	}
	for (int i = 0; i < (a-4); i++)
	{
		int a = q1.front();
		q1.pop();               ///times for rearranging
		q1.push(a);
	}
	while(!q1.empty())
	{
		cout << q1.front()<<" ";q1.pop();
	}
	return 0;
}
