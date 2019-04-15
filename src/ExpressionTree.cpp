#include "ExpressionTree.h"

#include <stdlib.h>
#include <cmath>
#include <string>
#include <list>
#include <cctype>
#include <algorithm>

using std::stod;
using std::find;

ExpressionTree::ExpressionTree() : BinaryTree() {
	setExpression("");
}

ExpressionTree::ExpressionTree(std::string exp) : BinaryTree(exp) {
	setExpression(exp);  
	// Hopefully this works  
}

void ExpressionTree::setExpression(std::string exp) {
	clearTree();  
	expression = exp;
	tokenator();
	root = buildTree(root);
	//setQIterator();
}

BT_Node<string>* ExpressionTree::buildTree(BT_Node<string>* node) {
	std::cout << *iq << endl;
	if (*iq == "") {
		setData(node, *iq);
		return node;
	}
	if (*iq == "(") {
		iq++;
		setLeft(node, createNode());
		setLeft(node, buildTree(getLeft(node)));

	}
	if (isNumber(*iq)) {
		setData(node, *iq);
		iq++;
		return node;
	}
	if (isOperator(*iq)) {
		setData(node, *iq);
		iq++;
		setRight(node, createNode());
		setRight(node, buildTree(getRight(node)));
	}
	if (*iq == ")") {
		iq++;
		return node;
	}
	return node;
}

double ExpressionTree::getResult() {
	//Just to make it compile
	return -1;
}

void ExpressionTree::printParseTreeInOrder(std::ostream& os) {
	printInOrder(os);
}

void ExpressionTree::printParseTreePostOrder(std::ostream& os) {
	printPostOrder(os);
}

bool ExpressionTree::isOperator(string a) {
	bool isOp = true;
	list<string> ops = { "+", "-", "*", "/", "^", "(", ")" };
	if (find(ops.begin(), ops.end(), a) != ops.end()) {
		return isOp;
	}
	return !isOp;
}

bool ExpressionTree::isNumber(string a) {
	return isdigit(a[0]) ? true : false;  
}

double ExpressionTree::compute(string a, string b, string op) {
	if (op == "+")		{ return add(a, b); }
	else if (op == "-") { return sub(a, b); }
	else if (op == "*") { return mult(a, b); }
	else if (op == "/") { return div(a, b); }
	else if (op == "^") { return power(a, b); }
	return 0.0;
}

double ExpressionTree::add(string a, string b) {
	return stod(a) + atof(b.c_str());
}

double ExpressionTree::sub(string a, string b) {
	return stod(a) - stod(b);
}

double ExpressionTree::mult(string a, string b) {
	return stod(a) * stod(b);
}

double ExpressionTree::div(string a, string b) {
	return stod(a) / stod(b);
}

double ExpressionTree::power(string a, string b) {
	return pow(stod(a), stod(b));
}

void ExpressionTree::tokenator() {
	Q.clear();  
	string temp;
	int i = 0;
	while (i < expression.length()) {
		temp = "";
		if (isOperator(expression.substr(i, 1))) {
			temp += expression[i++];
			Q.push_back(temp);
			continue;
		}
		while (!isOperator(expression.substr(i, 1)) && i < expression.length()) {
			temp += expression[i++];
		}
		Q.push_back(temp);
	}

	setQIterator();
	std::cout << "Here >>> ";
	for (auto i = Q.begin(); i != Q.end(); ++i) {
		std::cout << *i << "";
	}
	std::cout << endl << *iq << endl;
}

void ExpressionTree::setQIterator() {
	if (expression == "") {
		Q.push_back(expression);
	}
	iq = Q.begin();
}

void ExpressionTree::getExp() {
	std::cout << expression << std::endl;  
}
