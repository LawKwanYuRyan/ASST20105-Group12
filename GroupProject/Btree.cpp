#include "stdafx.h"
#include "Btree.h"

int Btree::compairById(Data data, Node node)
{
	int num = 0;
	while (data.tconst>node.keys[num].tconst && num <= node.keyTally)
		num++;
	if (data.tconst == node.keys[num].tconst)
		return num+10;
	else
		return num;
}

int Btree::compairByName(Data data, Node node)
{
	int num = 0;
	while ((string)data.primaryTitle > (string)node.keys[num].primaryTitle && num <= node.keyTally)
		num++;
	if ((string)data.primaryTitle == (string)node.keys[num].primaryTitle)
		return num + 10;
	else
		return num;
}

void Btree::insertionId(Data d)
{
	Node* currentNode;
	currentNode = head;
	Data data = d;
	Data tempd,temp1,temp2;
	static Node* arr[10];
	Node* temp[10];
	int pt[10];
	int num,counter=1,tempc=0;	
	//first data
	if (head == NULL)
	{
		Node* nn = new Node();
		head = nn;
		head->keys[0]=d;
		head->leaf = true;
		head->keyTally = 0;
		cout << "first node added" << endl;
	}
	else
	{
		//reaching to leaf
		while (currentNode->leaf == false)
		{
			arr[counter] = currentNode;
			num = compairById(d, *currentNode);
			pt[counter] = num;
			currentNode = currentNode->pointers[num];
			counter++;
		}
		//cout << "passed while" << endl;
		//reached leaf
		//leaf node still have space
		if (currentNode->keyTally < 5)
		{
			currentNode->addById(data);
		}
		//leaf node is full
		//counter showing current level, 1 = at top
		else
		{
			arr[counter] = currentNode;
			num = compairById(d, *currentNode);
			pt[counter] = num;
			data = d;
			for (int i = counter; i >= 0; i--)
			{
				//pushed up to a node that have spase
				if (arr[i]->keyTally < 5)
				{
					//
					Data dd[6];
					Node* pp[7];
					int ar = 0;
					pp[0] = arr[i]->pointers[0];
					for (int j = 0; j < 6; j++)
					{
						if (j == pt[i])
						{
							dd[j] = data;
							if (arr[i]->leaf == false)
								pp[j + 1] = temp[tempc - 1];
						}
						else
						{
							dd[j] = arr[i]->keys[ar];
							pp[j + 1] = arr[i]->pointers[ar + 1];
							ar++;
						}
					}
					arr[i]->pointers[0] = pp[0];
					for (int j = 0; j < 6; j++)
					{
						arr[i]->keys[j] = dd[j];
						arr[i]->pointers[j + 1] = pp[j + 1];
					}
					arr[i]->keyTally++;
					//
					
					break;
				}
				//node is full
				else
				{
					//temp Data & pt arr with one extra slot to hold the pushed data 
					Data dd[7];
					Node* pp[8];
					int ar = 0;
					//first pointer can't change
					pp[0] = arr[i]->pointers[0];
					for (int j = 0; j < 7; j++)
					{
						if (j == pt[i])
						{
							dd[j] = data;
							if(arr[i]->leaf==false)
								pp[j + 1] = temp[tempc-1];
						}
						else
						{
							dd[j] = arr[i]->keys[ar];
							pp[j + 1] = arr[i]->pointers[ar + 1];
							ar++;
						}
					}
					temp[tempc] = new Node();
					temp[tempc]->leaf = arr[i]->leaf;
					temp[tempc]->keyTally = 2;
					arr[i]->keyTally = 2;
					arr[i]->pointers[0] = pp[0];
					temp[tempc]->pointers[0] = pp[4];
					for (int j = 0; j < 3; j++)
					{
						arr[i]->keys[j] = dd[j];
						arr[i]->pointers[j + 1] = pp[j + 1];
						temp[tempc]->keys[j] = dd[j+4];
						temp[tempc]->pointers[j + 1] = pp[j+5];
					}
					/*
					for (int k = 0; k < 3 ; k++)
					{
						cout << arr[i]->keys[k].tconst<<"::";
					}
					cout << endl;
					*/
					//dd[3] = the middle data that has to be pushed up
					data = dd[3];
					tempc++;
					//needed new top
					if (counter == 1 || i==1)
					{
						levels++;
					//	cout <<"1. "<< arr[i]->keyTally << endl;
					//	cout << "new top"<<endl;
					//	cout << "Error new top 01" << endl;
						arr[0] = new Node();
						arr[0]->keyTally = 0;
						arr[0]->leaf = false;
					//	cout << "Error new top 02" << endl;
						head = arr[0];
					//	cout << "Error new top 03" << endl;
						head->keys[0] = data;
					//	cout << "Error new top 04" << endl;
					//	cout << "2. " << arr[i]->keyTally << endl;
						head->pointers[0] = arr[i];
					//	cout << "3. " << arr[i]->keyTally << endl;
						/*
						cout << "Left = ";
						for (int k = 0; k <= arr[i]->keyTally; k++)
						{
							cout << i + 1 << " : " << arr[i]->keys[k].tconst << " . ";
						}
						cout << endl;
						*/
					//	cout << "Error new top 05" << endl;
						head->pointers[1] = temp[tempc - 1];
						/*
						cout << "Right = ";
						for (int k = 0; k <= head->pointers[1]->keyTally; k++)
						{
							cout << i + 1 << " : " << head->pointers[1]->keys[k].tconst << " . ";
						}						
						cout << endl;
						*/
					//	cout << "Error new top 06" << endl;
						for (int k = 2; k < 7; k++)
						{
							head->pointers[k] = NULL;
						}
						break;
					}
					

				}
			}
		}
	}
}

void Btree::insertionName(Data d)
{
	Node* currentNode;
	currentNode = head;
	Data data = d;
	Data tempd, temp1, temp2;
	static Node* arr[10];
	Node* temp[10];
	int pt[10];
	int num, counter = 1, tempc = 0;
	//first data
	if (head == NULL)
	{
		Node* nn = new Node();
		head = nn;
		head->keys[0] = d;
		head->leaf = true;
		head->keyTally = 0;
		cout << "first node added" << endl;
	}
	else
	{
		//reaching to leaf
		while (currentNode->leaf == false)
		{
			arr[counter] = currentNode;
			num = compairByName(d, *currentNode);
			cout << num << endl;
			pt[counter] = num;
			currentNode = currentNode->pointers[num];
			counter++;
		}
		//cout << "passed while" << endl;
		//reached leaf
		//leaf node still have space
		if (currentNode->keyTally < 5)
		{
			currentNode->addByName(data);
		}
		//leaf node is full
		//counter showing current level, 1 = at top
		else
		{
			arr[counter] = currentNode;
			num = compairByName(d, *currentNode);
			pt[counter] = num;
			data = d;
			for (int i = counter; i >= 0; i--)
			{
				//pushed up to a node that have spase
				if (arr[i]->keyTally < 5)
				{
					//
					Data dd[6];
					Node* pp[7];
					int ar = 0;
					pp[0] = arr[i]->pointers[0];
					for (int j = 0; j < 6; j++)
					{
						if (j == pt[i])
						{
							dd[j] = data;
							if (arr[i]->leaf == false)
								pp[j + 1] = temp[tempc - 1];
						}
						else
						{
							dd[j] = arr[i]->keys[ar];
							pp[j + 1] = arr[i]->pointers[ar + 1];
							ar++;
						}
					}
					arr[i]->pointers[0] = pp[0];
					for (int j = 0; j < 6; j++)
					{
						arr[i]->keys[j] = dd[j];
						arr[i]->pointers[j + 1] = pp[j + 1];
					}
					arr[i]->keyTally++;
					//

					break;
				}
				//node is full
				else
				{
					//temp Data & pt arr with one extra slot to hold the pushed data 
					Data dd[7];
					Node* pp[8];
					int ar = 0;
					//first pointer can't change
					pp[0] = arr[i]->pointers[0];
					for (int j = 0; j < 7; j++)
					{
						if (j == pt[i])
						{
							dd[j] = data;
							if (arr[i]->leaf == false)
								pp[j + 1] = temp[tempc - 1];
						}
						else
						{
							dd[j] = arr[i]->keys[ar];
							pp[j + 1] = arr[i]->pointers[ar + 1];
							ar++;
						}
					}
					temp[tempc] = new Node();
					temp[tempc]->leaf = arr[i]->leaf;
					temp[tempc]->keyTally = 2;
					arr[i]->keyTally = 2;
					arr[i]->pointers[0] = pp[0];
					temp[tempc]->pointers[0] = pp[4];
					for (int j = 0; j < 3; j++)
					{
						arr[i]->keys[j] = dd[j];
						arr[i]->pointers[j + 1] = pp[j + 1];
						temp[tempc]->keys[j] = dd[j + 4];
						temp[tempc]->pointers[j + 1] = pp[j + 5];
					}
					/*
					for (int k = 0; k < 3 ; k++)
					{
					cout << arr[i]->keys[k].tconst<<"::";
					}
					cout << endl;
					*/
					//dd[3] = the middle data that has to be pushed up
					data = dd[3];
					tempc++;
					//needed new top
					if (counter == 1 || i == 1)
					{
						levels++;
						//	cout <<"1. "<< arr[i]->keyTally << endl;
						//	cout << "new top"<<endl;
						//	cout << "Error new top 01" << endl;
						arr[0] = new Node();
						arr[0]->keyTally = 0;
						arr[0]->leaf = false;
						//	cout << "Error new top 02" << endl;
						head = arr[0];
						//	cout << "Error new top 03" << endl;
						head->keys[0] = data;
						//	cout << "Error new top 04" << endl;
						//	cout << "2. " << arr[i]->keyTally << endl;
						head->pointers[0] = arr[i];
						//	cout << "3. " << arr[i]->keyTally << endl;
						cout << "Left = ";
						for (int k = 0; k <= arr[i]->keyTally; k++)
						{
							cout << i + 1 << " : " << arr[i]->keys[k].tconst << " . ";
						}
						cout << endl;
						//	cout << "Error new top 05" << endl;
						head->pointers[1] = temp[tempc - 1];
						cout << "Right = ";
						for (int k = 0; k <= head->pointers[1]->keyTally; k++)
						{
							cout << i + 1 << " : " << head->pointers[1]->keys[k].tconst << " . ";
						}
						cout << endl;

						//	cout << "Error new top 06" << endl;
						for (int k = 2; k < 7; k++)
						{
							head->pointers[k] = NULL;
						}
						break;
					}


				}
			}
		}
	}
}

void Btree::deletionId(string str)
{
	Node* current = head;
	int num;
	bool chk = false;
	clock_t start;
	start = clock();
	//searching for the deleting  data before reaching leaf
	while ((current->leaf != true)&&(chk==false))
	{
		num = 0;
		for (int i = 0; i <= current->keyTally; i++)
		{
			if (str > current->keys[i].tconst) {
				num++;
				//	cout << "after " << current->keys[i].tconst << endl;
			}

			else if (str == current->keys[i].tconst)
			{
				chk = true;
				num = i;
				std::cout << current->keys[i].tconst << "data found!" << endl;//fine
				break;
			}
			else
				break;
		}
		if(chk == false)
			current = current->pointers[num];
	}
	//arrived leaf , deleting data is at leaf
	if (chk == false)
	{
		for (int i = 0; i <= current->keyTally; i++)
		{
			if (str == current->keys[i].tconst)
			{
				std::cout << "data found at leaf!" << endl; //fine
				for (int j = i; j <= current->keyTally; j++)
				{
					current->keys[j] = current->keys[j + 1];
				}
				current->keyTally--;
				break;
			}
		}
	}
	else
	{
		Node* pt=current;
		Node* pn=current;
		Data dt;
		int c = num;
		int n;
		//replace from front
		if (current->pointers[num]->keyTally > current->pointers[num + 1]->keyTally)
		{
			pt = current->pointers[num];
			while (pt->pointers[num + 1] != NULL)
			{
				num = pt->keyTally;
				
				pn = pt;
				pt = pt->pointers[num+1];
	
			}
			dt = pt->keys[pt->keyTally];
			num = pt->keyTally;
		}
		//from behind
		else
		{
			pt = current->pointers[num+1];
			while ( pt->pointers[0] != NULL)
			{
				pn = pt;
				pt = pt->pointers[0];
			}
			dt = pt->keys[0];
			num = 0;
		}
		current->keys[c] = dt;
		//reched leaf
		cout << pt->keys[c].tconst;
		for (int j = c; j < pt->keyTally; j++)
		{
			
			pt->keys[j] = pt->keys[j + 1];
		}
		cout << pt->keys[c].tconst<<endl;
		pt->keyTally--;
		if (pt->keyTally == -1)
			pn->leaf = true;
	}
	double nn = (clock() - start) / (double)CLOCKS_PER_SEC;
	std::cout << "delete costed " << nn << " sec." << endl;
}

Data Btree::search(string str)
{
	Data data; int num=0;
	Node* current = head;
	data.tconst = "empty";
	//before current == leaf
	clock_t start; 
	start = clock();
	while ((current->leaf != true) && (data.tconst!=str))
	{
		num = 0;
		for (int i = 0 ; i <= current->keyTally; i++)
		{
			if (str > current->keys[i].tconst) {
				num++;
			//	cout << "after " << current->keys[i].tconst << endl;
			}
				
			else if (str == current->keys[i].tconst)
			{
				data = current->keys[i];
				break;
			}
			else
				break;
		}
		current = current->pointers[num];
	}
	//current == leaf
		for (int i = 0; i <= current->keyTally; i++)
		{
			if (str == current->keys[i].tconst)
				data = current->keys[i];
		}
		double nn = (clock() - start) / (double)CLOCKS_PER_SEC;
		cout << "search costed " << nn << " sec." << endl;
	return data;
}

int Btree::searchByType(Node* node, string type)
{
	clock_t start;
	start = clock();
	int cc = 0;
	for (int i = 0; i <= node->keyTally; i++)
	{
		if (node->pointers[i] != NULL && node->leaf == false)
			cc += searchByType(node->pointers[i], type);
		for (int k = 0 ; k < (int)node->keys[i].genres->size();k++)
		{
			if (type == node->keys[i].genres[k])
				cc++;
		}
	}
	if (node->pointers[node->keyTally + 1] != NULL && node->leaf == false)
		cc += searchByType(node->pointers[node->keyTally + 1], type);
	
	double nn = (clock() - start) / (double)CLOCKS_PER_SEC;
	cout << "search costed " << nn << " sec." << endl;
	return cc;
}

int Btree::searchByTypeM(Node * node, string type)
{
	clock_t start;
	start = clock();
	
	int cc = 0;
	for (int i = 0; i <= node->keyTally; i++)
	{
		if (node->pointers[i] != NULL && node->leaf == false)
			cc += searchByTypeM(node->pointers[i], type);
		if (type == node->keys[i].titleType)
			cc++;
	}
	if (node->pointers[node->keyTally + 1] != NULL && node->leaf == false)
		cc += searchByTypeM(node->pointers[node->keyTally + 1], type);
	double nn = (clock() - start) / (double)CLOCKS_PER_SEC;
	cout << "search costed " << nn << " sec." << endl;
	return cc;
}

int Btree::searchByYear(Node* node,int year)
{
	clock_t start;
	start = clock();
	
	int cc=0;
	for (int i = 0; i <= node->keyTally; i++)
	{
		if (node->pointers[i] != NULL && node->leaf == false)
			cc+=searchByYear(node->pointers[i], year);
		if (year == node->keys[i].startYear)
			cc++;
	}
	if (node->pointers[node->keyTally + 1] != NULL && node->leaf == false)
		cc+=searchByYear(node->pointers[node->keyTally + 1],year);
	double nn = (clock() - start) / (double)CLOCKS_PER_SEC;
	cout << "search costed " << nn << " sec." << endl;
	return cc;
}

void Btree::modify(string str)
{
	Data* data; int num = 0;
	Data d;
	data = &d;
	Node* current = head;
	//before current == leaf
	clock_t start;
	start = clock();
	while ((current->leaf != true) && (data->tconst != str))
	{
		num = 0;
		for (int i = 0; i <= current->keyTally; i++)
		{
			if (str > current->keys[i].tconst) {
				num++;
				//	cout << "after " << current->keys[i].tconst << endl;
			}

			else if (str == current->keys[i].tconst)
			{
				data = &current->keys[i];
				break;
			}
			else
				break;
		}
		current = current->pointers[num];
	}
	//current == leaf
	for (int i = 0; i <= current->keyTally; i++)
	{
		if (str == current->keys[i].tconst)
			data = &current->keys[i];
	}
	double nn = 0;
	nn += (clock() - start) / (double)CLOCKS_PER_SEC;
	//start = clock();
	
	if (data->tconst == "empty")
	{
		cout << "item not found";
		
	}
	else
	{
		cout << "Actions: 1,name : 2,titleType : 3,year : 4,runtimeMinutes : 5,genres"<<endl;
		cout << "Enter modify type : ";
		int tem = 0;
		cin >> tem;
		switch (tem)
		{
		case 1:
		{
			cout << "Enter new name : ";
			string stem;
			cin >> stem;
			start = clock();
			data->primaryTitle = stem;
			nn += (clock() - start) / (double)CLOCKS_PER_SEC;
			break;
		}
		case 2:
		{
			cout << "Enter new titleType : ";
			string stem;
			cin >> stem;
			start = clock();
			data->titleType = stem;

			break;
		}
		case 3:
		{
			cout << "Enter new year : ";
			int stem;
			cin >> stem;
			start = clock();
			data->startYear = stem;
			break;
		}
		case 4:
		{
			cout << "Enter new runtimeMinutes : ";
			int stem;
			cin >> stem;
			start = clock();
			data->runtimeMinutes = stem;
			break;
		}
		case 5:
		{
			cout << "Enter size of the new genres : ";
			int st = 0;
			cin >> st;
			string stem;
			for (int i = 0; 1 < st; i++) 
			{
				cout << "Enter  the new genres : ";
				cin >> stem;
				data->genres[i] = stem;
				stem = "";
			}
			for (int i = st; 1 < 3; i++)
			{
				data->genres[i] = "";
			}
			start = clock();
			break;
		}
		default:
			break;
		}
	}
	nn += (clock() - start) / (double)CLOCKS_PER_SEC;
	cout << "Modify costed " << nn << " sec." << endl;
}

Btree::Btree()
{
	head = NULL;
	levels = 0;
}


void Btree::print(Node* node)
{
	clock_t start;
	start = clock();
	for (int i = 0; i <= node->keyTally; i++)
	{
		if (node->pointers[i] != NULL && node->leaf==false)
			print(node->pointers[i]);
		cout << node->keys[i].tconst <<" : "<< node->keys[i].primaryTitle << endl;
	}
	if (node->pointers[node->keyTally+1] != NULL && node->leaf == false)
		print(node->pointers[node->keyTally+1]);
	double nn = (clock() - start) / (double)CLOCKS_PER_SEC;
	cout << "search costed " << nn << " sec." << endl;
}
