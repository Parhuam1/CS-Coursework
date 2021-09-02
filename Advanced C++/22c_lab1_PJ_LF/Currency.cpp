// Parhuam Jalalian
// Luke Fields
// 22C Fall 2018
// Last edited: 9/28/2018

#include "currency.h"
#include <string>

// Default constructor 
Currency::Currency() 
{
	whole = 0;
	part = 0;
}

// Copy Constructor
Currency::Currency(int w, int p, std::string n, std::string f)
{
	whole = w;
	part = p;
	name = n;
	fraction = f;
}
// Copies the variables of currency
Currency::Currency(const Currency& copy)
{
	whole = copy.whole;
	part = copy.part;
	name = copy.name;
	fraction = copy.fraction;
}

// Deconstructor
Currency::~Currency()
{
}

// Operator +
Currency Currency::operator+(Currency &other) {
	return Currency(whole + other.whole, part + other.part, name, fraction);
}

// Operator -
Currency Currency::operator-(Currency &other) {
	int a = ( (other.whole * 100) + other.part);
	int b = ( (whole * 100) + part );
	int c = b - a;

	b = c % 100;
	c /= 100;

	// assign values to currency object
	return Currency(c, b, name, fraction);
}



// input stream operator
std::ostream& operator << (std::ostream& os, const Currency& output)
{
	os	<< output.whole << ", "
		<< output.name << ", "
		<< output.part << ", "
		<< output.fraction;

	return os;
}

// outstream operator overload
std::istream& operator >> (std::istream& input_1, Currency &obj_1)
{
	double temp;
	int a, b;


	std::cout << "\t\tPlease enter an amount in the form of xx.xx?\n";
	std::cout << "\t\t";
	// convert input from double to whole and part ints
	input_1 >> temp;
	while (temp < 0)
	{
		std::cout << "\t\tplease enter a number greater than 0\n";
		std::cout << "\t\t";
		input_1 >> temp;
	}
	a = temp * 100;
	b = a % 100;
	a /= 100;

	// assign values to currency object
	obj_1.whole = a;
	obj_1.part = b;

	// return ostream object ref
	return input_1;
}



// Constructor Dollar
Dollar::Dollar() : Currency()
{
	// call Currency constructor initialization set on integer values
	name = "Dollar";
	fraction = "cent";
}
Dollar::Dollar(const Dollar &copy) : Currency(copy) {} // Copy constructor
Dollar::~Dollar() {} // Deconstructor

// Constructor Euro
Euro::Euro() : Currency()
{
	name = "Euro";
	fraction = "cent";
}
Euro::Euro(const Euro &copy) : Currency() {} // Copy Constructor
Euro::~Euro() {}	// Deconstructor

// Constructor Rupee
Rupee::Rupee() : Currency()
{
	// call Currency constructor initialization set on integer values
	name = "Rupee";
	fraction = "paise";
}
Rupee::Rupee(const Rupee &copy) : Currency(copy) {} // Copy constructor
Rupee::~Rupee() {}	// Deconstructor


// Yen Constructor
Yen::Yen() : Currency()
{
	name = "Yen";
	fraction = "sen";
}
Yen::Yen(const Yen &copy) : Currency(copy) {}	// Copy constructor
Yen::~Yen() {} //Deconstructor

// Yuan Constructor
Yuan::Yuan() : Currency()
{
	name = "Yuan";
	fraction = "fen";
}
Yuan::Yuan(const Yuan &copy) : Currency(copy) {} // Copy Constructor
Yuan::~Yuan() {} // Deconstructor