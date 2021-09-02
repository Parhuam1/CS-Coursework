#pragma once
#include <string>
#include <sstream>
#include <iostream>

class Calculator
{
private:
	//std::string infix;
	//std::string postfix;

	// perform a calculation
	int calcOperator(int x, int y, char oper);

	bool isOperator(const char a);
	bool isOp(const char a);
	int precedenceCheck(char oper);

	// Reverse an expression string
	std::string reverse(std::string inputstr);

	int prefixstr_to_number(const std::string &inputstr, int &startpos);
	int prefixstr_to_number(const std::string &inputstr) {
		int startpos = 0;
		return prefixstr_to_number(inputstr, startpos);
	}

	// take an infix expression, return the result number and the postfix expression in the 2nd parameter
	int InfixtoPostfix(std::string input, std::string &pfx, bool resultAlso, bool post);


public:

	// take infix, print out both the prefix string, and the numeric result
	void doInfixtoPrefix(std::string infixstr);

	// take infix, print out both the postfix string, and the numeric result
	void doInfixtoPostfix(std::string infixstr);

	// Calculate and print both postfix and prefix (expressions and the numeric result)
	void process_one_infix(std::string infixstr);

	bool validExp(std::string str);
};

