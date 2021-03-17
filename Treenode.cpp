/*
	Assignment #3: Revisting Tree Nodes
	Emma McAvoy
*/
#include "Treenode.h"

Treenode::Treenode()
	:_id(0),
	_child1(0),
	_child2(0)
{
	unsigned int _id();
	Treenode* _child1();
	Treenode* _child2();
}

Treenode::Treenode(unsigned int num)
	:_id(num),
	_child1(0),
	_child2(0)
{
}

Treenode::~Treenode()
{
}

Treenode::Treenode(const Treenode& other)
	:_id(other._id),
	_child1(other._child1),
	_child2(other._child2)
{
}

Treenode& Treenode::operator=(Treenode& rhs)
{
	_id = rhs._id;
	_child1 = rhs._child1;
	_child2 = rhs._child2;
	return *this;
}

void Treenode::setID(int num)
{
	_id = num;
}

unsigned int Treenode::getID() const
{
	return _id;
}

void Treenode::setChild(Treenode* num)
{
	_child1 = num;
}

Treenode* Treenode::getChild()
{
	return _child1;
}

void Treenode::setChild2(Treenode* num)
{
	_child2 = num;
}

Treenode* Treenode::getChild2()
{
	return _child2;
}

/// <summary>
///  Checks if the current node is connected to the node pointer
/// </summary>
/// <param name="P_node2"> pointer to a node </param>
/// <returns> false if the two nodes are not connected. true if they are </returns>
bool Treenode::isConnected(Treenode* P_node2)
{
	if (this == P_node2)
	{
		return true;
	}
	bool result = false;
	if (P_node2 != nullptr)
	{
		result = this->isChild(P_node2);
	}
	return result; 
}

/// <summary>
/// Determines if the node being passed in is a leaf or not
/// </summary>
/// <param name="P_node"> node being pointed too in the tree </param>
/// <returns> true if it is a leaf, false if it is not </returns>
bool Treenode::isLeafNode(Treenode* P_node)
{
	if (P_node != nullptr && P_node->_child1 == nullptr && P_node->_child2 == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}	
}

/// <summary>
/// Determins if the node being pointed too is a child of the tree / part of the tree
/// </summary>
/// <param name="child"> node being pointed too </param>
/// <returns> true if is a child in the tree, false if it is not a child </returns>
bool Treenode::isChild(Treenode* child)
{
	bool result = false;
	if (this == child)
	{
		return true;
	}

	if (_child1 != nullptr)
	{
		result = _child1->isChild(child);
	}

	if (!result && _child2 != nullptr)
	{
		result = _child2->isChild(child);
	}
	return result;
}

/// <summary>
/// Gets the ID of the current node and the corrposending information about it's childern
/// </summary>
/// <returns> a string contain it's ID and the ID of its childern,
///  --- if no child pointed to.
/// </returns>
string Treenode::getTxtInfo()
{
	char ignore = '---';
	unsigned int child1 = 0;
	unsigned int child2 = 0;
	string result; 

	unsigned int cur_num = getID();
	bool test = isLeafNode(this);

	if (test == true)
	{
		child1 = ignore;
		child2 = ignore;
	}

	else if (test == false)
	{
		bool result2 = isChild(this->_child1);
		bool result3 = isChild(this->_child2);
		
		if (result2 == false)
		{
			child1 = ignore;
		}
		else if (result2 == true)
		{
			child1 = _child1->getID();
		}

		if (result3 == false)
		{
			child2 = ignore;
		}
		else if (result3 == true)
		{
			child2 = _child2->getID();
		}
	}
	string myNumTxt = to_string(cur_num);
	string child_1 = to_string(child1);
	string child_2 = to_string(child2);
	result = "Treenode " + myNumTxt + " has child " + child_1 + " and " + child_2;

	return result;
}

Tree2400::Tree2400()
	:_P_root(0)
{
	Tree2400* _P_root(0);
}

Tree2400::Tree2400(unsigned int num)
	: _P_root(0)
{
}

Tree2400::~Tree2400()
{
}

Tree2400::Tree2400(const Tree2400& other)
	:_P_root(other._P_root)
{
}

Tree2400& Tree2400::operator=(Tree2400& rhs)
{
	_P_root = rhs._P_root;
	return *this;
}

