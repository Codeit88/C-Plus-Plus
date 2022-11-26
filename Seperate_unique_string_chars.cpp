#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main() {
	vector<char>v1;
	string s1("saaamiiiissad");
	for (int i = 0; i < s1.size(); i++){
		for (int j = 0; j < s1.size(); j++)
		{
			if(s1[i] < s1[j]) {
				char temp = s1[i];
				s1[i] = s1[j];
				s1[j] = temp;
			}
		}	
	}
	for (int i = 0; i < s1.size(); i++){
		if (s1[i] == s1[i + 1])
			continue;
		v1.push_back(s1[i]);
	}
	for (int i = 0; i < v1.size(); i++)
	{
		cout << v1[i] << " ";
	}
	return 0;
}
