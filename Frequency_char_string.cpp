#include<iostream>
#include<string>
using namespace std;
int main() {
	string s1("saaamiiiissad");
	int size = s1.size(),k=0;
	int *length=new int[size];
	for (int i = 0; i < size; i++) {
		int counter = 0;
		for (int j = 0; j < size; j++)	{
			if (j < i && s1[i] == s1[j])
				break;
			if (i != j) {
				if (s1[i] == s1[j]) {
					counter++;
				}
		   }
		}
		length[k] = counter;
		k++;
	}
	for (int i = 0; i < size; i++)
	{
		if(length[i]!=0)
		cout << length[i];
	}
	return 0;
}
