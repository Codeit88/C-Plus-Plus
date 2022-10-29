#include<iostream>
using namespace std;
bool checksum(int* arr, int size, int flag, int i, int j, int k) {
	if (flag == 1) {
		return true;
	}
	else if (arr[i] + arr[j] == arr[k] && i < k && j < k && j != k && i != j) {
		return checksum(arr, size, flag + 1, i, j, k);
	}
	else if (arr[i] + arr[j] != arr[k] && j < k) {
		return checksum(arr, size, flag, i, j + 1, k);
	}
	else if (arr[i] + arr[j] != arr[k] && j == k && i < k) {
		return checksum(arr, size, flag, i + 1, i + 2, k);
	}
	else if (arr[i] + arr[j] != arr[k] && i == k && j == k || j > k) {
		i = 0;
		return checksum(arr, size, flag, i, i + 1, k + 1);
	}
	else {
		cout << " Sum not found !";
		return false;
	}
}
int main() {
	int size;
	cout << "Enter the size : ";
	cin >> size;
	int* arr = new int[size];
	cout << " Enter the elements : \n";
	for (int i = 0; i < size; i++) {
		cin >> arr[i];
	}
	bool found = checksum(arr, size, 0, 0, 1, 2);
	if (found == true) {
		cout << " Sum is found ! ";
	}
	return 0;
}
