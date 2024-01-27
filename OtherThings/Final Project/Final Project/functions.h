/*
Author       : David Silverman
Class        : CSI-240 / SECTION NUMBER : Advanced Programming
Assignment   : Final Project
Date Assigned: 4/10/21
Due Date     : 4/25/21

Description:
			 A program that creates and stores lists

Certification of Authenticity:

I certify that this is entirely my own work, except where I have given
fully-documented references to the work of others. I understand the
definition and consequences of plagiarism and acknowledge that the assessor
of this assignment may, for the purpose of assessing this assignment:
- Reproduce this assignment and provide a copy to another member of
academic staff; and/or
- Communicate a copy of this assignment to a plagiarism checking
service (which may then retain a copy of this assignment on its
database for the purpose of future plagiarism checking)
*/

#include <iostream>;
#include <sstream>;
#include <fstream>;
#include <string>;
#include <vector>;
using namespace std;

const string DATA_FILE_NAME = "data.txt";
const string LOG_FILE_NAME = "log.txt";

class ProgramMain {
	
public:
	ProgramMain();
	void programRun();
};

class Item {
protected:
	string name;
public:
	Item();
	Item(string handle);
	void setName(string name);
	string getName();
	void update();
	string fileGive();
	string describe();
};

class CountItem : public Item{
private:
	int count;
public:
	CountItem(string handle, int count);
	void setCount(int num);
	int getCount();
	void update();
	string fileGive();
	string describe();
};

class DaysLeftItem : public Item {
	int daysLeft;
public:
	DaysLeftItem(string handle, int left);
	void setDays(int days);
	int getDays();
	void update();
	string fileGive();
	string describe();
};

class DateItem : public Item {
	/*
0 is day
1 is month
2 is year
*/
	int date[3];
public:
	DateItem(string handle, int day, int month, int year);
	void setDate(int day, int month, int year);
	string getDate();
	void update();
	string fileGive();
	string describe();
};

class ItemList {
	static int subtra;
	string title;
	vector <Item> given;
public:
	ItemList();
	ItemList(vector <Item>& items, string name);
	~ItemList();
	ItemList operator+(const Item& neo);
	ItemList operator-(const int& givn);
	void addItem();
	void deleteItem();
	void rename();
	void renameItem();
	void rearrange();
	stringstream outGive();
	string getName();
	void setName(string toGive);
	int getLength();
	void printData();
};

int ItemList::subtra = 1;