#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void binarycon(int num) {
	vector<int>p;
	while (num != 0) {
		int z = num % 2;
		p.push_back(z);
		num /=2;
    }
	int p1 = 4 - (int)p.size();
       for (int j = 1;j <= p1;j++)
      {
           p.push_back(0);
       }
       reverse(p.begin(), p.end());
	   for (int i = 0;i < p.size();i++) {
		   cout << p[i];
	   }
}
int main() {
	binarycon(10);
	return 0;
}
