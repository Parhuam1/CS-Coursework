 // Parhuam Jalalian
// Luke Fields
// Lab 4
// Partner's Contriubution 0 - Both did same work

#include <iostream>
#include <string>
#include "array.h"
#include "sorting.h"

using namespace std;

int main()
{
	const int SORT_MAX_SIZE = 32;

	while (true) {	
		std::cout << "\nMain Menu" << std::endl
			<< "Please select a data type" << std::endl << std::endl
			<< "1. Integer" << std::endl
			<< "2. Double" << std::endl
			<< "3. Character" << std::endl
			<< "4. String" << std::endl
			<< "5. Exit" << std::endl;

		
		int response;
		cout << "Reponse: ";
		cin >> response;
		if (isdigit(response)) {
			cin.clear(); // clear the error flags
			cin.ignore(INT_MAX, '\n'); // discard the row
			cout << "\nError, type an integer response\n";
			continue;
		}
		if (response == 5)
			return 0;
		

		int size = 0;
		cout << "\nType in your array size: \n";
		cin >> size;
		if (cin.fail())	{
			cin.clear(); // clear the error flags
			cin.ignore(INT_MAX,'\n'); // discard the row
			cout << "Error, You must type an integer for array size. \n";
			continue;
		}
		if (size > SORT_MAX_SIZE) {
			cout << "\nError, Size is not valid, size can be at most " << SORT_MAX_SIZE << endl;
			continue;
		}
		if (size <= 0) {
			cout << "\nError, Size is not valid, size must be more than 0 " << endl;
			continue;
		}


		switch (response)
		{
		case 1: {
			// Integer

			Array<int> aList(size);
			for (int i = 0; i < size; i++) {
				std::cout << "Enter item " << i + 1 << ": ";
				int item;
				aList[i] = validate(item);
			}

			sortArray(aList);
			break;
		}
		case 2: {
			// Double

			Array<double> aList(size);
			for (int i = 0; i < size; i++) {
				std::cout << "Enter item " << i + 1 << ": ";
				double item;
				aList[i] = validate(item);
			}

			sortArray(aList);
			break;
		}
		case 3: {
			// char

			Array<char> aList(size);
			for (int i = 0; i < size; i++) {
				std::cout << "Enter item " << i + 1 << ": ";
				char item;
				aList[i] = validate(item);
			}

			sortArray(aList);
			break;
		}
		case 4:{
			// string
			Array<string> aList(size);
			for (int i = 0; i < size; i++) {
				std::cout << "Enter item " << i + 1 << ": ";
				string item;
				aList[i] = validate(item);
			}

			sortArray(aList);
			break;
		}
		default:
			cout << "Error, response does not match any of the options on the menu, retry again.\n";
			break;
		}
	}

	system("pause");
	return 0;
}