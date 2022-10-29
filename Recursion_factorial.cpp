#include<iostream>
using namespace std;
int  fact(int num,int rec){
	if (num == 0) {
		return rec;
	}
	else {
		rec *= num;
		num--;
		return fact(num, rec);
	}
}
int main() {
	cout << fact(6,1);
	return 0;
}
