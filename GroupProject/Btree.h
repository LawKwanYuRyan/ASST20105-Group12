#pragma once
#ifndef BTREE_H
#define BTREE_H

#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <ctime>
using namespace std;

#include "Node.h"
#include "Data.h"

class Btree
{
private:
	//int levels represent amount of levels of the tree
	// top's levels = 0
	// levels increases by 1 every time when a new top is created
	// just for possible fulture needs
	int levels;
	int compairById(Data data,Node node);
	int compairByName(Data data, Node node);
public:
	Node* head;
// task 1
	void insertionId(Data d);//done
	void insertionName(Data d);//almost
	
// task 2 
	void deletionId(/*string idcode*/);	//to do first
	void deletionName(/*string name*/);

// task 3
	Data search(string str);	//to do first
// task 4 Statistical functions
	//provide a total number of movies produced in given year
	int moviesInYear(/*year value*/ /*bool print movie or not*/);
	//return max or min runtimeMinutes in all datas
	int movieInMin(/*bool min or max*//*bool print movie or not*/);
	//provide a total number of movies of a given type
	int moviesInType(/*type value*/ /*bool print movie or not*/);
//testing
	Btree();
	//print tree in accending order
	void print(Node* node);//done
};

#endif // !B+TREE_H