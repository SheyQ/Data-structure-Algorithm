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
	void clearall(treenode* node);
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
	treenode* root;
	int nodecount;
	bool removehelp(treenode*& node, int val);
	void print(treenode* node);
	int deletemin(treenode*& node)
	{
		if (node->left == nullptr)
		{
			int res = node->value;
			if (node->right != nullptr)
			{
				treenode* temp = node;
				node = node->right;
				delete temp;
			}
			else
			{
				delete node;
				node = nullptr;
			}
			return res;
		}
		else
			return deletemin(node->left);
	}
};