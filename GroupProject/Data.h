#pragma once
#ifndef DATA_H
#define DATA_H

#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;
class Data
{
public:
	string tconst;
	string titleType;
	string primaryTitle;
	int startYear;
	int runtimeMinutes;
	string genres[3];

	Data();
	Data(string code, string type, string title, int year, int min, string gen[]);
};

#endif // !DATA_H
