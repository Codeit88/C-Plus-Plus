#include<iostream>
#include<stdlib.h>
#include<ctime>
using namespace std;
struct Hash_Item {
	int val;
	bool status;
	Hash_Item() {
		this->val=0;
		this->status = false;
	}
	Hash_Item(int val) {
		this->val = val;
		this->status = false;
	}
};
class Hash_Table {
  private:
	int currsize,size;// Size will always be odd
	Hash_Item* arr;
  public:
	  Hash_Table() {
		  this->currsize = 0;
		  this->size = 0;
		  this->arr = NULL;
	  }
	  Hash_Table(int size){
		  this->currsize = 0;
		  this->size = size;
		  this->arr = new Hash_Item[this->size];
	  }
	  //Hash_Table(int method,bool rehash) {}
	  Hash_Item access(int index) {
		  return this->arr[index];
	  }
	  void Update(int &key,int val) {
		  for (int i = 0; i < this->size; i++)	  {
			  if (arr[i].val == key)
				  arr[i].val = val;
		  }
	  }
	  int Hash_it(int &val){
		  return val % 10;
	  }
	  void insert(int val){
		 /* this->currsize += 1;
		  if (currsize > (this->size / 2)) {
			  this->size *= 2;
		  }*/
		  int index = Hash_it(val);
		  if (arr[index].status == false) {
			  arr[index].val = val;
			  arr[index].status = true;
		  }
		  else {
			  char a;
			  cout << " Which method would you choose for Collision resolution : \n";
			  cout << " 1: Linear probing . \n";
			  cout << " 2: Linear probing(Steps). \n";
			  cout << " 3: Pseudo Random . \n";
			  cout << " 4: Double Hashing . \n";
			  cin >> a;
			  if (a == '1')
				  linear_probe(index,val);
			  else if (a == '2')
				  linear_probe_steps(index, val);
			  else if (a == '3')
				  pseudo_random_probe(index, val);
			  else if (a == '4')
				  double_hashing(index, val);
			  print_table();
			  cout << endl;
		  }
	  }
	  void double_hashing(int& index, int& val) {
		  int i = 1;
		  int hf2 = 1 + (val % 8);//8-(val%8);
			  i = index % 10;
			  index = (i + hf2) % 10;
		  arr[index].val = val;
		  arr[index].status = true;
	  }
	  void pseudo_random_probe(int& index, int& val){
		  unsigned seed = time(0);
		  srand(seed);
		  int r=0,i=0;
		  while (arr[index].status != false) {
			  r = 2 * val + rand() % 10;
			  index = r % 10;
		  }

		  arr[index].val = val;
		  arr[index].status = true;
	  }
	  void linear_probe(int &index,int &val) {
		  int i = 1;
		  while (arr[index].status != false) {
			  index = (index + i) % 10;
		  }
		  arr[index].val = val;
		  arr[index].status = true;
	  }
	  void linear_probe_steps(int& index, int& val) {
		  int i = 1;
		  while (arr[index].status != false) {
			  index = (index + i*3) % 10;
		  }
		  arr[index].val = val;
		  arr[index].status = true;
	  }
	  void delete_val(int val) {
		  for (int i = 0; i < this->size; i++){
			  if (arr[i].val == val) {
				  for (int j = i; j < this->size; j++) {
					  arr[j] = arr[j+1];
				  }
			  }
		  }
		 this->size--;
	  }
	  void print_table() {
		  for (int i = 0; i < this->size; i++){
			  cout << arr[i].val << " ";
		  }
	  }
};
int main() {
	Hash_Table h1(10);
	h1.insert(43);
	h1.insert(74);
	h1.insert(53);
	h1.insert(57);
	h1.insert(75);
	h1.insert(41);
	h1.insert(45);
	h1.insert(76);
	h1.insert(51);
	cout << endl;
	return 0;
}
