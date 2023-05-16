// C++ program for different tree traversals
#include <iostream>
using namespace std;

/* A binary tree node has data, pointer to left child
and a pointer to right child */
struct Node {
	int data;
	struct Node *left, *right;
	Node(int data)
	{
		this->data = data;
		left = right = NULL;
	}
};

/* Given a binary tree, print its nodes according to the
"bottom-up" postorder traversal. */
void printPostorder(struct Node* node)
{
	if (node == NULL)
		return;

	// first recur on left subtree
	printPostorder(node->left);

	// then recur on right subtree
	printPostorder(node->right);

	// now deal with the node
	cout << node->data << " ";
}

/* Given a binary tree, print its nodes in inorder*/
void printInorder(struct Node* node)
{
	if (node == NULL)
		return;

	/* first recur on left child */
	printInorder(node->left);

	/* then print the data of node */
	cout << node->data << " ";

	/* now recur on right child */
	printInorder(node->right);
}

/* Given a binary tree, print its nodes in preorder*/
void printPreorder(struct Node* node)
{
	if (node == NULL)
		return;

	/* first print data of node */
	cout << node->data << " ";

	/* then recur on left sutree */
	printPreorder(node->left);

	/* now recur on right subtree */
	printPreorder(node->right);
}



/* Driver program to test above functions*/
int main()
{
	struct Node *root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);

	cout << "\nPreorder traversal of binary tree is \n";
	printPreorder(root);

	cout << "\nInorder traversal of binary tree is \n";
	printInorder(root);

	cout << "\nPostorder traversal of binary tree is \n";
	printPostorder(root);

	return 0;
}


// C++ program to print left view of
// Binary Tree

#include<bits/stdc++.h>
using namespace std;

// A Binary Tree Node
struct Node
{
	int data;
	struct Node *left, *right;
};

// Utility function to create a new tree node
Node* newNode(int data)
{
	Node *temp = new Node;
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

// function to print left view of
// binary tree
void printLeftView(Node* root)
{
	vector<int> ans;
	if (!root)
		return;

	queue<Tree*> q;
	q.push(root);

	while (!q.empty())
	{	
		int n = q.size();
		for(int i = 1; i <= n; i++)
		{
			Tree* temp = q.front();
			q.pop();
			if (i == 1)
				ans.emplace_back (temp->val);
			if (temp->left != NULL)
				q.push(temp->left);
			if (temp->right != NULL)
				q.push(temp->right);
		}
	}
	return ans;
}	

// Driver code
int main()
{
	// Let's construct the tree as
	// shown in example

	Node* root = newNode(10);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(7);
	root->left->right = newNode(8);
	root->right->right = newNode(15);
	root->right->left = newNode(12);
	root->right->right->left = newNode(14);

	printLeftView(root);
}

// This code is contributed by
// Manne SreeCharan

int treePathsSumUtil(node *Tree, int ans) 
{ 
    if (root == NULL) return 0; 
    ans = (ans*10 + root->val); 
      if (root->left==NULL && root->right==NULL) 
    return ans; 
      return treePathsSumUtil(root->left, ans) + 
        treePathsSumUtil(root->right, ans); 
}