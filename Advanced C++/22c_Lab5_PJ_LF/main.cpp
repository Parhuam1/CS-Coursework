// Parhuam Jalalian
// Luke Fields
// Lab 5
// Partner's Contriubution 0 - Both did same work
// main.cpp

#include "BST.h"
#include "Person.h"
#include "BSTNode.h"
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

int main()
{
	BST<Person> nameTree;
	BST<Person> dateTree;
	string path;

	while (true) {
		cout << "enter file directory path" << endl
			<< "blank for current directory" << endl;
		getline(cin, path);
		if (path.length() > 0) // auto correct for path missing '\'
			path = (path[path.length() - 1] == '\\') ? path : path += '\\';
		ifstream inFile(path + "InputData.txt"); // open input file

		if (inFile.is_open())
		{
			string name, date;
			while (!inFile.eof())
			{
				getline(inFile, name);
				getline(inFile, date);

				nameTree.insert(Person(true, name, date));
				dateTree.insert(Person(false, name, date));
			}
			inFile.close();
			break;	// leave loop if file open success
		}
		else {
			cout << "No file named \"InputData.txt\"" << endl;
			system("pause");
		}
	}

	// write output to path
	ofstream nameOutput(path + "NamesOutput.txt", ios::trunc);
	ofstream dateOutput(path + "BirthdaysOutput.txt", ios::trunc);

	nameOutput << "pre-order" << endl
		<< "name\t\tdate" << endl;
	nameTree.writeToFile(1, nameOutput);

	nameOutput << endl
		<< "post-order" << endl
		<< "name\t\tdate" << endl;
	nameTree.writeToFile(2, nameOutput);
	
	dateOutput << "In-Order" << endl
		<< "name\t\tdate" << endl;
	dateTree.writeToFile(3, dateOutput);

	dateOutput << endl
		<< "breadth-first" << endl
		<< "name\t\tdate" << endl;
	dateTree.writeToFile(4, dateOutput);

	nameOutput.close();
	dateOutput.close();
	
	cout << "Your files have been successfully written to:" << endl
		<< (path.length() > 0 ? path : "Current directory") << endl;

	system("pause");
	return 0;
}
