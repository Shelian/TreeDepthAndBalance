#pragma once
#include"TreeDepth.h"
struct ListNode
{
	int _value;
	Node* _left;
	Node* _right;

	ListNode(const int & x)
		:_value(x)
		, _left(NULL)
		, _right(NULL)
	{}
};

bool IsBalance(Node* root)
{
	if (root == NULL)
		return true;

	int left = TreeDepth(root->_left);
	int right = TreeDepth(root->_right);
	if (abs(left - right) > 1)
		return false;

	return IsBalance(root->_left) && IsBalance(root->_right);
}


void TestIsBalance()
{
	Node* p1 = new Node(1);
	Node* p2 = new Node(2);
	Node* p3 = new Node(3);
	Node* p4 = new Node(4);
	Node* p5 = new Node(5);
	Node* p6 = new Node(6);
	Node* p7 = new Node(7);

	p1->_left = p2;
	p2->_left = p4;
	p2->_right = p5;
	p5->_left = p7;
	p1->_right = p3;
	p3->_right = p6;

	cout << IsBalance(p1) << endl;
}