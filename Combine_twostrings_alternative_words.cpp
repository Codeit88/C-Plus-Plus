#include<iostream>
using namespace std;
int main() {
	char arr1[15] = { 'f','a','d','i',' ','i','s',' ','g','o','o','o','d','i','\0' };
	char arr2[10] = { 'n','o','t',' ','t','h','a','t','\0' };
	char comb[25];
	int m = 0, n = 0,q=0, count = 2;
	bool flag = false;
	for (int i = 0; arr1[m]!='\0' || arr2[n]!='\0'; i++)
	{
		if (count % 2 != 0) {
			comb[i] = arr2[n];
			n++;
			if (comb[i] == ' ' || comb[i] == '\0') {
				count++;
			}
		}
		else {
			comb[i] = arr1[m];
			m++;
			if (comb[i] == ' ' || comb[i] == '\0') {
				count++;
			}
		}
	}
	for (int i = 0; i < 23; i++)
	{
		cout << comb[i];
	}
	return 0;
}
