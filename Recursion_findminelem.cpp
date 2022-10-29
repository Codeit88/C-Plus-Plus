#include<iostream>
using namespace std;
int findmin(int *arr,int size,int min) {
	if (size == 0) {
		return min;
	}
	else if(min>arr[size-1]) {
		min = arr[size-1];
		return findmin(arr,size-1,min);
	}
	return findmin(arr, size - 1, min);
}
int main() {
	int* arr = new int[100], size;
	cout << " Enter the size : ";
	cin >> size;
	cout << " Enter the elements : \n";;
	for (int i = 0; i < size; i++){
		cin >> arr[i];
	}
	cout << findmin(arr,size,arr[0]);
	return 0;
}
