#pragma once
#ifndef NODE_H
#define NODE_H

#include "stdafx.h"
#include <iostream>
using namespace std;
#include "Data.h"

class Node
{
public:
	bool leaf;
	int keyTally;
	Data keys[6];
	Node* pointers[7];

	Node();
	void addById(Data d);
	void addByName(Data d);
	void removeById(Data d);
	~Node()
	{
	//	delete[]keys;
	//	delete[]pointers;
	}
};

#endif // !NODE_H
