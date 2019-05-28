// C++ implementation to find leaf
// count of a given Binary tree
#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

/* A binary tree node has data,
pointer to left child and
a pointer to right child */
struct node
{
	int data;
	struct node *left;
	struct node *right;
};

bool contains(list<struct node *> list, struct node *node)
{
	return (find(list.begin(), list.end(), node) != list.end());
}

void removeLeafs(struct node *node)
{
	if (node != NULL)
	{
		list<struct node *> allNodes;
		list<struct node *> stack;
		allNodes.push_front(node);
		stack.push_front(node);

		while (!stack.empty())
		{
			if (node->left != NULL && !contains(allNodes, node->left))
			{
				allNodes.push_front(node->left);
				stack.push_front(node->left);

				if (node->left->left == NULL && node->left->right == NULL)
					node->left = NULL;
				else
					node = node->left;
			}
			else if (node->right != NULL && (!contains(allNodes, node->right)))
			{
				allNodes.push_front(node->right);
				stack.push_front(node->right);
				if (node->right->left == NULL && node->right->right == NULL)
					node->right = NULL;
				else
					node = node->right;
			}
			else
			{
				stack.pop_front();
				if (!stack.empty())
					node = stack.front();
			}
		}
	}
}

int getHeight(struct node *node)
{
	int h = 0;
	int c = 0;

	if (node != NULL)
	{
		list<struct node *> allNodes;
		list<struct node *> stack;
		allNodes.push_front(node);
		stack.push_front(node);
		//int count = queue.size();

		while (!stack.empty())
		{
			if (node->left != NULL && !contains(allNodes, node->left))
			{
				allNodes.push_front(node->left);
				stack.push_front(node->left);
				node = node->left;
				++h;
			}
			else if (node->right != NULL && (!contains(allNodes, node->right)))
			{
				allNodes.push_front(node->right);
				stack.push_front(node->right);
				node = node->right;
			}
			else
			{
				if (h > c)
					c = h;
				--h;
				stack.pop_front();
				if (!stack.empty())
					node = stack.front();
			}
		}
	}
	return c;
}

int getRightChildren(struct node *node)
{
	int r = 0;

	if (node != NULL)
	{
		list<struct node *> allNodes;
		list<struct node *> stack;
		allNodes.push_front(node);
		stack.push_front(node);

		while (!stack.empty())
		{
			if (node->left != NULL && !contains(allNodes, node->left))
			{
				allNodes.push_front(node->left);
				stack.push_front(node->left);
				node = node->left;
			}
			else if (node->right != NULL && (!contains(allNodes, node->right)))
			{
				++r;
				allNodes.push_front(node->right);
				stack.push_front(node->right);
				node = node->right;
			}
			else
			{
				stack.pop_front();
				if (!stack.empty())
					node = stack.front();
			}
		}
	}

	return r;
}

int getLeafCount(struct node *node)
{
	int leaf = 0;

	if (node != NULL)
	{
		list<struct node *> allNodes;
		list<struct node *> stack;
		allNodes.push_front(node);
		stack.push_front(node);

		while (!stack.empty())
		{
			if (node->left != NULL && !contains(allNodes, node->left))
			{
				allNodes.push_front(node->left);
				stack.push_front(node->left);
				node = node->left;
				if (node->left == NULL && node->right == NULL)
					++leaf;
			}
			else if (node->right != NULL && (!contains(allNodes, node->right)))
			{
				allNodes.push_front(node->right);
				stack.push_front(node->right);
				node = node->right;
				if (node->left == NULL && node->right == NULL)
					++leaf;
			}
			else
			{
				stack.pop_front();
				if (!stack.empty())
					node = stack.front();
			}
		}
	}
	return leaf;
}

int getNodeCount(struct node *node)
{
	if (node != NULL)
	{
		list<struct node *> allNodes;
		list<struct node *> stack;
		allNodes.push_front(node);
		stack.push_front(node);

		while (!stack.empty())
		{
			if (node->left != NULL && !contains(allNodes, node->left))
			{
				allNodes.push_front(node->left);
				stack.push_front(node->left);
				node = node->left;
			}
			else if (node->right != NULL && (!contains(allNodes, node->right)))
			{
				allNodes.push_front(node->right);
				stack.push_front(node->right);
				node = node->right;
			}
			else
			{
				stack.pop_front();
				if (!stack.empty())
					node = stack.front();
			}
		}
		return allNodes.size();
	}
	return 0;
}

struct node *newNode(int data)
{
	struct node *node = (struct node *)
			malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return (node);
}

int main()
{
	struct node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->left->left->left = newNode(6);

	cout << "Leaf count of the tree is : " << getLeafCount(root) << endl;
	cout << "Node count of the tree is : " << getNodeCount(root) << endl;
	cout << "The count of the right nodes is : " << getRightChildren(root) << endl;
	cout << "The height of the tree is : " << getHeight(root) << endl;

	removeLeafs(root);
	cout << "After removing the leaves, remaining node count of the tree is : " << getNodeCount(root) << endl;

	return 0;
}
