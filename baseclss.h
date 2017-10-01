#include <iostream>
using namespace std;

template <typename T>
class Sequence
{
public:
	int length;
	Sequence() { length = 0; };
	virtual int Getlength() = 0;
	bool GetisEmpty() { return lehgth == 0; }
	virtual T Get(int ind) = 0;
	virtual T GetFirst() = 0;
	virtual T GetLast() = 0;
	virtual Sequence<T>& GetSubsequence(int FirstInd, int LastInd) = 0;
	virtual void Append(T item) = 0;
	virtual void Prepend(T item) = 0;
	virtual void InsertAt(T item, int ind) = 0;
	virtual void Remove(T item) = 0;
	virtual void show() = 0;

};
#pragma once
