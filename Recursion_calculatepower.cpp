#include<iostream>
using namespace std;
 int powerup(int num,int power,int res) {
	if (power == 0) {
		return res;
	}
	else {
		return powerup(num,power-1,res*num);
	}
}
int main() {
cout<<powerup(5,5,1);
	return 0;
}
