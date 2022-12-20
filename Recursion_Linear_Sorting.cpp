//Written by Muhammad Sami Khokher
#include<iostream>
using namespace std;
void sort_array(int*arr,int size,int largest,int nested){
	if (largest == size)
		return;
	else {
		if (nested == size)
			sort_array(arr, size, largest + 1, largest+2);
		else if (arr[largest] > arr[nested]) {
			int temp = arr[largest];
			arr[largest] = arr[nested];
			arr[nested] = temp;
			sort_array(arr, size, largest, nested + 1);
		}
		else {
			sort_array(arr, size, largest, nested + 1);
		}
	}
}
int main() {
	int* arr{ new int[8] {62,538,987,3321,431,454,77,21} };
	cout << " Before sortion : ";
	for (int i = 0; i < 8; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	sort_array(arr, 8, 0, 1);
	cout << " After sortion : ";
	for (int i = 0; i < 8; i++) {
		cout << arr[i] << " ";
	}
	return 0;
}
