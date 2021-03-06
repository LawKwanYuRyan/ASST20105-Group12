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
	
	string cat[3];
	int temp;
	ifstream infile;
	cout << "enter file name : ";
	string hh;
	cin >> hh;
	clock_t start;start = clock();
	infile.open(hh);
	
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
		for (int i = 0; i < line.size(); i++)
		{
			if (line[i] != ',' && line[i] != '"')
			{
				cat[aa] += line[i];
			}
			else if(line[i] == ',')
			{
				data.genres[aa] = cat[aa];
				//cout << data.genres[aa] <<" , ";
				aa++;
			}
		}
		data.genres[aa] = cat[aa];
		//cout << data.genres[aa] << " , ";
		tree.insertionId(data);
		cout << "inserted " << data.tconst << endl;
		//tree.print(tree.head);
	}
	double nn = (clock() - start) / (double)CLOCKS_PER_SEC;
	infile.close();
	cout << "insertion costed " << nn << " sec." << endl;
	int tem=0;
	for (;;)
	{
		cout << "Action 1,search : 2,delete : 3,statistical functions : 4,print : 5,modify\nEnter action : ";
		cin >> tem;
		switch (tem)
		{
		case 1:
		{
			string tt;
			tt = "";
			cout << "Search :";
			cin >> tt;
			Data ttd = tree.search(tt);
			if (ttd.tconst == "empty")
				cout << "not found" << endl;
			else
			{
				cout << ttd.tconst << " " << ttd.titleType << " " << ttd.primaryTitle << " " << ttd.startYear << " " << ttd.runtimeMinutes << " \" ";
				for (int i = 0; i < 3; i++)
				{
					cout << ttd.genres[i] << " ";
				}
				cout << "\"\n" << endl;
			}
			
			break;
		}
		case 2:
		{
			cout << "Enter deleting data's id code : ";
			string tt;
			cin >> tt;
			tree.deletionId(tt);
			break;
		}
		case 3:
		{
			int tem1 = 0;
			cout << "Action 1,amount in year : 2,amount in type \nEnter action : ";
			cin>>tem1;
			switch (tem1)
			{
			case 1:
			{
				int nn;
				cout << "Enter year to search : ";
				cin >> nn;
				cout << "Total "<<tree.searchByYear(tree.head, nn) << " match found.\n" <<endl;
				break;
			}
			case 2:
			{
				string nn;
				cout << "Enter type to search : ";
				cin >> nn;
				if(nn!="movie")
					cout << "Total " << tree.searchByType(tree.head, nn) << " match found.\n" << endl;
				else
					cout << "Total " << tree.searchByTypeM(tree.head, nn) << " match found.\n" << endl;
				break;
			}
			default:
				break;
			}
			
			break;
		}
		case 4:
		{
			cout << "print start" << endl;
			tree.print(tree.head);
			cout << "print end" << endl;
			break;
		}
		case 5:
		{
			cout << "Enter id to modify : ";
			string stem;
			cin >> stem;
			tree.modify(stem);
			break;
		}
		default:
			break;
		}
		
		
	}
	
	/*
	cout << "print start" << endl;
	tree.print(tree.head); 
	cout << "print end" << endl;
	*/
	system("pause");
    return 0;
}

