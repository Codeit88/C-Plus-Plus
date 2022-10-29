#include<iostream>
using namespace std;
bool checksum(int*arr,int &size,int k,int j,int m,int counter) {
	if (counter == (size-2)) {
		return false;
	}
	//int* arr{ new int[7] {2,7,3,11,5,99,6} };

	else if (arr[k] + arr[j] == arr[m]) {
		return true;
	}
	else if(m == size) {
		m = j + 1;
		k += 1;
		j += 1;
		counter += 1;
	}
	else if(m>j)
		return checksum(arr,size,k,j+1,m,counter);
	else if(j==m && k<j)
		return checksum(arr, size, k+1, j, m, counter);
	k = 0;
	j = 1;
	return checksum(arr, size, k , j, m+1, counter);

}
int main() {
	int* arr=new int[100], size;
	cout << " Enter size : ";
	cin >> size;
	cout << " Enter the values : \n";
	for (int i = 0;i < size;i++) {
		cin >> arr[i];
	}
	/*int size = 7;
	int* arr{ new int[7] {2,7,3,11,13,99,6} };*/
	bool check = checksum(arr,size,0,1,2,0);
	if (check == true) {
		cout << " Yes sum exists !";
	}
	else
		cout << " No sum doesnt exist !";
	return 0;
}
