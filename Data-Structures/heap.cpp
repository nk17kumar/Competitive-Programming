#include "bits/stdc++.h"
using namespace std;

template < class T >
class MinHeap {

private:

	int capacity;
	T* arr;
	int sz;
	int left(int idx) {
		return 2*idx + 1;
	}
	int right(int idx) {
		return 2*idx + 2;
	}
	int parent(int idx) {
		return (idx-1)/2;
	}
	void heapify(int idx) {
		int l = left(idx);
		int r = right(idx);
		int smallest = idx;
		if(l < sz and this->arr[l] < this->arr[smallest]) 
			smallest = l;
		if(r < sz and this->arr[r] < this->arr[smallest])
			smallest = r;
		swap(this->arr[idx],this->arr[smallest]);
		if(smallest != idx)
			heapify(smallest);
	}

public:

	MinHeap(int cap);
	bool push(T key);
	T extract_min();
	bool pop();
	int size();

};

template < class T > 
MinHeap < T > :: MinHeap(int cap) {
	this->capacity = cap;
	this->arr = new T[cap];
	this->sz = 0;
}

template < class T >
int MinHeap < T > :: size() {
	return this->sz;
}

template < class T >
bool MinHeap < T > :: push(T key) {
	if(this->sz == this->capacity) {
		cerr << "Overflow !!!" << endl;
		return false;
	}
	this->arr[sz] = key;
	this->sz++;
	int i = sz-1;
	while(i != 0 and this->arr[i] < this->arr[parent(i)]) {
		swap(this->arr[i],this->arr[parent(i)]);
		i = parent(i);
	}
	return true;
}

template < class T >
T MinHeap < T > :: extract_min() {
	if(this->sz == 0) {
		cerr << "Underflow !!!" << endl;
		return -1;
	}
	return this->arr[0];
}

template < class T >
bool MinHeap < T > :: pop() {
	if(sz == 0) {
		cerr << "Underflow !!!" << endl;
		return false;
	}
	swap(this->arr[0],this->arr[sz-1]);
	sz--;
	heapify(0);
	return true;
}

int main(int argc, char const *argv[])
{
	MinHeap < int > obj(5);
	obj.push(34);
	obj.push(12);
	obj.push(123);

	cout << obj.extract_min() << endl;
	obj.pop();
	cout << obj.extract_min() << endl;
	obj.pop();
	cout << obj.extract_min() << endl;

	cout << "sz : " << obj.size() << endl;
	return 0;
}