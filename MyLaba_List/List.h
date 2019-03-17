#pragma once
#include "stdafx.h"
#include <iostream>

using namespace std;

template<class T>
class List {

private:
	struct Node
	{
		T value;
		Node *next;
	};

	Node *first = NULL;
	T zero = 0;

	T & GetSetIndex(int);

public:

	void add(T);
	void print();
	int length();
	T value(int);
	void remove(int);

	T &operator [] (int);
	void sort(bool);
	List<T> sorted(bool);
};

template<class T>
void List<T>::add(T value)
{
	Node *pv = new Node;
	pv->value = value;
	pv->next = NULL;

	if (first == NULL)
	{
		first = pv;
	}
	else
	{
		Node *cur;
		cur = first;

		while (cur->next != NULL)
		{
			cur = cur->next;
		}
		cur->next = pv;
	}
}

template<class T>
void List<T>::print()
{
	if (first == NULL) {
		cout << "empty" << endl;
		return;
	}
	Node *cur = first;

	while (cur != NULL)
	{
		cout << cur->value << ' ';
		cur = cur->next;
	}
	cout << endl;
}

template<class T>
int List<T>::length()
{
	if (first == NULL)
		return 0;

	Node *cur = first;
	int i = 1;
	while (cur->next != NULL)
	{
		++i;
		cur = cur->next;
	}
	return i;
}

template<class T>
T List<T>::value(int index)
{
	Node *cur;
	if (index > (length() - 1) || index < 0)
	{
		cerr << "Индекс вышел за грани списка \n";
		return 0;
	}
	else
	{
		cur = first;
		int i = 0;
		while (i < index)
		{
			cur = cur->next;
			++i;
		}
	}
	return cur->value;
}

template<class T>
void List<T>::remove(int index)
{
	if (first == NULL)
	{
		cerr << "Список пуст!";
		return;
	}
	else
	{
		if (index > (length() - 1) || index < 0)
		{
			cerr << "Не найдет элемент с заданным индексом\n";
			return;
		}
		Node *cur = first;
		Node *prev = NULL;
		int i = 0;

		while (i != index)
		{
			prev = cur;
			cur = cur->next;
			++i;
		}
		if (prev != NULL) {
			prev->next = cur->next;
		}
		else
		{
			first = cur->next;
		}
		delete cur;
	}
}

template<class T>
T & List<T>::GetSetIndex(int index)
{
	zero = 0;

	if (index > (length() - 1) || index < 0)
	{
		cerr << "Индекс вышел за грани списка \n";
	}
	else
	{
		int i = 0;
		Node *pv = first;
		while (i != index)
		{
			pv = pv->next;
			++i;
		}
		return pv->value;
	}
	return zero;
}

template<class T>
T & List<T>:: operator[](int index)
{
	return GetSetIndex(index);
}

template<class T>
void List<T>::sort(bool ascending)
{
	int len = length();

	Node *cur_i, *cur_j;
	int i, j;
	for (cur_i = first, i = 0; i < len - 1; cur_i = cur_i->next, i++)
	{
		for (cur_j = first, j = 0; j < len - i - 1; cur_j = cur_j->next, j++)
		{
			int a = cur_j->value, b = cur_j->next->value;

			if (a > b && ascending || a < b && !ascending)
			{
				swap(cur_j->value, cur_j->next->value);
			}
		}
	}
}

template<class T>
List<T> List<T>::sorted(bool ascending)
{
	List newList;
	for (int i = 0; i < length(); ++i)
	{
		newList.add(value(i));
	}
	newList.sort(ascending);
	return newList;
}