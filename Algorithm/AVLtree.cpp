#include"AVLtree.h"
AVL::treenode* AVL::find(int val)
{
	if (nodecount == 0) return nullptr;
	treenode* temp = root;
	while (temp->value != val)
	{
		while (temp != nullptr && temp->value > val) temp = temp->left;
		while (temp != nullptr && temp->value < val) temp = temp->right;
		if (temp == nullptr) return nullptr;
	}
	return temp;
}

void AVL::clearall(treenode* node)
{
	if (node == nullptr) return;
	clearall(node->left);
	clearall(node->right);
	delete node;
}

void AVL::print(treenode* node)
{
	if (node == nullptr) return;
	print(node->left);
	std::cout << node->value << " ";
	print(node->right);
}


/* LL(insert into leftchild's leftsubtree of k1):
    sigle rotate

        k1			    k2
       /  \			   /  \
      k2   A  			  B    K1
     /  \       ==>              /    / \
    B    C  			D    C   A
   /
  D
 */
AVL::treenode* AVL::LLrotate(treenode* k1)
{
	treenode* k2 = k1->left;
	k1->left = k2->right;
	k2->right = k1;
	k1->height = max(getheight(k1->left), getheight(k1->right)) + 1;
	k2->height = max(getheight(k2->left), getheight(k2->right)) + 1;
	return k2;
}

/* RR(insert into rightchild's rightsubtree of k1):
	sigle rotate

        k1				k2
       /  \		       	       /  \
      A   k2  			      k1   C
         /  \       ==>               / \    \
    	B    C  		     A   B    D
   	      \
  	       D
 */
AVL::treenode* AVL::RRrotate(treenode* k1)
{
	treenode* k2 = k1->right;
	k1->right = k2->left;
	k2->left = k1;
	k1->height = max(getheight(k1->left), getheight(k1->right)) + 1;
	k2->height = max(getheight(k2->left), getheight(k2->right)) + 1;
	return k2;
}

/* LR(insert into leftchild's rightsubtree of k1):
	double rotate

      k1                         k1                        k3
     /  \                       /  \                      /  \
    k2   A                     k3   A                    k2   k1
   /  \         ==>           /           ==>           / \    \
  B    k3                    k2                        B   C    A
      /                    /   \
     C                    B    	C
*/
AVL::treenode* AVL::LRrotate(treenode* k1)
{
	k1->left = RRrotate(k1->left);
	return LLrotate(k1);
}

/* RL(insert into rightchild's leftsubtree of k1):
	double rotate

      k1                       		  k1                        k3
     /  \                      		 /  \                      /  \
    A   k2                   	         A    k3                   k1   k2
       /  \         ==>                 /  \        ==>           /    /  \
      k3    B                          C   k2          		 A    C    B
     /                        		     \
    C                         		      B
*/
AVL::treenode* AVL::RLrotate(treenode* k1)
{
	k1->right = LLrotate(k1->right);
	return RRrotate(k1);
}

AVL::treenode* AVL::inserthelp(treenode*& node, int val)
{
	if (nodecount == 0) {
		root->value = val;
		return root;
	}
	if (node == nullptr)
		return (node = new treenode(val, 0));
	else if (node->value > val)
		node->left = inserthelp(node->left, val);
	else
		node->right = inserthelp(node->right, val);
	node->height = max(getheight(node->left), getheight(node->right)) + 1;
	if (getheight(node->left) - getheight(node->right) == 2)
	{
		if (val < node->left->value)
			node = LLrotate(node);
		else
			node = LRrotate(node);
	}
	else if (getheight(node->right) - getheight(node->left) == 2)
	{
		if (val < node->right->value)
			node = RLrotate(node);
		else
			node = RRrotate(node);
	}
	return node;
}

AVL::treenode* AVL::removehelp(treenode*& node, int val)
{
	if (node == nullptr)
	{
		std::cout << "can't find " << val << std::endl;
		return nullptr;
	}
	if (node->value == val)
	{
		if (node->right == nullptr)
		{
			treenode* temp = node;
			node = node->left;
			delete temp;
			return root;
		}
		else
		{
			treenode* temp = node->right;
			while (temp->left)
				temp = temp->left;
			node->value = temp->value;
			node->right = removehelp(node->right, temp->value);
		}
	}
	else if (node->value > val)
		return removehelp(node->left, val);
	else
		return removehelp(node->right, val);
	node->height = max(getheight(node->left), getheight(node->right)) + 1;
	if (getheight(node->left) - getheight(node->right) == 2)
	{
		if (val < node->left->value)
			node = LLrotate(node);
		else
			node = LRrotate(node);
	}
	else if (getheight(node->right) - getheight(node->left) == 2)
	{
		if (val < node->right->value)
			node = RLrotate(node);
		else
			node = RRrotate(node);
	}
	return node;
}
