// GroupProject.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <sstream>
#include <string>
#include <cstdio>
#include <ctime>
#include <iostream>
using namespace std;

#include "Data.h"
#include "Node.h"
#include "Btree.h"

int main()
{
	Btree tree;
	int num;
	clock_t start;
	string cat[3];
	int temp;
	ifstream infile;
	infile.open("DataSet1_50000.txt");
	start = clock();
	while (!infile.eof()) // To get you all the lines.
	{
		string line;
		Data data; int n;
		//code
		getline(infile, line, '\t');
		data.tconst = line;
		//type
		getline(infile, line, '\t');
		data.titleType = line;
		//name
		getline(infile, line, '\t');
		data.primaryTitle = line;
		//year
		getline(infile, line, '\t');
		istringstream(line) >> n;
		data.startYear = n;
		//min
		getline(infile, line, '\t');
		istringstream(line) >> n;
		data.runtimeMinutes = n;
		//arrtype
		getline(infile, line, '\n');
		int aa = 0;
		for (int i = 0; i < 3; i++)
		{
			cat[i] = "";
			data.genres[i] = "";
		}
		//cout << "inserted " << line << endl;
		for (int i = 1; i < line.size() - 1; i++)
		{
			if (line[i] != ',')
			{
				cat[aa] += line[i];
			}
			else
			{
				data.genres[aa] = cat[aa];
				aa++;
			}
		}
		tree.insertionId(data);
		cout << "inserted " << data.tconst << endl;
		//tree.print(tree.head);
	}
	int nn = (clock() - start) / (double)CLOCKS_PER_SEC;
	infile.close();
	cout << "insertion costed " << nn << " sec." << endl;
	cout << "print start" << endl;
	//tree.print(tree.head); 
	cout << "print end" << endl;
	system("pause");
    return 0;
}

