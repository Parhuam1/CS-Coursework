// Parhuam Jalalian
// Luke Fields
// Lab 3
// Partner's Contriubution 0 - Both did same work



#include <iostream>
#include <string>
#include <sstream>
#include "calculator.h"
#include "list.h"

using namespace std;

int main()
{
	Calculator calc;	
	// This loop breaks out when the user types in an empty infix string
	
	while (true) {
		cout << "Enter infix string (empty to exit): ";

		std::string infixstr;
		std::getline(cin, infixstr);
		
		if (infixstr.empty()) {
			break;
		}
		// check for valid expression
		else if (!calc.validExp(infixstr))
		{
			std::cout << "please enter a valid expression\n";
			continue;
		}
		else {
			calc.process_one_infix(infixstr);
		}
	}

	system("pause");
	return 0;
}