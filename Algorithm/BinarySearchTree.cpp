#include"BinarySearchTree.h"

BST::treenode* BST::find(int val)
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

int BST::deletemin(treenode*& node)
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

void BST::insert(int val)
{
	if (nodecount == 0) root->value = val;
	else
	{
		treenode* temp = root;
		for (;;)
		{
			if (val >= temp->value)
			{
				if (temp->right != nullptr)
					temp = temp->right;
				else
				{
					temp->setright(val);
					break;
				}
			}
			else
			{
				if (temp->left != nullptr)
					temp = temp->left;
				else
				{
					temp->setleft(val);
					break;
				}
			}
		}
	}
	nodecount++;
}

bool BST::removehelp(treenode*& node, int val)
{
	if (node == nullptr)
	{
		std::cout << "can't find " << val << std::endl;
		return false;
	}
	else if (node->value == val)
	{
		nodecount--;
		if (node->left == nullptr && node->right == nullptr)
		{
			delete node;
			node = nullptr;
		}
		else if (node->left == nullptr)
		{
			treenode* temp = node;
			node = node->right;
			delete temp;
		}
		else if (node->right == nullptr)
		{
			treenode* temp = node;
			node = node->left;
			delete temp;
		}
		else
		{
			node->value = deletemin(node->right);
		}
		return true;
	}
	else
	{
		if (node->value > val) return removehelp(node->left, val);
		else if (node->value < val) return removehelp(node->right, val);
	}
}

void BST::clearall(treenode* node)
{
	if (node == nullptr) return;
	clearall(node->left);
	clearall(node->right);
	delete node;
}

void BST::print(treenode* node)
{
	if (node == nullptr) return;
	print(node->left);
	std::cout << node->value << " ";
	print(node->right);
}

int main(int argc, char const *argv[])
{
	BST mybst;
	mybst.insert(190);
	mybst.insert(200);
	mybst.insert(20);
	mybst.insert(22);
	mybst.insert(24);
	mybst.insert(201);
	mybst.insert(20);
	mybst.insert(11);
	mybst.remove(20);
	mybst.remove(22);
	mybst.remove(11);
	mybst.remove(190);
	mybst.remove(33);
	mybst.remove(24);
	mybst.printbyorder();
	std::cout << "BST nodecount:" << mybst.size() << std::endl;
	return 0;
}