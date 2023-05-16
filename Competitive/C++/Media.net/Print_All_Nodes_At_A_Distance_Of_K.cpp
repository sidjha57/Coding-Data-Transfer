#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

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

************************************************************/
void kDistanceUtil(TreeNode<int> *node, int k, vector<int>& ans, int dis, unordered_map<int,bool>& vis) {
    if (!node) return;
    if (vis.find(node->data) != vis.end()) return;
    
    if (dis == k) {
        ans.push_back(node->data);
    }
    
    if (node->left) {
       kDistanceUtil(node->left,k,ans,dis+1,vis);
    } 
    
    if (node->right) {
      kDistanceUtil(node->right,k,ans,dis+1,vis);
    }
}
bool traverse (TreeNode<int>* node,int target,vector<TreeNode<int> *>& path) {
    if (!node) return 0;
    
    path.push_back(node);
    
    if (node->data == target) return 1;
    
    
    if (traverse(node->left,target,path) || traverse(node->right,target,path))
        return 1;
    
    path.pop_back();
    return 0;
}
vector<int> kDistance(TreeNode<int> *root, int target, int k)
{
    
    unordered_map<int,bool> vis;
    vector<int> ans;
    vector<TreeNode<int> *> path;
    traverse(root,target,path);

    for (int i=path.size()-1; i>= 0 && k >= 0; i--, k--) {  
        if (k == 0) ans.push_back(path[i]->data);
        else
            kDistanceUtil(path[i],k,ans,0,vis);
        vis[path[i]->data] = 1;
    }
    return ans;
}