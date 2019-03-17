#pragma once
#include "stdafx.h"
#include <iostream>

using namespace std;

class List {

private:
	struct Node
	{
		int value;
		Node *next;
	};

	Node *first = NULL;
	int zero = 0;

	int & GetSetIndex(int);

public:

	void add(int);
	void print();
	int length();
	int value(int);
	void remove(int);

	int &operator [] (int);
	void sort(bool);
	List sorted(bool);
};