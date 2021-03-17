/* 
	Assignment #3: Revisting Tree Nodes 
	Emma McAvoy
*/
#include <iostream>
#include <string.h>
#include "Treenode.h"
using namespace std;

int main()
{
	Treenode* P_testNode = new Treenode(14);
	P_testNode->setID(13);
	cout << "The Test tree node value's are: " << P_testNode->getID() << endl;

	/*
		I created all the objects on the stack, instead of the heap. Therefor, nothing in the destructor 
		once, it goes out of the scope of main. it will be deleted automatically. 
	*/

	/*
		****Testing for week 1****
	*/
	Treenode n1(1);
	Treenode n2(2);
	Treenode n0(0);
	Treenode n3(3);
	Treenode n4(4);
	Treenode n5(5);
	Treenode n6(6);
	
	n0.setChild(&n1);
	n1.setChild(&n3);
	n0.setChild2(&n2);
	n2.setChild(&n4);
	n2.setChild2(&n5);

	bool ret = n0.isChild(&n4);
	bool ret2 = n0.isConnected(&n5);
	bool ret4 = n5.isLeafNode(&n5);
	bool ret9 = n0.isChild(&n6);
	bool ret11 = n0.isLeafNode(&n1);
	
	cout << ret << endl;
	cout << ret2 << endl;
	cout << ret4 << endl; 
	cout << ret9 << endl; 

	/* 
		*****Testing for Week 2*****
	*/
	string ret22 = n0.getTxtInfo();
	cout << ret22 << endl; 

	
	return 0;
}
