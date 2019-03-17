#include "stdafx.h"
#include "List.h"

void List::add(int value)
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

void List::print()
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

int List::length()
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

int List::value(int index)
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

void List::remove(int index)
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