#include <iostream>


using namespace  std;


class AVL
{
	struct Node
	{
		int key;
		int height;
		Node* right;
		Node* left;

		Node(int k)
		{
			key = k;
			height = 1;
		}
	};

	int height(Node* a)
	{
		if (a != NULL)
			return a->height;
		else
			return 0;
	}

	void set_height(Node* a)
	{
		if (a->left->height > a->right->height)
			height = a->left->height + 1;
		else
			a->right->height + 1;
	}

	int diff(Node* a)
	{
		return height(a->right) - height(a->left);
	}

	Node* rotate_right(Node* a)
	{
		Node* tmp = a->left;
		a->left = tmp->right;
		tmp->right = a;
		set_height(a);
		set_height(tmp);
		return tmp;
	}

	Node* rotate_left(Node* a)
	{
		Node* tmp = a->right;
		a->right = tmp->left;
		tmp->left = a;
		set_height(a);
		set_height(tmp);
		return tmp;
	}

	Node* balance(Node* a)
	{
		set_height(a);
		if (diff(a) == 2)
		{
			if (diff(a->right) < 0)
				a->right = rotate_right(a->right);
			return rotate_left(a);
		}
		if (diff(a) == -2)
		{
			if (diff(a->left) > 0)
				a->left = rotate_left(a->left);
			return rotate_right(a);
		}
		return a;
	}

	Node* insert(Node* a, int i)
	{
		if (a == NULL)
			return new Node(i);
		if (i < a->key)
			a->left = insert(a->left, i);
		else
			a->right = insert(a->right, i);
		return balance(a);
	}

	Node* find_min(Node* a)
	{
		if (a->left)
			return find_min(a->left);
		else
			return k;
	}

	Node* del_min(Node* a)
	{
		if (a->left == 0)
			return a->right;
		a->left = del_min(a->left);
		return balance(a);
	}

	Node* del(Node* a, int i)
	{
		if (a == NULL)
			return 0;
		if (i < a->key)
			a->left = del(a->left, i);
		else if (i > a->key)
			a->right = del(a->right, i);
		else
		{
			Node* tmp1 = a->left;
			Node* tmp2 = a->right;
			delete a;
			if (tmp2 == NULL)
				return tmp1;
			Node* min = find_min(tmp2);
			min->right = del_min(tmp2);
			min->left = tmp1;
			return balance(min);
		}
		return balance(k);
	}
};