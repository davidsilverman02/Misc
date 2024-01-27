/*
	Author:       David Silverman
	Class:		  CSI-281-01
	Assignment: Final Project
	Date Assigned: 11/30/21
	Due Date: 11/10/21 1:00 PM

		Description:
			Encrypt a text into numbers

		Certification of Authenticity:
			I certify that this is entirely my own work, except where I have given fully-
			documented references to the work of others. I understand the definition and
			consequences of plagiarism and acknowledge that the assessor of this assignment
			may, for the purpose of assessing this assignment:
				-Reproduce  this  assignment  and  provide  a  copy  to  another  member  of
				 academic staff; and/or
				-Communicate a copy of this assignment to a plagiarism checking service
				(which may then retain a copy of this assignment on its database for
				the purpose of future plagiarism checking)
*/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "timersystem.h"

using namespace std;

const int ALF_SIZE = 46;
const int LIST_SIZE = 398484;

int returnProp(char given);

/* Pre:  Nothing
*  Post:  Creates the Trie
*  Purpose:  Stores the Trie
*********************************************************/
class Trie
{
public:
	bool isLeaf;
	string encryptKey;
	Trie* childs[ALF_SIZE];

	// Constructor
	Trie()
	{
		this->isLeaf = false;

		for (int i = 0; i < ALF_SIZE; i++) {
			this->childs[i] = nullptr;
		}
	}

	bool deletion(Trie*& curr, string key);
	bool haveChildren(Trie const*);
	void insert(string key, string encrypt);
	string search(string);

};

/* Pre:  Nothing
*  Post:  A word is deleted
*  Purpose:  Cleans out the tree
*********************************************************/
bool Trie::deletion(Trie*& curr, string key)
{
	// return if Trie is empty
	if (curr == nullptr) {
		return false;
	}

	// if the end of the key is not reached
	if (key.length())
	{

		if (curr != nullptr && curr->childs[returnProp(key[0])] != nullptr && deletion(curr->childs[returnProp(key[0])], key.substr(1)) && curr->isLeaf == false)
		{
			if (!haveChildren(curr))
			{
				delete curr;
				curr = nullptr;
				return true;
			}
			else {
				return false;
			}
		}
	}

	// if the end of the key is reached
	if (key.length() == 0 && curr->isLeaf)
	{
		// if the current node is a leaf node and doesn't have any children
		if (!haveChildren(curr))
		{
			delete curr;
			curr = nullptr;

			// delete the non-leaf parent nodes
			return true;
		}

		// if the current node is a leaf node and has children
		else {
			// mark the current node as a non-leaf node (DON'T DELETE IT)
			curr->isLeaf = false;

			// don't delete its parent nodes
			return false;
		}
	}

	return false;
}

/* Pre:  Nothing
*  Post:  A bool is returned
*  Purpose:  Sees if a Trie node has children
*********************************************************/
bool Trie::haveChildren(Trie const* curr)
{
	for (int i = 0; i < ALF_SIZE; i++)
	{
		if (curr->childs[i]) {
			return true;
		}
	}

	return false;
}


/* Pre:  Nothing
*  Post:  A word is inserted to the tree
*  Purpose:  Adds words to the tree
*********************************************************/
void Trie::insert(string key, string encrypt)
{
	int temp;
	// start from the root node
	Trie* curr = this;
	for (int i = 0; i < key.length(); i++)
	{
		temp = returnProp(key[i]);
		// create a new node if the path doesn't exist
		if (curr->childs[temp] == nullptr) {
			curr->childs[temp] = new Trie();
		}

		// go to the next node
		curr = curr->childs[temp];
	}

	// mark the current node as a leaf
	curr->isLeaf = true;
	curr->encryptKey = encrypt;
}

/* Pre:  A character is given
*  Post:  A number is returned
*  Purpose:  Develops numbers for the Trie
*********************************************************/
int returnProp(char given)
{
	int index = given - 'a';

	if (index >= -32 && index <= -7)
		index += 32;

	if (index < 0)
	{
		switch (index)
		{
		case -58:
			index = 26;
			break;
		case -52:
			index = 27;
			break;
		case -42:
			index = 28;
			break;
		case -112:
			index = 29;
			break;
		case -50:
			index = 30;
			break;
		case -63:
			index = 31;
			break;
		case -51:
			index = 32;
			break;
		case -38:
			index = 33;
			break;
		case -48:
			index = 34;
			break;
		case -59:
			index = 35;
			break;
		case -120:
			index = 36;
			break;
		case -2:
			index = 37;
			break;
		case -49:
			index = 38;
			break;
		case -47:
			index = 39;
			break;
		case -46:
			index = 40;
			break;
		case -45:
			index = 41;
			break;
		case -44:
			index = 42;
			break;
		case -43:
			index = 43;
			break;
		case -41:
			index = 44;
			break;
		case -40:
			index = 45;
			break;
		}
	}
	return index;
}

/* Pre:  Nothing
*  Post:  Returns an encrypted string
*  Purpose:  Encrypts words
*********************************************************/
string Trie::search(string key)
{
	// return false if Trie is empty
	if (this == nullptr) {
		return "";
	}

	Trie* curr = this;


	for (int i = 0; i < key.length(); i++)
	{
		// go to the next node
		curr = curr->childs[returnProp(key[i])];

		// if the string is invalid (reached end of a path in the Trie)
		if (curr == nullptr) {
			return "";
		}
	}

	return curr->encryptKey;
}




int main()
{


	// Set up initial variables and settings
	TimerSystem timing;

	cout.setf(ios::scientific | ios::showpoint);
	cout.precision(16);

	string test,
		word,
		encrypt,
		storedLine,
		stored;

	string input;
	string output;

	ifstream fin;
	ifstream dataTaken;
	ofstream dataGiven;
	stringstream encryptionLine;

	bool inside = true;

	Trie* ecrypt;
	string* deletionTool;
	deletionTool = new string[LIST_SIZE];

	double time1,
		time2,
		time3;

	fin.open("testFunct.txt");

	

	// Get array sorting time

	timing.startClock();

	ecrypt = new Trie();

	time1 = timing.getTime();

	cout << "The Time Taken to create the Trie is " << time1 << "s" << endl << endl << endl;

	timing.startClock();

	for (int i = 0; i < LIST_SIZE; i++)
	{
		fin >> word >> encrypt;
		deletionTool[i] = word;
		ecrypt->insert(word, encrypt);
	}

	time2 = timing.getTime();

	cout << "The Time Taken to fill the Trie " << time2 << "s" << endl << endl << endl;

	while (inside)
	{

		cout << "Enter Encrypt Source File:   ";
		cin >> input;

		if (input != "exit")
		{
			cout << "Enter Encrypt Target File:   ";
			cin >> output;

			dataTaken.open(input);
			dataGiven.open(output);

			cout << endl << endl << endl;

			timing.startClock();

			getline(dataTaken, storedLine);

			while (!dataTaken.eof())
			{
				encryptionLine << storedLine;

				while (!encryptionLine.eof())
				{
					encryptionLine >> stored;
					dataGiven << ecrypt->search(stored) << " ";
				}

				dataGiven << endl;
				encryptionLine.clear();
				getline(dataTaken, storedLine);
			}

			dataGiven.close();
			dataTaken.close();
			dataGiven.clear();
			dataTaken.clear();


			time3 = timing.getTime();

			cout << "Encryption Complete" << endl << "The Time Taken to encrypt the file is " << time3 << "s" << endl << endl << endl;

			cout << "Total time taken: " << time1 + time2 + time3 << endl << endl;

			cout << "Rebooting System" << endl << endl;

		}
		else
		{
			inside = false;

			cout << endl << "Shutting down" << endl;
		}

	}

		for (int i = 0; i < LIST_SIZE; i++)
		{
			//ecrypt->deletion(ecrypt, deletionTool[i]);
		}

	

	delete [] deletionTool;
}