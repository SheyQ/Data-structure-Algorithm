#include"RBtree.h"
RBtree::treenode* RBtree::find(int val)
{
	if (nodecount == 0) return nullptr;
	treenode* temp = head->parent;
	while (temp->value != val)
	{
		while (temp != nullptr && temp->value > val) temp = temp->left;
		while (temp != nullptr && temp->value < val) temp = temp->right;
		if (temp == nullptr) return nullptr;
	}
	return temp;
}

void RBtree::clearall(treenode* root)
{
	if (root == nullptr) return;
	clearall(root->left);
	clearall(root->right);
	delete root;
}

void RBtree::print(treenode* node)
{
	if (node == nullptr) return;
	print(node->left);
	std::cout << node->value << " ";
	print(node->right);
}

RBtree::treenode* RBtree::find_larger(treenode* node)
{
	if (node == head->right) return nullptr;//已是最大节点
	if (node->right != nullptr)
	{
		node = node->right;
		while (node->left != nullptr)
			node = node->left;
		return node;
	}
	else
	{
		treenode* p = node->parent;
		while (p->right == node)
		{
			node = p;
			p = p->parent;
		}
		if (node->right != p)
			node = p;
		return node;
	}
}

RBtree::treenode* RBtree::find_smaller(treenode* node)
{
	if (node == head->left) return nullptr; //已是最小节点
	if (node->left != nullptr)
	{
		node = node->left;
		while (node->right != nullptr)
			node = node->right;
		return node;
	}
	else
	{
		treenode* p = node->parent;
		while (p->left == node)
		{
			node = p;
			p = p->parent;
		}
		return p;
	}
}

/*
r2插入在r1左子节点违反规则,对b右旋转
改变r1和b的颜色(在之后的rebalance调整里进行，rotate函数只进行旋转.)
假设A,B为nullptr
     b               r1              b(r1)
    / \			    / \				/ \
   r1  A   ==>     r2  b    ==>	   r2  r3(b)
  / \                 / \              / \
 r2  B				 B	 A            B   A
*/
void RBtree::right_rotate(treenode* node)
{
	treenode*& root = head->parent;
	treenode* r1 = node->left;
	node->left = r1->right;
	if (r1->right != nullptr) //set parent
		r1->right->parent = node;
	r1->parent = node->parent;
	if (node == root) //set root
		root = r1;
	else if (node == node->parent->right)
		node->parent->right = r1;
	else
		node->parent->left = r1;
	r1->right = node;
	node->parent = r1;
}

void RBtree::left_rotate(treenode* node)
{
	treenode*& root = head->parent;
	treenode* r1 = node->right;
	node->right = r1->left;
	if (r1->left != nullptr)
		r1->left->parent = node;
	r1->parent = node->parent;
	if (node == root)
		root = r1;
	else if (node == node->parent->left)
		node->parent->left = r1;
	else
		node->parent->right = r1;
	r1->left = node;
	node->parent = r1;
}


RBtree::treenode* RBtree::insert(const int val)
{
	if (nodecount == 0)
	{
		nodecount++;
		head->parent = new treenode(head, val, 'b');
		head->left = head->parent;
		head->right = head->parent;
		return head->parent;
	}
	treenode* y = head;
	treenode* x = head->parent;
	while (x != nullptr)
	{
		y = x;
		x = val < x->value ? x->left : x->right;
	}
	treenode* p = y;
	if (val < y->value)
	{
		if (p == head->left)
			return insert_unique(x, y, val);
		else
			p = find_smaller(p);
	}
	if (val > p->value)
		return insert_unique(x, y, val);
	//值重复,不插入,返回空指针
	return nullptr;
}

RBtree::treenode* RBtree::insert_unique(treenode* x, treenode* y, const int val)
{
	treenode* newnode = new treenode(y, val, 'r');
	if (y == head || x != 0 || val < y->value)
	{
		y->left = newnode;
		if (y == head)
		{
			head->parent = head->right;
			head->right = newnode;
		}
		else if (y == head->left)
			head->left = y->left;
	}
	else
	{
		y->right = newnode;
		if (y == head->right)
			head->right = newnode;
	}
	nodecount++;
	rebanlance(newnode);//调整新插入的节点
	return newnode;
}

void RBtree::rebanlance(treenode* node)
{
	treenode*& root = head->parent;
	while (node != root && node->parent->color == 'r')
	{
		if (node->parent == node->parent->parent->left)
		{
			treenode* temp = node->parent->parent->right;
			if (temp && temp->color == 'r')
			{
				node->parent->color = 'b';
				temp->color = 'b';
				node->parent->parent->color = 'r';
				node = node->parent->parent;
			}
			else
			{
				if (node == node->parent->right)
				{
					node = node->parent;
					left_rotate(node);
				}
				node->parent->color = 'b';
				node->parent->parent->color = 'r';
				right_rotate(node->parent->parent);
			}
		}
		else
		{
			treenode* temp = node->parent->parent->left;
			if (temp && temp->color == 'r')
			{
				node->parent->color = 'b';
				temp->color = 'b';
				node->parent->parent->color = 'r';
				node = node->parent->parent;
			}
			else
			{
				if (node == node->parent->left)
				{
					node = node->parent;
					right_rotate(node);
				}
				node->parent->color = 'b';
				node->parent->parent->color = 'r';
				left_rotate(node->parent->parent);
			}
		}
	}
	root->color = 'b';
}

int main(int argc, char const *argv[])
{
	RBtree rbtree;
	rbtree.insert(10);
	rbtree.insert(9);
	rbtree.insert(10);
	rbtree.insert(33);
	rbtree.insert(0);
	rbtree.insert(-2);
	rbtree.insert(32);
	//-2 0 9 10 32 33
	rbtree.printbyorder();
	return 0;
}