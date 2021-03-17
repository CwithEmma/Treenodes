/*
	Assignment #3: Revisting Tree Nodes
	Emma McAvoy
*/
#pragma once
#include <string>
using namespace std;

class Treenode
{
public:
	Treenode();
	Treenode(unsigned int num);
	~Treenode();
	Treenode(const Treenode& other);
	Treenode& operator=(Treenode& rhs);

public:
	void setID(int num);
	unsigned int getID() const; 
	void setChild(Treenode* num);
	Treenode* getChild();
	void setChild2(Treenode* num);
	Treenode* getChild2();

public:
	bool isConnected(Treenode* P_node2);
	bool isLeafNode(Treenode* P_node);
	bool isChild(Treenode* P_node2);
	string getTxtInfo();
	

private:
	unsigned int _id;
	Treenode* _child1;
	Treenode* _child2;
};

class Tree2400 
{
private:
	Treenode* _P_root;
public:
	Tree2400();
	Tree2400(unsigned int num);
	~Tree2400();
	Tree2400(const Tree2400& other);
	Tree2400& operator=(Tree2400& rhs);
};


