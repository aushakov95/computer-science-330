/*******************************************************************************
* Andrey Ushakov
* lab_01.cpp
* 01/17/16
* This program converts an infix expression into a prefix to postfix expression.
* Time complexity: O(n³)
********************************************************************************/
#include <iostream>
#include <stack>

using namespace std;

int prec(char o){
	int rank;
	if (o == '*' or o == '/')								//if the operator entered is * or / it will have the highest rank
		rank = 3;
	else if (o == '+' or o == '-')
		rank = 2;
	else if (o == '(')
		rank = 1;
	return rank;
}

int main(){
stack <char> operators;

char in;
cin >> in;

while (!cin.eof()){
	if ((in >= '0' and in <= '9') or (in >= 'a' and in <='z') or (in >= 'A' and in <= 'Z'))
		cout << in;
	else if(in == '(')
		operators.push(in);
	else if(in == ')') {

		while (operators.top() != '(' and !operators.empty()){
			cout << operators.top();
			operators.pop();
		}

		if (!operators.empty())
			operators.pop();							//pop the '('

	} else if (in == '*' or in == '/' or in == '+' or in == '-' ) {
			if ((operators.empty()) or (prec(operators.top()) < prec(in)))
				operators.push(in);
			else {

				while (!operators.empty()){
					cout << operators.top();
					operators.pop();
				}
				operators.push(in);
			}
		}
	cin >> in;
}

while (!operators.empty()){
	cout << operators.top();
	operators.pop();
}
cout << endl;
}



// An algorithm for infix to postfix expression conversion.
// For example,   a + b - c     translates to   a b + c -
//                a + b * c     translates to   a b c * +
//                (a + 2) / (5 - d)   goes to   a 2 + 5 d - /
//                a + ((b - c) * d) / e    to   a b c - d * e / +
// Valid operands are single digits and characters: 0-9 a-z A-Z
// Valid operators are: + - * / ( )
// Highest precedence:  * /
// Lowest precedence:   + -
// ( has lowest precedence on the stack and highest precedence outside of stack.
// ) never goes on stack.
// Bottom of the stack has the lowest precedence than any operator.
// Use a prec() function to compare the precedence of the operators based on the above rules.
// Note there is little error checking in the algorithm!
/*
while there is more input
	if input is an operand
		print input
	else
		if input is '('  // '(' has lowest precedence in the stack, highest outside
			push input on stack
		else if input is ')'
			while stack is not empty and top of stack is not '('
				print top of stack
				pop stack
			if stack is not empty
				pop stack
			else error  // no matching '('
		else if input is '*' or '/' or '+' or '-'
			if stack is empty or prec(top of stack) < prec(input) // bottom of stack has lower precedence than everything
				push input on stack
			else // prec(top of stack) >= prec(input)
				while stack is not empty and prec(top of stack) >= prec(input)
					print top of stack
					pop stack
				push input on stack
		else check for errors
while stack is not empty
	print top of stack
	pop stack
*/
