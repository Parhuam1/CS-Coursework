// Parhuam Jalalian
// Luke Fields
// Lab 2
// Partner's Contriubution 0 - Both did same work
// currency.h

#pragma once

#ifndef CURRENCY_H
#define CURRENCY_H
#include <string>
#include <iostream>
class Wallet;

class  Currency
{
protected:
	int whole;						// integer - whole
	int part;						// integer - part
	std::string name;				// string - name
	std::string fraction;			// string - fraction

public:
	Currency();							// Contructor
	Currency(int w, int p, std::string n, std::string f);
	Currency(const Currency& copy);		// Copy Constructor
	~Currency();						// Deconstructor 

	friend class Menu;

	// overloaded operators

	Currency operator + (Currency &other);
	Currency operator - (Currency &other);
	bool operator == (const Currency &other);
	bool operator == (int other);
	friend std::ostream& operator << (std::ostream& os, const Currency& output);
	friend std::istream& operator >> (std::istream& input_1, Currency& obj_1);
};


class Dollar : public Currency
{
public:
	Dollar();						// Contructor
	Dollar(const Dollar &copy);	    // Copy Constructor
	~Dollar();						// Deconstructor 
};

class Euro : public Currency
{
public:
	Euro();							// Contructor
	Euro(const Euro &copy);			// Copy Constructor
	~Euro();						// Deconstructor 
};

class Rupee : public Currency
{
public:
	Rupee();						// Contructor
	Rupee(const Rupee &copy);		// Copy Constructor
	~Rupee();						// Deconstructor 
};

class Yen : public Currency
{
public:
	Yen();							// Contructor
	Yen(const Yen &copy);			// Copy Constructor
	~Yen();							// Deconstructor
};

class Yuan : public Currency
{
public:
	Yuan();							// Contructor
	Yuan(const Yuan &copy);			// Copy Constructor
	~Yuan();						// Deconstructor
};
#endif
