// Parhuam Jalalian
// Luke Fields
// Lab 5
// Partner's Contriubution 0 - Both did same work
// Person.h
#pragma once

#include <string>
#include <fstream>
#include <iostream>


class Person 
{
public:
	// When comparing Persons with different orderByName fields, we always
	// place a "name" (i.e. true) person before any "birthday" (i.e. false) person,
	// regardless of the other fields.
	//
	// But assuming orderByName is the same, then we pay attention to
	// the other fields as follows: if true, then we compare by name first,
	// and then (if a tie) by birthdate.  If false, we compare by birthdate first,
	// and then (if a tie) by name.
	std::string name,
		date;
	bool orderByName; // if true, then we will compare by name, if false, we will compare by birthday

	Person(bool orderName, std::string n, std::string d) :
		orderByName(orderName),
		name(n),
		date(d)
	{}

	friend bool operator> (const Person &person_1, const Person &person_2);
	friend bool operator< (const Person &person_1, const Person &person_2);
	friend bool operator== (const Person &person_1, const Person &person_2);
	friend bool operator>= (const Person &person_1, const Person &person_2);
	friend std::ostream& operator<<(std::ostream& os, const Person &person);
};

bool operator> (const Person &person_1, const Person &person_2) {

	if (person_1.orderByName)
		return (person_1.name > person_2.name);
	else
		return (person_1.date > person_2.date);

};

bool operator< (const Person &person_1, const Person &person_2)
{
	if (person_1.orderByName)
		return (person_1.name < person_2.name);
	else
		return (person_1.date < person_2.date);
};


bool operator== (const Person &person_1, const Person &person_2) {
	if (person_1.orderByName)
		return (person_1.name == person_2.name);
	else
		return (person_1.date == person_2.date);
}

bool operator>= (const Person &person_1, const Person &person_2) {
	if (person_1.orderByName)
		return (person_1.name >= person_2.name);
	else
		return (person_1.date >= person_2.date);
}

std::ostream& operator<<(std::ostream& os, const Person& person)
{
	os << person.name << '\t' << person.date;
	return os;
};
