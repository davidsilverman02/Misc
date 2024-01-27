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

#include "functions.h"
using namespace std;

Item ite(int chos){
	string name;
	int choi1;
	int choi2;
	int choi3;
	int maxD;
	int feb = 28;
	switch (chos) {
	case 1:
		cout << endl << "Enter object name: ";
		cin >> name;
		return Item(name);
		break;
	case 2:
		cout << endl << "Enter object name: ";
		cin >> name;
		cout << endl << "Enter the count";
		cin >> choi1;
		return CountItem(name, choi1);
		break;
	case 3:
		cout << endl << "Enter object name: ";
		cin >> name;
		cout << endl << "Enter days left";
		cin >> choi1;
		while (choi1 < 0) {
			cout << endl << "Invalid number";
			cout << endl << "Enter days left";
			cin >> choi1;
		}
		return DaysLeftItem(name, choi1);
		break;
	case 4:
		cout << endl << "Enter object name: ";
		cin >> name;
		cout << endl << "Enter year: ";
		cin >> choi3;
		cout << endl  << "Enter month as number: ";
		cin >> choi2;
		while (choi2 > 12 || choi2 < 1) {
			cout << "Invalid month";
			cout << endl << "Enter month as number: ";
			cin >> choi2;
		}
		switch (choi2) {
		case 1:
			maxD = 31;
			break;
		case2:
			if (choi3 % 4 == 0) {
				maxD = 29;
			}
			else {
				maxD = 28;
			}
			break;
		case 3:
			maxD = 31;
			break;
		case 4:
			maxD = 30;
			break;
		case 5:
			maxD = 31;
			break;
		case 6:
			maxD = 30;
			break;
		case 7:
			maxD = 31;
			break;
		case 8:
			maxD = 31;
			break;
		case 9:
			maxD = 30;
			break;
		case 10:
			maxD = 31;
			break;
		case 11:
			maxD = 30;
			break;
		case 12:
			maxD = 31;
			break;
		}
		cout << endl << "Enter day as number: ";
		cin >> choi1;
		while (choi1 > maxD || choi1 < 1) {
			cout << endl << "Invalid day";
			cout << endl << "Enter day as number: ";
			cin >> choi1;
		}
		break;
	}
}
Item::Item() {
	name = "Ni";
}
Item::Item(string handle) {
	name = handle;
}
void Item::setName(string name) {
	this->name = name;
}
string Item::getName() {
	return name;
}
void Item::update() {
	string nom;
	cout << endl << "Enter new name: ";
	cin >> nom;
	name = nom;
}
string Item::fileGive() {
	return "*" + name + "\n";
}
string Item::describe() {
	return name;
}
CountItem::CountItem(string handle, int count) : Item(handle) {
	this->count = count;
}
void CountItem::setCount(int num) {
	count = num;
}
int CountItem::getCount() {
	return count;
}
void CountItem::update() {
	string nom;
	int coun;
	cout << endl << "Enter new name: ";
	cin >> nom;
	name = nom;
	cout << endl << "Enter new count: ";
	cin >> coun;
	count = coun;
}
string CountItem::fileGive() {
	return "1" + to_string(count) + "\n" + '@' + name + "\n";
}
string CountItem::describe() {
	return name + "   Count: " + to_string(count);
}
DaysLeftItem::DaysLeftItem(string handle, int left) : Item(handle) {
	daysLeft = left;
}
void DaysLeftItem::setDays(int days) {
	daysLeft = days;
}
int DaysLeftItem::getDays() {
	return daysLeft;
}
void DaysLeftItem::update() {
	string nom;
	int coun;
	cout << endl << "Enter new name: ";
	cin >> nom;
	name = nom;
	cout << endl << "Enter days left: ";
	cin >> coun;
	while (coun < 0) {
		cout << endl << "Invalid Number: ";
		cout << endl << "Enter days left: ";
		cin >> coun;
	}
	daysLeft = coun;
}
string DaysLeftItem::fileGive() {
	return "1" + to_string(daysLeft) + "\n" + "$" + name + "\n";
}
string DaysLeftItem::describe(){
	return name + "   Days Left: " + to_string(daysLeft);
}
DateItem::DateItem(string handle, int day, int month, int year) : Item(handle){
	date[0] = day;
	date[1] = month;
	date[2] = year;
}
void DateItem::setDate(int day, int month, int year) {
	date[0] = day;
	date[1] = month;
	date[2] = year;
}
string DateItem::getDate() {
	return to_string(date[0]) + "/" + to_string(date[1]) + "/" + to_string(date[2]);
}
void DateItem::update() {
	string nom;
	int feb = 28;
	int coun1;
	int coun2;
	int coun3;
	int madX;
	cout << endl << "Enter new name: ";
	cin >> nom;
	name = nom;
	cout << endl << "Enter new year: ";
	cin >> coun1;
	date[2] = coun1;
	if (coun1 % 4 == 0) {
		feb = 29;
	}
	cout << endl << "Enter new month as number: ";
	cin >> coun2;
	while (coun2 > 12 || coun2 < 1)
	{
		cout << endl << "Invalid month";
		cout << endl << "Enter new month as number: ";
		cin >> coun2;
	}
	date[1] = coun2;
	switch (coun2) {
	case 1:
		madX = 31;
		break;
	case 2:
		madX = feb;
		break;
	case 3:
		madX = 31;
		break;
	case 4:
		madX = 30;
		break;
	case 5:
		madX = 31;
		break;
	case 6:
		madX = 30;
		break;
	case 7:
		madX = 31;
		break;
	case 8:
		madX = 31;
		break;
	case 9:
		madX = 30;
		break;
	case 10:
		madX = 31;
		break;
	case 11:
		madX = 30;
		break;
	case 12:
		madX = 31;
		break;
	}
	cout << endl << "Enter new day as number: ";
	cin >> coun3;
	while (coun3 > madX || coun3 < 1) {
		cout << endl << "Invalid day";
		cout << endl << "Enter new day as number: ";
		cin >> coun3;
	}
}
string DateItem::fileGive() {
	return "1" + to_string(date[0]) + "\n" + "2" + to_string(date[1]) + "\n" + "3" + to_string(date[2]) + "\n" + "%" + name + "\n";
}
string DateItem::describe() {
	return name + "   " + getDate();
}
ItemList::ItemList() {
	title = "base";
}
ItemList::ItemList(vector <Item>& items, string name){
	title = name;
	given = items;
}
ItemList::~ItemList() {
	
}
void ItemList::addItem() {
	int choice;
	int choice2;
	int choice3;
	Item choice4();
	cout << endl << "Select Which you want to do:"
		<< endl << "1: Add at the end"
		<< endl << "2: Add at a specific position"
		<< endl;
	cin >> choice;
	while (choice != 1 || choice != 2) {
		cout << endl << "Invalid Choice"
			<< endl << "Select Which you want to do:"
			<< endl << "1: Add at the end"
			<< endl << "2: Add at a specific position"
			<< endl;
		cin >> choice;
	}
	cout << endl << "Choose which type of item to add:"
		<< endl << "1: Plain item"
		<< endl << "2: Count item"
		<< endl << "3: Days Left item"
		<< endl << "4: Date item"
		<< endl;
	cin >> choice2;
	while (choice2 > 4 || choice2 < 1) {
		cout << endl << "Choose which type of item to add:"
			<< endl << "1: Plain item"
			<< endl << "2: Count item"
			<< endl << "3: Days Left item"
			<< endl << "4: Date item"
			<< endl;
		cin >> choice2;
	}
	switch (choice) {
	case 1:
		given.push_back(ite(choice2));
		break;
	case 2:
		int id = given.size();
		cout << endl << "At which point do you want to add item?";
		for (int i = 0; i < id; i++) {
			cout << endl << i + 1;
		}
		cin >> choice3;
		while (choice3 > id || choice3 < 1)
		{
			cout << endl << "Invalid Choice";
			cout << endl << "At which point do you want to add item?";
			for (int i = 0; i < id; i++) {
				cout << endl << i + 1;
			}
			cin >> choice3;
		}
		given.push_back(choice4());
		id = given.size();
		for (int i = choice3; i < id; i++) {
			given[i + 1] = given[i];
		}
		given[choice3] = ite(choice2);
		break;
	}
}

void ItemList::rename() {
	string newN;
	cout << " Enter new name: ";
	cin >> newN;
	title = newN;
}
void ItemList::renameItem(){
	int vecNum = given.size();
	int getIN;
	for (int i = 0; i < vecNum; i++) {
		cout << endl << i + 1 << ". " << given[i].getName();
	}
	cout << endl << "Choose item to rename: ";
	cin >> getIN;
	while (getIN > vecNum || getIN < 1) {
		cout << endl << "Invalid Item";
		for (int i = 0; i < vecNum; i++) {
			cout << endl << i + 1 << ". " << given[1].getName();
		}
		cout << endl << "Choose item to rename: ";
		cin >> getIN;
	}
	given[getIN].update();
}
void ItemList::rearrange() {
	int choic1;
	int choic2;
	for (int i = 0; i < given.size(); i++) {
		cout << endl << i + 1 << ". " << given[i].getName();
	}
	cout << endl << "Choose first to swap: ";
	cin >> choic1;
	while (choic1 > given.size() || choic1 < 1) {
		cout << endl << "Invalid choice";
		for (int i = 0; i < given.size(); i++) {
			cout << endl << i + 1 << ". " << given[i].getName();
		}
		cout << endl << "Choose first to swap: ";
		cin >> choic1;
	}
	for (int i = 0; i < given.size(); i++) {
		cout << endl << i + 1 << ". " << given[i].getName();
	}
	cout << endl << "Choose second to swap: ";
	cin >> choic2;
	while (choic2 > given.size() || choic2 < 1) {
		cout << endl << "Invalid choice";
		for (int i = 0; i < given.size(); i++) {
			cout << endl << i + 1 << ". " << given[i].getName();
		}
		cout << endl << "Choose second to swap: ";
		cin >> choic2;
	}

	Item newIt1 = given[choic1];
	Item newIt2 = given[choic2];

	given[choic1] = newIt2;
	given[choic2] = newIt1;
}
ItemList ItemList::operator+(const Item& neo) {
	given.push_back(neo);
	return *this;
}
ItemList ItemList::operator-(const int& givn) {
	for (int i = 0; i < givn; i++) {
		given.pop_back();
	}
	return *this;
}
void ItemList::deleteItem() {
	int choice;
	int choice2;
	cout << endl << "Select Which you want to do:"
		<< endl << "1: Remove at the end"
		<< endl << "2: Remove at a specific position"
		<< endl;
	cin >> choice;
	while (choice != 1 || choice != 2) {
		cout << endl << "Invalid Choice"
			<< endl << "Select Which you want to do:"
			<< endl << "1: Remove at the end"
			<< endl << "2: Remove at a specific position"
			<< endl;
		cin >> choice;
	}
	switch (choice) {
	case 1:
		
		*this - subtra;
		break;
	case 2:
		int id = given.size();
		cout << endl << "At which point do you want to add item?";
		for (int i = 0; i < id; i++) {
			cout << endl << i + 1;
		}
		cin >> choice2;
		while (choice2 > id || choice2 < 1)
		{
			cout << endl << "Invalid Choice";
			cout << endl << "At which point do you want to add item?";
			for (int i = 0; i < id; i++) {
				cout << endl << i + 1;
			}
			cin >> choice2;
		}
		for (int i = choice2; i < id; i++) {
			given[i] = given[i + 1];
		}
		given.pop_back();
		break;
	}
}
stringstream ItemList::outGive() {
	stringstream giveOut;
	giveOut << title << endl;
	for (int i = 0; i < given.size(); i++) {
		giveOut << given[i].fileGive();
	}
	return giveOut;
}
string ItemList::getName() {
	return title;
}
void ItemList::setName(string toGive) {
	title = toGive;
}
int ItemList::getLength() {
	return given.size();
}
void ItemList::printData() {
	for (int i = 0; i < given.size(); i++) {
		cout << given[i].describe() << endl;
	}
}
ProgramMain::ProgramMain(){}
void ProgramMain::programRun() {
	ifstream inp;
	ofstream outp;
	ofstream logo;
	string listName;
	string readLine;

	inp.open(DATA_FILE_NAME);
	outp.open(DATA_FILE_NAME, fstream::app);
	logo.open(LOG_FILE_NAME, fstream::app);

	logo << "List Added \n";
	bool running = true;
	cout << "Welcome to List Master!" << endl;

	while (running == true) {
		int numChoice;
		int functChoice;
		stringstream part1;
		stringstream part2;
		cout << endl << "Options:"
			<< endl << "1: Add a List"
			<< endl << "2: Remove a List"
			<< endl << "3: Edit a List"
			<< endl << "4: Display a List"
			<< endl << "5: Leave the Program"
			<< endl << endl << "Enter Choice";
		cin >> numChoice;
		while (numChoice > 5 || numChoice < 1) {
			cout << endl << "Invalid Choice" << endl;
			cout << endl << "Options:"
				<< endl << "1: Add a List"
				<< endl << "2: Remove a List"
				<< endl << "3: Edit a List"
				<< endl << "4: Display a List"
				<< endl << "5: Leave the Program"
				<< endl << endl << "Enter Choice";
			cin >> numChoice;
		}

		switch (numChoice)
		{
			
			case 1:
			{	bool run;
				string* given = new string;
				int listChosen;

				cout << "1: Add to the end"
					<< "2: Add at a specific point"
					<< endl << endl << "Enter Choice";
				cin >> functChoice;
				while (functChoice > 2 || functChoice < 1)
				{
					cout << "1: Add to the end"
						<< "2: Add at a specific point"
						<< endl << endl << "Enter Choice";
					cin >> functChoice;
				}
				cout << "Name list";
				cin >> listName;
				switch (functChoice)
				{
				case 1: {
					outp << "#" + listName;
					break;
				}
				case 2: {
					cout << endl << "After which list?";
					int listAmount = 0;
					while (!inp.eof()) {
						getline(inp, readLine);
						if (readLine.at(0) == '#') {
							given[listAmount] = readLine;
							listAmount += 1;
						}
					}
					int arrSize = sizeof(given) / sizeof(given[0]);
					for (int i = 0; i < arrSize; i++) {
						cout << endl << i + 1 << ". " << given[i].substr(1);
					}
					cout << endl;
					cin >> listChosen;
					while (listChosen > arrSize || listChosen < 1) {
						cout << endl << "Invalid list";
						cout << endl;
						cin >> listChosen;
					}
					listAmount = 0;
					while (!inp.eof()) {
						getline(inp, readLine);
						if (readLine.at(0) == '#') {
							listAmount += 1;
						}
						if (listAmount > listChosen) {
							part2 << readLine;
						}
						else
						{
							part1 << readLine;
						}

					}
					outp.open(DATA_FILE_NAME, std::fstream::out | std::fstream::trunc);
					outp.close();
					outp.open(DATA_FILE_NAME, fstream::app);
					outp << part1.str();
					outp << '#' + listName;
					outp << part2.str();
					logo << "List Added \n";
				}
					  break;
				}
			}
			case 2:
			{
				bool run;
				string* given =  new string;
				int listChosen;


				cout << "1: Remove from the end"
					<< "2: Remove from a specific point"
					<< endl << endl << "Enter Choice";
				cin >> functChoice;
				while (functChoice > 2 || functChoice < 1)
				{
					cout << "1: Remove from the end"
						<< "2: Remove a specific point"
						<< endl << endl << "Enter Choice";
					cin >> functChoice;
				}
				switch (functChoice) {
				case 1:
				{
					int listAmount = 0;
					int listChosen = 0;

					while (!inp.eof()) {
						getline(inp, readLine);
						if (readLine.at(0) == '#') {
							listChosen += 1;
						}
					}
					while (!inp.eof()) {
						getline(inp, readLine);
						if (readLine.at(0) == '#') {
							listAmount += 1;
						}
						if (listAmount < listChosen) {
							part1 << readLine;
						}
					}
					outp.open(DATA_FILE_NAME, std::fstream::out | std::fstream::trunc);
					outp.close();
					outp.open(DATA_FILE_NAME, fstream::app);
					outp << part1.str();
					break;
				}
				case 2: {
					cout << endl << "Delete which? : ";
					int listAmount = 0;
					while (!inp.eof()) {
						getline(inp, readLine);
						if (readLine.at(0) == '#') {
							given[listAmount] = readLine;
							listAmount += 1;
						}
					}
					int arrSize = sizeof(given) / sizeof(given[0]);
					for (int i = 0; i < arrSize; i++) {
						cout << endl << i + 1 << ". " << given[i].substr(1);
					}
					cout << endl;
					cin >> listChosen;
					while (listChosen > arrSize || listChosen < 1) {
						cout << endl << "Invalid list";
						cout << endl;
						cin >> listChosen;
					}
					listAmount = 0;
					while (!inp.eof()) {
						getline(inp, readLine);
						if (readLine.at(0) == '#') {
							listAmount += 1;
						}
						if (listAmount > listChosen) {
							part2 << readLine;
						}
						else if (listAmount < listChosen)
						{
							part1 << readLine;

						}


					}
					outp.open(DATA_FILE_NAME, std::fstream::out | std::fstream::trunc);
					outp.close();
					outp.open(DATA_FILE_NAME, fstream::app);
					outp << part1.str();
					outp << part2.str();
					break;
				}
				}
				logo << "List removed \n";
				break;
			}
			case 3: {
				int funcChoic;
				ItemList* chosen = new ItemList();
				string givnTitle;
				int listChosen;
				int choice1;
				int choice2;
				int choice3;
				string* given = new string;
				string nameGivn;
				cout << endl << "Choose which list to edit: ";
				int listAmount = 0;
				while (!inp.eof()) {
					getline(inp, readLine);
					if (readLine.at(0) == '#') {
						given[listAmount] = readLine;
						listAmount += 1;
					}
				}
				int arrSize = sizeof(given) / sizeof(given[0]);
				for (int i = 0; i < arrSize; i++) {
					cout << endl << i + 1 << ". " << given[i].substr(1);
				}
				cout << endl;
				cin >> listChosen;
				while (listChosen > arrSize || listChosen < 1) {
					cout << endl << "Invalid list";
					cout << endl;
					cin >> listChosen;
				}
				bool startRead = true;
				listAmount = 0;
				while (!inp.eof()) {
					bool makeItem;
					int chosenType;
					getline(inp, readLine);
					if (readLine.at(0) == '#') {
						listAmount += 1;
					}
					if (listAmount == listChosen) {
						switch (readLine.at(0))
						{
						case '#':
							chosen->setName(readLine.substr(1));
							chosenType = 0;
							break;
						case '*':
							// Item
							*chosen + (Item (readLine.substr(1)));
							chosenType = 0;
								break;
						case '@':
							// CountItem
							nameGivn = readLine.substr(1);
							chosenType = 1;
							makeItem = true;
							break;
						case '$':
							// DaysLeftItem
							nameGivn = readLine.substr(1);
							chosenType = 2;
							makeItem = true;
							break;
						case '%':
							// DateItem
							nameGivn = readLine.substr(1);
							chosenType = 3;
							makeItem = true;
							break;
						case '1':
							choice1 = stoi(readLine.substr(1));
							break;
						case '2':
							choice2 = stoi(readLine.substr(1));
							break;
						case '3':
							choice3 = stoi(readLine.substr(1));
							break;
						default:
							break;
						}
						if (makeItem) {
							switch (chosenType)
							{
							case 1:
								*chosen + CountItem(nameGivn, choice1);
								break;
							case 2:
								*chosen + DaysLeftItem(nameGivn, choice1);
								break;
							case 3:
								*chosen + DateItem(nameGivn, choice1, choice2, choice3);
								break;
							default:
								break;
							}
							makeItem = false;
						}
					}
				}
				cout << endl << "What action would you like to perform: "
					<< endl << "1. Add an Item to the list"
					<< endl << "2. Delete an Item from the list"
					<< endl << "3. Rename the list"
					<< endl << "4. Edit a List Item"
					<< endl << "5. Rearrange two list items"
					<< endl;
				cin >> funcChoic;
				while (funcChoic > 5 || funcChoic < 1) {
					cout << endl << "Invalid choice";
					cout << endl << "What action would you like to perform: "
						<< endl << "1. Add an Item to the list"
						<< endl << "2. Delete an Item from the list"
						<< endl << "3. Rename the list"
						<< endl << "4. Edit a List Item"
						<< endl << "5. Rearrange two list items"
						<< endl;
					cin >> funcChoic;
				}
				switch (funcChoic) {
				case 1:
					chosen->addItem();
					break;
				case 2:
					chosen->deleteItem();
					break;
				case 3:
					chosen->rename();
					break;
				case 4:
					chosen->renameItem();
					break;
				case 5:
					chosen->rename();
					break;
				}
				while (!inp.eof()) {
					getline(inp, readLine);
					if (readLine.at(0) == '#') {
						listAmount += 1;
					}
					if (listAmount > listChosen) {
						part2 << readLine;
					}
					else if (listAmount < listChosen)
					{
						part1 << readLine;

					}
				}
				outp.open(DATA_FILE_NAME, std::fstream::out | std::fstream::trunc);
				outp.close();
				outp.open(DATA_FILE_NAME, fstream::app);
				outp << part1.str();
				outp << chosen->outGive().str();
				outp << part2.str();
				delete chosen;
				delete given;
				logo << "List Edited \n";
				break;
			}
			case 4: {
				int funcChoic;
				ItemList* chosen = nullptr;
				string givnTitle;
				int listChosen;
				int choice1;
				int choice2;
				int choice3;
				string* given = nullptr;
				string nameGivn;
				cout << endl << "Choose which list to edit: ";
				int listAmount = 0;
				while (!inp.eof()) {
					getline(inp, readLine);
					if (readLine.at(0) == '#') {
						given[listAmount] = readLine;
						listAmount += 1;
					}
				}
				int arrSize = sizeof(given) / sizeof(given[0]);
				for (int i = 0; i < arrSize; i++) {
					cout << endl << i + 1 << ". " << given[i].substr(1);
				}
				cout << endl;
				cin >> listChosen;
				while (listChosen > arrSize || listChosen < 1) {
					cout << endl << "Invalid list";
					cout << endl;
					cin >> listChosen;
				}
				bool startRead = true;
				listAmount = 0;
				while (!inp.eof()) {
					bool makeItem;
					int chosenType;
					getline(inp, readLine);
					if (readLine.at(0) == '#') {
						listAmount += 1;
					}
					if (listAmount == listChosen) {
						switch (readLine.at(0))
						{
						case '#':
							givnTitle = readLine.substr(1);
							break;
						case '*':
							// Item
							*chosen + (Item(readLine.substr(1)));
							chosenType = 0;
							break;
						case '@':
							// CountItem
							nameGivn = readLine.substr(1);
							chosenType = 1;
							makeItem = true;
							break;
						case '$':
							// DaysLeftItem
							nameGivn = readLine.substr(1);
							chosenType = 2;
							makeItem = true;
							break;
						case '%':
							// DateItem
							nameGivn = readLine.substr(1);
							chosenType = 3;
							makeItem = true;
							break;
						case '1':
							choice1 = stoi(readLine.substr(1));
							break;
						case '2':
							choice2 = stoi(readLine.substr(1));
							break;
						case '3':
							choice3 = stoi(readLine.substr(1));
							break;
						default:
							break;
						}
						if (makeItem) {
							switch (chosenType)
							{
							case 1:
								*chosen + CountItem(nameGivn, choice1);
								break;
							case 2:
								*chosen + DaysLeftItem(nameGivn, choice1);
								break;
							case 3:
								*chosen + DateItem(nameGivn, choice1, choice2, choice3);
								break;
							default:
								break;
							}
							makeItem = false;
						}
					}
				}
				cout << endl;
				cout << chosen->getName() << endl;
				chosen->printData();
				delete chosen;
				delete given;
				logo << "List Displayed \n";
				break;
			}
			case 5:
				running = false;
				logo << "Program Ended \n";
				break;
			default:
				break;
		}
	}
}
