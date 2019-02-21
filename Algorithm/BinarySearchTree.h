#include<assert.h>
#include<iostream>
class BST
{
	struct treenode
	{
		treenode* left;
		treenode* right;
		int value;
		treenode(int val): left(nullptr), right(nullptr), value(val) {}
		void setleft(int val)
		{
			this->left = new treenode(val);
		}
		void setright(int val)
		{
			this->right = new treenode(val);
		}
	};
	
private:
	treenode* root;
	int nodecount;

public:
	BST(): root(new treenode(0)), nodecount(0) {};
	~BST() {clearall(root);}

	treenode* find(int val);
	void insert(int val);
	bool remove(int val)
	{
		if (nodecount == 0) return false;
		else return removehelp(root, val);
	}
	void printbyorder()
	{
		std::cout << "printbyorder:";
		print(root);
		std::cout << std::endl;
	}
	int size()
	{
		return nodecount;
	}

private:
	void clearall(treenode* node);
	bool removehelp(treenode*& node, int val);
	void print(treenode* node);
	int deletemin(treenode*& node);
};