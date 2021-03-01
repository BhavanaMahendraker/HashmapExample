
// Bhavana mahendraker

#include<iostream>
#include<string>
#include<fstream>
#include"HashMap.h"
#include"HashNode.h"
using namespace std;


int main()
{
	ifstream infile;
	string location;
	cout << "Enter the location of the file: ";
	getline(cin, location);

	while (infile.fail())
	{
		cout << "The location that is entered is wrong. Please re-enter the location: ";
		getline(cin, location);
	}
	infile.open(location.c_str());
	HashNode<string, string> *h = new HashNode<string, string>;
	HashMap<string, string> *hm = new HashMap<string, string>;

	string name, date;

	//while not the end of file 
	// get name and date 
	// set the value as name and key as date
	// insert the date with key as date and value as name
	while (!infile.eof())
	{
		getline(infile, name);
		getline(infile, date);
		h->setKey(date);
		h->setValue(name);
		hm->insertNode(date, name);
	}
	infile.close();// close the file
	hm->display(); // display the hash table
	cout << "Number of data items: " << hm->sizeofMap() << endl;
	cout << "Load factor = "<< hm->sizeofMap() / hm->capacityFunction() * 100 << endl;
	cout << "Number of collisions = " << hm->getCollisions() << endl;
	int choice=0;

	// do the menu while choice is equal to 1
	do {
		string userDate=" ";

		cout << "Enter the birthday of the person in YYYY-MM-DD format (Ex: 1974-08-24): ";
		cin >> userDate;

		cout << "The Name of the Birthday that you entered is " << hm->find(userDate) << endl;

		cout << "1. Would you like to search another Birthday (type 1): " << endl;
		cout << "2. End the program" << endl;
		cin >> choice;

	} while (choice == 1);
	system("pause");
	return 0;
}