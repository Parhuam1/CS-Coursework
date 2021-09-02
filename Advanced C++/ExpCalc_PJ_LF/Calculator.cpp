
#include "queue.h"
#include "stack.h"
#include "calculator.h"
#include <string>
#include <sstream>


// Dealing with properties and manipulation of numbers
int Calculator::calcOperator(int x, int y, char oper)
{
	switch (oper)
	{
		case '+': 
			return x + y;
		case '-':
			return x - y;
		case '*': 
			return x * y;
		case '/': 
			if (y == 0) {
				throw "Divide by zero";
			}
			return x / y;
		case '%':
			return x % y;
		case '^':
			throw "Exponentiation is not implemented";
		default:
			throw "Bad operator given to calcOperator()";
	}
}

// Find a given character is an operator or not
bool Calculator::isOperator(const char a)
{
	//check  various operators
	if (a == '+' || a == '-' || a == '*' || a == '/' || a == '^' || a == '%' || a == '(' || a == ')')
		return true;
	else
		return false;
}

bool Calculator::isOp(const char a)
{
	//check  various operators
	if (a == '+' || a == '-' || a == '*' || a == '/' || a == '^' || a == '%')
		return true;
	else
		return false;
}

// Find precedence of oper. 
int Calculator::precedenceCheck(char oper) 
{
	if (oper == '+' || oper == '-')
		return 1;
	if (oper == '*' || oper == '/' || oper == '%')
		return 2;
	if (oper == '^')
		return 3;
	// parens
	return 0;
}

// Infix to Postfix, Double Stack method
// Always calculates the postfix expression into "pfx" parameter.
// If boolean parameter is true, also calculates the result.
// We need the boolean parameter because sometimes (when called
// from postfix-to-prefix code) we only want the expression, and
// trying to calculate a number could give a bogus divide by zero.
int Calculator::InfixtoPostfix(std::string input, std::string &pfx, bool resultAlso, bool post) 
{
	Stack <int> numbers;
	Stack <char> oper;
	int i;
	
	pfx.clear();
	
	for (i = 0; i < input.length(); i++) 
	{
		char c = input[i];
		// Skip Whitespace
		if (c == ' ')
			continue;

		// Push brace to oper
		else if (c == '(') 
		{
			oper.push(c);
		}

		// Push number to stack
		else if (isdigit(c))  // isdigit checks whether input[i] is a decimal digit character
		{
			int val = 0;

			// If more than one digit
			while (i < input.length() && isdigit(input[i]))
			{
				val = (val * 10) + (input[i] - '0');
				i++;
			}
			i--; // outer for loop always increments i by 1.  In this case we don't want that, so the i-- neutralizes it.
			
			if (resultAlso) {
				numbers.push(val);
			}

			pfx += " "; // in postfix and prefix, a space is needed to cleanly separate two numbers next to each other.
			pfx += std::to_string(val);
		}
		else if (c == ')')
		{
			// For a close parenthesis, consume all operators up to and including the matching open parenthesis
			while (!oper.isEmpty() && oper.top() != '(')
			{
				if (resultAlso) {
					if (numbers.getCount() < 2) {
						throw "Not enough numbers to process an operator";
					}
					int val2 = numbers.top();
					numbers.pop();

					int val1 = numbers.top();
					numbers.pop();
				
					char op = oper.top();
					numbers.push(calcOperator(val1, val2, op));
				}

				char op = oper.top();
				oper.pop();

				pfx += " ";
				pfx += op;

				if (resultAlso) {
				}
			}

			// Pop the matching open parens
			if (oper.top() != '(')
			{
				throw "Close ) needs a (";
			}

			oper.pop(); // throw avoids this line
		}
		else if (isOperator(c))
		{
			// We have a regular non-parenthesis operator.
			// Push it onto the operator stack, but first pop all operators of >= precedence
			// to 'c'.  For each operator that we pop, pop 2 numbers to go with it.
			if (post)
			{
				while (!oper.isEmpty() && precedenceCheck(oper.top()) >= precedenceCheck(c))
				{
					if (resultAlso) {
						if (numbers.isEmpty()) {
							throw "Malformed input - not enough numbers for an operator";
						}
						int val2 = numbers.top();
						numbers.pop();

						if (numbers.isEmpty()) {
							throw "Malformed input - not enough numbers for an operator";
						}
						int val1 = numbers.top();
						numbers.pop();

						char op = oper.top();
						numbers.push(calcOperator(val1, val2, op));
					}

					char op = oper.top();
					oper.pop();

					pfx += " ";
					pfx += op;
				}
			}
			if (!post)
			{
				while (!oper.isEmpty() && precedenceCheck(oper.top()) > precedenceCheck(c))
				{
					if (resultAlso) {
						if (numbers.isEmpty()) {
							throw "Malformed input - not enough numbers for an operator";
						}
						int val2 = numbers.top();
						numbers.pop();

						if (numbers.isEmpty()) {
							throw "Malformed input - not enough numbers for an operator";
						}
						int val1 = numbers.top();
						numbers.pop();

						char op = oper.top();
						numbers.push(calcOperator(val1, val2, op));
					}

					char op = oper.top();
					oper.pop();

					pfx += " ";
					pfx += op;
				}
			}

			// Push input to operator stack
			oper.push(c);
		}
		else {
			throw "Bad input character";
		}
	}

	// All done with input.  Need to drain all pushed operators that have not yet been popped.
	while (!oper.isEmpty()) {
		if (resultAlso) {
			if (numbers.isEmpty()) {
				throw "Malformed input - not enough numbers for an operator";
			}
			int val2 = numbers.top();
			numbers.pop();

			if (numbers.isEmpty()) {
				throw "Malformed input - not enough numbers for an operator";
			}
			int val1 = numbers.top();
			numbers.pop();
		
			char op = oper.top();
			numbers.push(calcOperator(val1, val2, op));
		}

		char op = oper.top();
		oper.pop();

		pfx += " ";
		pfx += op;
	}

	if (resultAlso) {
		// Return result
		if (numbers.getCount() != 1) {
			throw "When all done calculating, we need to have exactly 1 number on the number stack";
		}
		int result = numbers.top();
		numbers.pop();

		return result;
	}
	else {
		return 0;
	}
}


int Calculator::prefixstr_to_number(const std::string &inputstr, int &startpos)
{
	// processing a prefix equation is a recursive process:
	// for each operator, we recursively call this function twice
	// to get the inputs for the operator.
	// startpos is modified in place.

	if (startpos >= inputstr.size()) {
		throw "out of range";
	}

	// Consume all leading spaces, if any
	while (startpos < inputstr.size() && inputstr[startpos] == ' ') {
		startpos++;
	}

	if (startpos >= inputstr.size()) {
		throw "out of range";
	}

	// When parsing a prefix subexpression, we expect one of two things:
	// 1) a single number.  If so, just return it.
	// 2) an operator.  If so, then recursively call this function twice to
	// get the left and right sides of that operator, do the math, and return it.
	char c = inputstr[startpos];

	if (isdigit(c)) {
		// parse and return a single number
		int val = 0;

		// If more than one digit
		while (startpos < inputstr.length() && isdigit(inputstr[startpos]))
		{
			val = (val * 10) + (inputstr[startpos] - '0');
			startpos++;
		}

		return val;
	}
	
	if (!isOperator(c)) {
		throw "Expected to see an operator here";
	} else 	if (c == '(' || c == ')') {
		throw "Prefix should never have ( or )";
	}

	startpos++;

	int left_side_result = prefixstr_to_number(inputstr, startpos);
	int right_side_result = prefixstr_to_number(inputstr, startpos);

	// we have the left and the right.  Now we just combine with the operator 'op'
	return calcOperator(left_side_result, right_side_result, c);
}

std::string Calculator::reverse(std::string inputstr) {
	// An element is a number or an operator
	Stack<std::string> elements;

	int i = 0;
	while (i < inputstr.length()) {
		char c = inputstr[i];
		i++;

		if (c == ' ') {
			continue;
		}
		else if (isOperator(c)) {
			// after swapping ( and ) if appropriate, push onto elements
			if (c == '(') {
				c = ')';
			}
			else if (c == ')') {
				c = '(';
			}

			std::string op_as_str;
			op_as_str += c;

			elements.push(op_as_str);
		}
		else if (isdigit(c)) {
			std::string num_as_str;
			num_as_str += c;
			
			while (i < inputstr.length() && isdigit(inputstr[i])) {
				num_as_str += inputstr[i];
				i++;
			}

			// put this number onto the stack
			elements.push(num_as_str);
		}
		else {
			throw "unexpected input character when reversing string";
		}
	}

	// Pop all strings from the stack.  For each such string, append to result.
	std::string result;
	while (!elements.isEmpty()) {
		std::string elem = elements.top();
		elements.pop();

		result += " ";
		result += elem;
	}
	return result;
}

void Calculator::doInfixtoPrefix(std::string infixstr)
{
	// infix-to-prefix makes use of code for infix-to-postfix.
	// 1) reverse the input (not char by char: need to preserve numbers).
	//    This include swapping '(' with ')'
	// 2) get the postfix from that reversed input string
	// 3) reverse one more time

	try {
		std::string reversed_infixstr = reverse(infixstr);
		std::string postfixstr;
		int ignore_result = InfixtoPostfix(reversed_infixstr, postfixstr, false, false);
		std::string prefixstr = reverse(postfixstr);

		int result = prefixstr_to_number(prefixstr);
		std::cout << "prefix string is: " << prefixstr << std::endl;
		std::cout << "prefix result is: " << result << std::endl;
	}
	catch (const char *errmsg) {
		std::cout << "Could not calculate prefix: caught exception: " << errmsg << std::endl;
	}
}

void Calculator::doInfixtoPostfix(std::string inputstr)
{
	try {
		std::string postfixstr;
		int answer = InfixtoPostfix(inputstr, postfixstr, true, true);

		std::cout << "postfix string is: " << postfixstr << std::endl;
		std::cout << "postfix result is: " << answer << std::endl;
	}
	catch (const char *errmsg) {
		std::cout << "\nException caught.  Input was: " << inputstr << ", error: " << errmsg << std::endl;
	}
}

void Calculator::process_one_infix(std::string infixstr) {
	std::cout << "For infix input: " << infixstr << std::endl;

	doInfixtoPostfix(infixstr);
	doInfixtoPrefix(infixstr);
}

bool Calculator::validExp(std::string str) {
	int size = str.length();
	int pCount = 0, oCount = 0, dCount = 0;
	char prev = '\0', cur = '\0';
	for (int i = 0; i < size; i++) {
		if (str[i] == '(')
			pCount++;
		if (str[i] == ')')
			pCount--;
		if (pCount < 0)
			return false;
	}
	for (int i = 0; i < size; i++) {
		cur = str[i];	// set cur ith element

		// check for matching parentheses
		if (cur == '(')
			pCount++;
		if (cur == ')')
			pCount--;
		if (pCount < 0)		// check for unopened parentheses
			return false;

		if (cur == ' ')
			continue;		// skip spaces
		if (isOp(cur) && isOp(prev)) {
			return false;	// invalid if two operators in a row
		}
		if (prev == '('  && isOp(cur))
			return false;	// check for unary operators after parens
		if (cur == '(' && !isOp(prev) && prev != '(')
			return false;	// make sure operator between operand and parens
		if (cur == ')' && isOp(prev))
			return false;	// check for hanging operator
		if (isOp(cur))
			oCount++;		// add to operator count
		if (!isOp(cur))
			dCount++;		// add to operand count
		if (!isOp(cur) && !isOp(prev) && prev != '\0')
			dCount--;		// normalize operand count for multi digit operands

		prev = cur;
	}
	if (pCount != 0 || dCount <= oCount)
		return false;		// invalid if more closing parens or too many operators
	return true;
}