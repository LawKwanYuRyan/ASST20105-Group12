#include "stdafx.h"
#include "Data.h"

Data::Data()
{
	tconst = "Empty";
	titleType = "";
	primaryTitle = "";
	startYear = 0;
	runtimeMinutes = 0;
	for (int i = 0; i < 3; i++)
	{
		genres[i] = "";
	}
}

Data::Data(string code, string type, string title, int year, int min, string gen[])
{
	tconst = code;
	titleType = type;
	primaryTitle = title;
	startYear = year;
	runtimeMinutes = min;
	for (int i = 0; i < 3; i++)
	{
			genres[i] = gen[i];
	}
}
