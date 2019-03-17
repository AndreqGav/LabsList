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

public:

	void add(int);
	void print();
	int length();
	int value(int);
	void remove(int);
};