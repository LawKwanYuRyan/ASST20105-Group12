#pragma once
#ifndef BTREE_H
#define BTREE_H

#include "stdafx.h"
#include <iostream>
using namespace std;

#include "Node.h"
#include "Data.h"

class Btree
{
private:
	
	int compairById(Data data,Node node);
public:
	Node* head;
// task 1
	void insertionId(Data d);
	Data insertionName(Node node,Data data);
	Data insertionType(Node node,Data data);
// task 2 
	void deletionId(/*string idcode*/);
	void deletionName(/*string name*/);
	void deletionType(/*string type*/);
// task 3
	void search(/*different types of datas should be able to be used for searching*/);
// task 4 Statistical functions
	//provide a total number of movies produced in given year
	int moviesInYear(/*year value*/ /*bool print movie or not*/);
	//return max or min runtimeMinutes in all datas
	int movieInMin(/*bool min or max*//*bool print movie or not*/);
	//provide a total number of movies of a given type
	int moviesInType(/*type value*/ /*bool print movie or not*/);
//testing
	Btree();
	void print(Node* node);
};

#endif // !B+TREE_H