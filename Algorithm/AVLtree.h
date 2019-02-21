#include<assert.h>
#include<iostream>
class AVL
{
	struct treenode
	{
		treenode* left;
		treenode* right;
		int value;
		int height;
		treenode(int val, int h): left(nullptr), right(nullptr), value(val), height(h) {}
		void setleft(int val, int h)
		{
			this->left = new treenode(val, h);
		}
		void setright(int val, int h)
		{
			this->right = new treenode(val, h);
		}
	};
	
private:
	treenode* root;
	int nodecount;

public:
	AVL(): root(new treenode(0, 0)), nodecount(0) {};
	~AVL() {clearall(root);}

	treenode* find(int val);
	void insert(int val)
	{
		inserthelp(root, val);
		nodecount++;
	}
	void remove(int val)
	{
		if (nodecount == 0) {
			std::cout << "can't find " << val << std::endl;
			return;
		}
		else {
			if (removehelp(root, val))
				nodecount--;
		}
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
	int max(int a, int b)
	{
		return a > b ? a : b;
	}
	treenode* LLrotate(treenode* k1);
	treenode* LRrotate(treenode* k1);
	treenode* RRrotate(treenode* k1);
	treenode* RLrotate(treenode* k1);
	treenode* inserthelp(treenode*& node, int val);
	treenode* removehelp(treenode*& node, int val);
	void clearall(treenode* node);
	void print(treenode* node);
	int getheight(treenode* node)
	{
		return node == nullptr ? -1 : node->height;
	}
};