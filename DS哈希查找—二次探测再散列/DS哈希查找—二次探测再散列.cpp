#include <iostream>
using namespace std;
int temp ;
class HashTable {
private:
	int* data;
	int size;
public:
	HashTable(int n) {
		size = n;
		data = new int[size+100];
		for (int i = 0; i < size; i++) {
			data[i] = -1;
		}
	}
	int Hash(int n) {
		return n % 11;
	}
	void insert(int n, int hash) {
		hash %= size;
		if (data[hash] == -1) {
			data[hash] = n;
		}
		else {
			int i = 1;
			while (1) {
				if (data[(hash + i * i) % size] == -1) {
					data[(hash + i * i) % size] = n;
					break;
				}
				else {
					if ((hash - i * i) >= 0) {
						if (data[(hash - i * i)] == -1) {
							data[(hash - i * i)] = n;
							break;
						}
					}
					else {
						if (data[size + (hash - i * i)] == -1) {
							data[size + (hash - i * i)] = n;
							break;
						}
					}
				}
				i++;
			}
		}
	}
	void search(int find) {
		int times = 0, index = 0;
		int hash = Hash(find);
		int i = 1;
		int flag = 1, sum = hash;
		while (1) {  
			times++;
			if (data[sum] == find) {
				cout << "1 " << times << " " << sum + 1 << endl;
				return;
			}
			if (data[sum] == -1) {
				cout << "0 " << times <<endl;
				return;
			}
			if (flag) { 
				flag = 0;
				sum = hash + i * i; 
				sum %= size;
			}
			else {
				flag = 1;
				sum = hash - i * i; 
				if (sum < 0) {
					sum = size + sum;
				}
				i++;
			}

		}
	}
	void print() {
		temp = 0;
		for (int i = 0; i < size; i++) {
			if (data[i] > 0) {
				if (temp == 0)
				{
					cout << data[i];
					temp++;
				}
				else 
				{
				cout <<" "<< data[i] ;
				}
			}
			else {
				if (temp == 0)
				{
					cout << "NULL";
					temp++;
				}
				else
				{
					cout << " " << "NULL";
				}
			}
		}
		cout << endl;
	}
	~HashTable() {
		delete[] data;
	}
};

int main() {
	int t;
	cin >> t;
	while (t--) {
		int size, n;
		cin >> size >> n;
		HashTable h(size);
		while (n--) {
			int data;
			cin >> data;
			h.insert(data, h.Hash(data));
		}
		h.print();
		int k;
		cin >> k;
		while (k--) {
			int find;
			cin >> find;
			h.search(find);
		}
	}
	return 0;
}
