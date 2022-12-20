#include<iostream>
#include<string>
using namespace std;
void print_order(int ar[], int size,int counter) {
	if (counter == size)
		return;
	else {
		if (ar[counter] % 2 == 0) {
			cout << ar[counter] << " ";
		}
		print_order(ar, size, counter + 1);
		if (ar[counter] % 2 != 0) {
			cout << ar[counter] << " ";
		}
	}
}
int main() {
	int ar[8] = { 1,2,3,4,5,6,7,8 };
	print_order(ar, 8,0);
	return 0;
}
