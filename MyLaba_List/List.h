#pragma once
#include "stdafx.h"
#include <iostream>

using namespace std;

struct Node
{
	int value;
	Node *next;
};

void add(Node **, int);
void print(Node*);
int length(Node *);
int value(Node *, int);
void remove(Node**, int);