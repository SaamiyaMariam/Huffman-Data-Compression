// DATA STRUCTURES PROJECT                               //
// Saamiya Mariam (20i-0612) & Bisma Haroon (20i-0716)   //
// Section D                                             //
// // // // // // // // // // // // // // // // // // // //

#include <iostream>
using namespace std;

class Node
{
public:
	char data;
	int frequency;
	Node* left;
	Node* right;
	Node* next;
	//default constructor
	Node()
	{
		data = '\0';
		frequency = 1;
		left = NULL;
		right = NULL;
		next = NULL;
	}
	//parameterized constructor
	Node(char d, int f, Node* r, Node* l, Node* n)
	{
		data = d;
		frequency = f;
		left = l;
		right = r;
		next = n;
	}
};
