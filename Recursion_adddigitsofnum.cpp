#include<iostream>
using namespace std;
int sumup(int num,int sum) {
	if (num == 0) {
		return sum;
	}
	else {
		return sumup(num/10,sum+(num%10));
	}
}
int main() {
cout<<sumup(4213551,0);
	return 0;
}
