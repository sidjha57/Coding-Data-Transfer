#include<bits/stdc++.h>

using namespace std;

#include <bits/stdc++.h> 


template <typename T>
class TreeNode {
    public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

 void traverse(TreeNode<int> *node, int& k, int& sum, vector<int>& path, vector<vector<int>>& ans) {
     if (!node->left && !node->right) {
         if (sum == k) {
             ans.push_back(path);
         }
         return;
     }
     
     if (node->left) {
         sum += node->left->data;
         path.push_back(node->left->data);
         traverse(node->left, k, sum, path, ans);
         sum -= node->left->data;
         path.pop_back();
     }
     if (node->right) { 
         sum += node->right->data;
         path.push_back(node->right->data);
         traverse(node->right, k, sum, path, ans);
         sum -= node->right->data;
         path.pop_back();
     }
     return;
 }

vector<vector<int>> KSumPaths(TreeNode<int> *root, int k)
{
	vector<int> path;
    vector<vector<int>> ans;
    path.push_back(root->data);
    int sum = root->data;
    traverse(root,k,sum,path,ans);
    return ans;
}

int main () {
    TreeNode<int>* root = new TreeNode<int>(5);
    TreeNode<int>* left = new TreeNode<int>(6);
    root->left = left;
    TreeNode<int>* right = new TreeNode<int>(15);
    root->right = right;
    left = new TreeNode<int>(4);
    root->left->left = left;
    right = new TreeNode<int>(1);
    root->left->right = right;
    KSumPaths(root,15);
    // left = new TreeNode<int>(6);
}
