#include<iostream>

class RBtree
{
	struct treenode
	{
		treenode* parent;
		treenode* left;
		treenode* right;
		int value;
		char color;
		treenode(treenode* p, int val, int color): parent(p), left(nullptr), right(nullptr), value(val), color(color) {}
	};

private:
	/*旋转时根节点可能发生变化,维护一个head节点与根节点相互以parent指向
	左子节点指向最左(即最小)节点,右子节点指向最右(即最大)节点.
	    O <-head
	    |
	    O <-root
	   / \
	  A   B
	 */
	treenode* head;
	int nodecount;

public:
	RBtree(): head(new treenode(nullptr, -1, 'r')), nodecount(0)
	{
		//init
		head->left = head;
		head->right = head;
	}
	~RBtree()
	{
		clearall(head->parent);
		delete head;
	}
	//采用不可重复的插入方式
	treenode* insert(const int val);
	treenode* find(const int val);
	void printbyorder()
	{
		print(head->parent);
	}

private:
	//不允许有相同的值,x为插入节点,y为父结点
	treenode* insert_unique(treenode* x, treenode* y, const int val);
	void left_rotate(treenode* node);
	void right_rotate(treenode* node);
	//自上而下调整树型
	void rebanlance(treenode* node);
	void clearall(treenode* root);
	void print(treenode* root);
	/*
	获得比当前节点稍大/小的节点
	用于插入时和插入节点比较大小分辨是否有相同的值
	*/
	treenode* find_larger(treenode* node);
	treenode* find_smaller(treenode* node);
};
