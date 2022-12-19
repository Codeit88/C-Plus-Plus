#include<iostream>
#include<string>
using namespace std;
int sub_str(string& k, int a) {
	int size1 = k.size(), dis_elems, count = 0;
	for (int i = 0; i < size1 - a; i++) {
		dis_elems = 0;
		int hash_table[26] = {};
		for (int j = i; j<size1 && dis_elems<a; j++) {
			if (hash_table[k[j] - 97] == 0) {
				hash_table[k[j] - 97] = 1;
				dis_elems += 1;
			}
			if (dis_elems == a)
				count += 1;
		}
	}
	return  count;
}
int main() {
	string a("abbca");
	cout << sub_str(a, 3);
	return 0;
}
