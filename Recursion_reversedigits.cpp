#include<iostream>
using namespace std;
int revdig(int& num, int rev, int rem) {
	if (num == 0) {
		return rev;
	}
	else {
		rem = num % 10;
		rev = rev * 10 + rem;
		num /= 10;
		return revdig(num, rev, rem);
	}
}
int main() {
	int no;
	cout << " Enter your number : ";
	cin >> no;
	cout << " Reversed number is : " << revdig(no, 0, 0);
	return 0;
}
