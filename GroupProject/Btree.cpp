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
		cout << "passed while" << endl;
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
					for (int k = 0; k < 3 ; k++)
					{
						cout << arr[i]->keys[k].tconst<<"::";
					}
					cout << endl;
					//dd[3] = the middle data that has to be pushed up
					data = dd[3];
					tempc++;
					//needed new top
					if (counter == 1 || i==1)
					{
						cout <<"1. "<< arr[i]->keyTally << endl;
					//	cout << "new top"<<endl;
					//	static Node ngen;
					//	cout << "Error new top 01" << endl;
						arr[0] = new Node();
						arr[0]->keyTally = 0;
						arr[0]->leaf = false;
					//	cout << "Error new top 02" << endl;
						head = arr[0];
					//	cout << "Error new top 03" << endl;
						head->keys[0] = data;
					//	cout << "Error new top 04" << endl;
						cout << "2. " << arr[i]->keyTally << endl;
						head->pointers[0] = arr[i];
						cout << "3. " << arr[i]->keyTally << endl;
						for (int k = 0; k <= arr[i]->keyTally; k++)
						{
							cout << i + 1 << " : " << arr[i]->keys[k].tconst << " . ";
						}
						cout << endl;
					//	cout << "Error new top 05" << endl;
						head->pointers[1] = temp[tempc - 1];
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

Btree::Btree()
{
	head = NULL;
}


void Btree::print(Node* node)
{
//	for (int i = 0; i < 7; i++)
//	{
//		if (node->pointers[i] != NULL && node->leaf==false)
//			print(node->pointers[i]);
//	}
	for (int i = 0; i <= node->keyTally; i++)
	{
		cout << i + 1 << " : " << node->keys[i].tconst << " . ";
	}
	cout << endl;
	for (int i = 0; i <= node->pointers[0]->keyTally; i++)
	{
		cout << i + 1 << " : " << node->pointers[0]->keys[i].tconst << " . ";
	}
	cout << endl;
	for (int i = 0; i <= node->pointers[1]->keyTally; i++)
	{
		cout << i + 1 << " : " << node->pointers[1]->keys[i].tconst << " . ";
	}
	cout << endl;
	if(node->pointers[2]!=NULL)
	for (int i = 0; i <= node->pointers[2]->keyTally; i++)
	{
		cout << i + 1 << " : " << node->pointers[2]->keys[i].tconst << " . ";
	}
	cout << endl;
}

Data Btree::search(string tconst) {
  Node* curr = head;
  
  while (!curr->leaf) {
    bool found = false;
    int i = 0;
    while (!found && curr->pointers[i]) {
      if (tconst < curr->keys[i].tconst) {
        curr = curr->pointers[i];
        found = true;
      }
      ++i;
    }
    if (!found)
      curr = curr->pointers[i];
  }

  Data data;
  for (int i = 0; i < 6; ++i) {
    if (curr->keys[i].tconst == tconst) {
      data = curr->keys[i];
      break;
    }
  }
  return data;
}
