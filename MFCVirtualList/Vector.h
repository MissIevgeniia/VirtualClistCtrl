#ifndef Vector_h
#define Vector_h

#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <windows.h>
#include <conio.h>
using namespace std;
typedef unsigned int uint;
template <class T>
void add_array(T*& a, uint& n, T val)
{
	T *temp = new T[++n];
	for (int i = 0; i < n; i++)
		temp[i] = (i < n - 1 ? a[i] : val);
	delete[]a;
	a = temp;
}
template <class T>
void del_array(T*& a, uint& n, int y)
{
	T *temp = new T[--n];
	for (int i = 0; i < y; i++)
		temp[i] = a[i];
	for (int i = y; i < n; i++)
		temp[i] = a[i + 1];
	delete[]a;
	a = temp;
}
template <class T>
class Vector {
	T *p;
	uint size;
public:
	Vector() : p(0), size(0) {};
	explicit Vector(uint);
	Vector(const Vector<T>&);
	~Vector();
	void Clear();
	Vector(T array[], uint arraysize);
	Vector operator=(const Vector<T>&);
	T operator[](int) const;
	uint Getsize() const { return size; }
	bool IsEmpty()const { return size == 0; };
	bool operator !()const { return IsEmpty(); };
	void add(T);
	void del(int);
};
template < class T>
Vector<T>::Vector(uint n) {
	size = n;
	if (size)
		p = new T[size];
	else p = nullptr;
}
template <class T>
Vector<T>::Vector(T array[], uint arraysize) {
	if (array&&arraysize) {
		p = new T[arraysize];
		for (int i = 0; i < arraysize; i++)
			p[i] = array[i];
	}
	else if (arraysize) p = new T[arraysize];
	else p = nullptr;
	size = arraysize;
}
template <class T>
Vector<T>::Vector(const Vector<T>&c) {
	size = c.size;
	if (size) {
		p = new T[size];
		for (int i = 0; i < size; i++)
			p[i] = c.p[i];
	}
	else p = nullptr;
}
template <class T>
Vector<T>::~Vector() {
	delete[]p;
}
template <class T>
void Vector<T>::Clear() {
	if (p) delete[]p;
	p = nullptr;
	size = 0;
}
template <class T>
Vector<T> Vector<T>::operator =(const Vector<T>&c) {
	if (this == &c) return*this;
	if (p) delete[]p;
	p = new T[c.size];
	for (int i = 0; i < c.size; i++)
		p[i] = c[i];
	size = c.size;
	return *this;
}
template <class T>
T Vector<T>:: operator[](int i) const {
	if (i < 0) return p[0];
	else if (i >= size) return p[size - 1];
	else return p[i];
}
template <class T>
void Vector<T>::add(T a) {
	add_array(p, size, a);
}
template <class T>
void Vector<T>::del(int i) {
	del_array(p, size, i);
}
template <class T>
ostream & operator << (ostream& os, const Vector<T>& c) {
	for (int i = 0; i < c.Getsize(); i++)
		cout << c[i];
	return os;
};
#endif Vector_h
#pragma once
