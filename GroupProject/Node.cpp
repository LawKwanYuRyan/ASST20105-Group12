#include "stdafx.h"
#include "Node.h"

Node::Node()
{
	leaf = true;
	keyTally = -1;
	for (int i = 0; i < 7; i++)
	{
		pointers[i] = NULL;
	}
}

void Node::addById(Data d)
{
	string id = d.tconst;
	Data temp1,temp2;
	int i = 0;
	//search for insert posittiion
	while (id > keys[i].tconst && i<=keyTally)
	{
		i++;
	}
	for (int j = 0 ; j < 6 ; j++)
	{
		if (j == i)
		{
			temp1 = keys[j];
			keys[j] = d;
		}
		else if (j > i)
		{
			temp2 = keys[j];
			keys[j] = temp1;
		}
	}
	keyTally++;
}

void Node::addByName(Data d)
{
	string id = d.primaryTitle;
	Data temp1, temp2;
	int i = 0;
	while (id > (string)(keys[i].primaryTitle) && i <= keyTally)
	{
		i++;
	}
	for (int j = 0; j < 6; j++)
	{
		if (j == i)
		{
			temp1 = keys[j];
			keys[j] = d;
		}
		else if (j > i)
		{
			temp2 = keys[j];
			keys[j] = temp1;
		}
	}
}

void Node::removeById(Data d)
{
	int i = 0;
}
