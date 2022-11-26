#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;
string open_file(string s1){
	string s2;
	ifstream obj(s1);
	if (!obj.is_open())
		cout << " File is not opened ! \n";
	else {
		obj >> s2;
	}
	obj.close();
	return s2;
}
vector<char> seperate_unique_chars(string &s2,vector<char> &v1) {
	for (int i = 0; i < s2.size(); i++) {
		for (int j = 0; j < s2.size(); j++)
		{
			if (s2[i] < s2[j]) {
				char temp = s2[i];
				s2[i] = s2[j];
				s2[j] = temp;
			}
		}
	}
	for (int i = 0; i < s2.size(); i++) {
		if (s2[i] == s2[i + 1])
			continue;
		v1.push_back(s2[i]);
	}
	return v1;
}
int*freq_counter(string &s2, vector<char>& v1,int*arr){
	for (int i = 0,k=0; i < v1.size(); i++,k++) {
		int counter = 0;
		for (int j = 0; j < s2.size(); j++){
			if (v1[i] == s2[j]) {
				counter++;
				continue;
			}
			continue;
		}
		arr[k] = counter;
	}
	return arr;
}
int main() {
	string *s1=new string,s2;
	vector<char> v1, v2;
	cout << " Enter the filename you want to open : ";
	cin >> *s1;
	s2=open_file(*s1);
	for (int i = 0; i < s2.size(); i++)
	{
		cout << s2[i] << " ";
	}
	cout << endl;
	v2 = seperate_unique_chars(s2, v1);
	/*for (int i = 0; i < s2.size(); i++) {
		v1.push_back(s2[i]);
	}*/
	for (int i = 0; i < s2.size(); i++)
	{
		cout << s2[i] << " ";
	}
	cout << endl;
	/*vector<string>* v1 = new vector<string>,*v2;
	v2 = seperate_unique_chars(s2, v1);*/
	for (int i = 0; i < v2.size(); i++) {
		cout << v2[i] << " ";
	}
	cout << endl;
	int* freq = new int[v2.size()],*freq2;
	freq2 = freq_counter(s2,v1,freq);
	for (int i = 0; i < v2.size(); i++) {
		cout << freq2[i] << " ";
	}
	return 0;
}
