#ifndef H_Expression_Tree
#define H_Expression_Tree

#include "BinaryTree.h"
#include <iostream>
#include <string>
#include <list>

using std::string;
using std::list;

class ExpressionTree : private BinaryTree<std::string> {
private:
	string expression;
	list<string> Q;
	list<string>::iterator iq;
	
	BT_Node<string>* buildTree(BT_Node<string>* node);
	bool isOperator(string a);
	bool isNumber(string a);
	double compute(string a, string b, string op);
	double add(string a, string b);
	double sub(string a, string b);
	double mult(string a, string b);
	double div(string a, string b);
	double power(string a, string b);
	void tokenator();
	void setQIterator();  
//	void printTreeInOrder(std::ostream& os);
//	void printTreePostOrder(std::ostream& os);


public:
	ExpressionTree();
	ExpressionTree(std::string exp);
	void setExpression(std::string exp);
	double getResult();
	void printParseTreeInOrder(std::ostream& os);
	void printParseTreePostOrder(std::ostream& os);
	
	void getExp();
};
#endif