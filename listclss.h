#pragma once
#include <iostream>
#include <stdlib.h>
#include "baseclss.h"
#include <fstream>
using namespace std;

template <typename T>
class ListSequence : public Sequence <T> {
public:
	ListSequence() {
		Head = nullptr;
		length = 0;
	};
	~ListSequence() { delete[] Head };
	int Getlength() override { return length; };
	void Append(T item) //Добавляет элемент в очередь
	{
		cell* a;
		a = new cell;
		a->next = nullptr;
		a->component = item;
		cell* curr;
		if (length != 0) {
			curr = Head;
			for (int i = 0; i < length -1; i++)
			{
				curr = curr->next;
			};
			curr->next = a;
			(curr->next)->previous = curr;
		}
		else {
			Head = a;
			Head->previous = nullptr;
		};
		length++;
	};
	void show() {
		cell* write;
		write = Head;
		for (int i = 0; i < length; i++)
		{
			cout << write->component << " ";
			write = write->next;
		}
		cout << endl;
	};
	T Get(int ind) override {
		cell* curr = Head;
		int i = 0;
		if ((ind >= 0) && (ind < length))
		{			
			while  (i != ind) {
				i++;
				curr = curr->next;
			};
			return curr->component;
		}
		else throw indexOutOfRange();
	};
	T GetFirst() override {
		if (length != 0)
			return Head->component;
		else
			throw indexOutOfRange();
	};
	T GetLast() override {
		if (length != 0)
		{
			cell* curr = Head;
			for (int i = 0; i < length - 1; i++)
			{
				curr = curr->next;
			};
			return curr->component;
		}
		else
			throw indexOutOfRange();
	};
	Sequence <T>& GetSubsequence(int FirstInd, int LastInd) override {
		int i = 0;
		ListSequence <T>*SubSeq = new ListSequence <T>;
		if (FirstInd < 0 || FirstInd >= length || LastInd < 0 || LastInd >= length || FirstInd > LastInd)
			throw indexOutOfRange();
		else {			
			cell* curr = Head;
			while (i != FirstInd)
			{
				curr = curr->next;
				i++;
			};
			for (int i = FirstInd; i < LastInd + 1; i++)
			{
				SubSeq->Append(curr->component);
				curr = curr->next;
			};
		};
		return *SubSeq;
	};
	void Prepend(T item) override
	{
		cell* a = new cell;
		a->component = item;
	if (length != 0)
	{
		a->next = Head;
		Head->previous = a;
		Head = a;
		Head->previous = nullptr;
	}
	else
	{
		Head->component = item;
	};
	length++;
	};
	void InsertAt(T item, int ind)
	{
		int i = 0;
		cell* a = new cell;
		a->component = item;
		if (length != 0)
		{
			cell* curr = Head;
			while (i != ind-1)
			{
				curr = curr->next;
				i++;
			};
			curr->next->previous = a;
			a->previous = curr;
			a->next = curr->next;
			curr->next = a;			
		}
		else
		{
			Head = a;
		};
		length++;
	};
	void Remove(T item) 
	{
		int i = 0;
		cell* curr = Head;
		while ((curr->component != item) && (i < length -1))
		{
			curr = curr->next;
			i++;
		};
		if (i < length -1 && i!=0 && curr->component == item)
		{
			curr->previous->next = curr->next;
			curr->next->previous = curr->previous;
			length--;
		}
		else if (i == length - 1 && curr->component == item)
		{
			curr->previous->next = nullptr;
			length--;
		}
		else if (i == 0)
		{
			Head = Head->next;
			Head->previous = nullptr;
			length--;
		}
	};
private:
	struct cell {
		T component;
		cell* next;
		cell* previous;
	};
	cell *Head;
};