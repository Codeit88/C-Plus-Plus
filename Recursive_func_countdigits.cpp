#include<iostream>
using namespace std;
int digi(int num,int count) {
	if (num == 0) {
		return count;
	}
	else {
		num /= 10;
		count++;
		return digi(num, count);
	}
}
int main() {
	cout << digi(7456532,0);
	return 0;
}
