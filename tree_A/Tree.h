#pragma once
#include <iostream>
#include <string>
using namespace std;
class Tree
{
private:
	int changeData = 0;
	int data;
	Tree* left;
	Tree* right;
	Tree* tmp;

public:

	Tree(int num)
	{
		this->data = num;
		this->left = NULL;
		this->right = NULL;
		this->tmp = NULL;
	}

	~Tree() = default;

	void insertData(Tree* root, int value)
	{
		changeData = value;
		insert(root, changeData);
		return;
	}

	void insert(Tree* root, int dataa)
	{
		if (root == NULL) {
			Tree* root = new Tree(data);
		}
		else if (dataa <= root->data)
		{
			if (root->left != NULL)
				insert(root->left, dataa);
			else
				root->left = new Tree(dataa);
		}
		else if (dataa > root->data)
		{
			if (root->right != NULL)
				insert(root->right, dataa);
			else
				root->right = new Tree(dataa);
		}
	}

	void printTree(Tree* root, int space = 0, int t = 0)
	{
		int COUNT = 3;
		if (root == NULL)
			return;
		space += COUNT;
		printTree(root->right, space, 1);
		for (int i = COUNT; i < space; i++)
		{
			cout << " ";
		}
		if (t == 1)
		{ // Right node
			cout << "/ " << root->data << endl;
		}
		else if (t == 2)
		{ // Left node
			cout << "\\ " << root->data << endl;
		}
		else
		{ // Root node
			cout << root->data << endl;
		}
		printTree(root->left, space, 2);
	}

	void testser(Tree* first, int node1, int node2)
	{
		tmp = NULL;
		bool q = false;
		if (first->left == NULL && first->right == NULL)
		{
			throw "Exception < tree is empty! >";
			return;
		}
		else 
		{
			searchNode(first, node1, node2, q);
		}
		if (q == true)
		{
			printTree(first);
		}
		else
		{
			throw "Exception< can`t trade tree nods";
		}
		return;
	}

	void searchNode(Tree* newnode, int node1, int node2, bool& q)
	{
		if (node1 != newnode->data)
		{
			if (newnode->right != NULL)
			{
				searchNode(newnode->right, node1, node2, q);
			}
			if (newnode->left != NULL)
			{
				searchNode(newnode->left, node1, node2, q);
			}
		}
		if (newnode->left != NULL && newnode->right != NULL)
		{
			if ((newnode->left->data == node1 && newnode->right->data == node2)
				|| (newnode->right->data == node1 && newnode->left->data == node2))
			{
				tradeNods(newnode);
				q = true;
				return;
			}
		}
	}

	void tradeNods(Tree* newnode)
	{
		tmp = newnode->left;
		newnode->left = newnode->right;
		newnode->right = tmp;
		return;
	}
};