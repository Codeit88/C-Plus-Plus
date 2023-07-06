#include<iostream>
using namespace std;
void printarr(int*arr,int &n){
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] <<" ";
	}
	cout << "\n";
}
int main() {
	int n = 0;
	cout << " Enter size : ";
	cin >> n;
	int* arr = new int[n];
	cout << " Enter array elems : ";
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	printarr(arr,n);
	int k = 0;
	for (int i = 0; i < n; i++)
	{
		if (*(arr+i) == 0) {
			if (arr[k] != 0) {
				swap(arr[i], arr[k]);
				k++;
			}
			else k++;
	  }
	}
	printarr(arr, n);
	delete[]arr;
	return 0;
}
