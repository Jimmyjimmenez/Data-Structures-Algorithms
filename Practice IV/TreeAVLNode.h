#pragma once
class TreeAVLNode
{
public:

	TreeAVLNode();

	int data;
	int equilibrium;
	int height;

	TreeAVLNode* right;
	TreeAVLNode* left;
};
