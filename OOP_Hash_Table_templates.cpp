#include<iostream>
using namespace std;
template <class v>
struct Hash_Item{
	int key;
	v value;
	short status;
	Hash_Item() {
		this->key = 0;
		this->value = 0;
		this->status = 0;
	}
};
template <class v>
class Hash_Map{
protected:
	Hash_Item<v>* hashArray;
	int capacity;
	int currentElements;
	virtual int getNextCandidateIndex(int key, int i){
		if (this->hashArray[i].status == 0) {
			return i;
	    }
		else {
		      getNextCandidateIndex(key,(i+1) % this->capacity);
		}
	}
public:
	Hash_Map() {
		this->capacity = 10;
		hashArray = new Hash_Item<v>[this->capacity];
		this->currentElements = 0;
	}
	Hash_Map(int const capacity) {
		this->capacity = capacity;
		if (capacity < 1) {
			cout << " Error giving size ! \n";
			return;
		}
		this->currentElements = 0;
		hashArray = new Hash_Item<v>[this->capacity];
		for (int i = 0; i < this->capacity; i++){
			hashArray[i].status = 0;
			hashArray[i].key = 0;
			hashArray[i].value = 0;
		}
	}
	int home_index(int const key) {
		return key % capacity;
	}
	void insert(int const key, v const value) {
		this->currentElements++;
		int h_i = home_index(key);//home_index
		if (this->hashArray[h_i].status == 0) {
			this->hashArray[h_i].key = key;
			this->hashArray[h_i].value = value;
			this->hashArray[h_i].status = 2;
		}
		else if (this->hashArray[h_i].status == 2) {
			int d_i = getNextCandidateIndex(key, h_i);//destination index
			this->hashArray[d_i].key = key;
			this->hashArray[d_i].value = value;
			this->hashArray[d_i].status = 2;
		}
		float l_f = this->capacity/ this->currentElements;
		if (l_f < 2) //loading factor
			this->hashArray=double_size();
	}
	void print_table() {
		for (int i = 0; i < this->capacity; i++){
			cout << this->hashArray[i].value << " ";
		}
	}
	Hash_Item<v>* double_size() {
		this->capacity *= 2;
		Hash_Item<v>* nnew = new Hash_Item<v>[capacity];
		for (int i = 0; i < capacity/2; i++) {
			nnew[i] = this->hashArray[i];
		}
		delete[]hashArray;
		this->hashArray = new Hash_Item<v>[this->capacity];
		for (int i = 0; i < capacity; i++){
			this->hashArray[i] = nnew[i];
		}
		delete[]nnew;
		return this->hashArray;
	}
	bool deleteKey(v const key) {
		int h_i = home_index(key);
		if (hashArray[h_i].key == key) {
			hashArray[h_i].status = 1;
			return true;
		}
		else {
			int i = h_i;
			while (hashArray[i].key != key) {
				i = i + 1;
			}
			if (hashArray[i].key == key) {
				hashArray[i].status = 1;
				return true;
			}
			else
				return false;
		}
	
	}
	v get(v const key) {
		int h_i = home_index(key);
		if (hashArray[h_i].key == key) {
			return hashArray[h_i].value;
		}
		else {
			int i = h_i;
			while (hashArray[i].key != key) {
				i = i + 1;
			}
			if (hashArray[i].key == key) {
				return hashArray[h_i].value;
			}
			else
				return NULL;
		}
	}
	~Hash_Map() {
		delete[]this->hashArray;
	}
};
template <class v>
class QHashMap:public Hash_Map<v> {
protected:
	Hash_Item<v>* hashArray;
	int capacity;
	int currentElements;
	int getNextCandidateIndex(int key, int i) {
		int probe_it = 1,index=i;
		while (this->hashArray[index].status != 0) {
			index = (i + (probe_it * probe_it)) % this->capacity;
			probe_it += 1;
		}
		return index;
	}
public:
	QHashMap() {};
	QHashMap(int const capacity) {
		this->capacity = capacity;
		if (capacity < 1) {
			cout << " Error giving size ! \n";
			return;
		}
		this->currentElements = 0;
		this->hashArray = new Hash_Item<v>[this->capacity];
		for (int i = 0; i < this->capacity; i++) {
			this->hashArray[i].status = 0;
			this->hashArray[i].key = 0;
			this->hashArray[i].value = 0;
		}
	}
	~QHashMap() {
		delete [] this->hashArray;
	}
};
template <class v>
class DHashMap :public Hash_Map<v> {
protected:
	Hash_Item<v>* hashArray;
	int capacity;
	int currentElements;
	int getNextCandidateIndex(int key, int i) {
		int first = key % this->capacity;
		int sec = 3 - (key % 3);
		int index = first + (i * sec) % this->capacity;
			return index;
	}
public:
	DHashMap(){};
	DHashMap(int const capacity) {
		this->capacity = capacity;
		if (capacity < 1) {
			cout << " Error giving size ! \n";
			return;
		}
		this->currentElements = 0;
		this->hashArray = new Hash_Item<v>[this->capacity];
		for (int i = 0; i < this->capacity; i++) {
			this->hashArray[i].status = 0;
			this->hashArray[i].key = 0;
			this->hashArray[i].value = 0;
		}
	}
	~DHashMap() {
		delete[] this->hashArray;
	}
};
int main() {
	Hash_Map<int>h1(10);
	h1.insert(3, 43);
	h1.insert(4, 65);
	h1.insert(43, 654);
	h1.insert(65, 52);
	h1.insert(21, 543);
    h1.print_table();
    cout << endl;
    QHashMap <int>q1(10);
    q1.insert(3, 43);
    q1.insert(4, 65);
    q1.insert(43, 654);
    q1.insert(65, 52);
    q1.insert(21, 543);
    q1.print_table();
	cout << endl;
	DHashMap <int>d1(10);
	d1.insert(3, 43);
	d1.insert(4, 65);
	d1.insert(43, 654);
	d1.insert(65, 52);
	d1.insert(21, 543);
	d1.print_table();
	return 0;
}
