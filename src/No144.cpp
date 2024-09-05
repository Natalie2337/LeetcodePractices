// 通过！
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 前序遍历： 根节点 -> 左子树 -> 右子树
class Solution {
public:
    vector<int> results;

    void Traverse(TreeNode* node){
        if (node == nullptr) return; // 添加对空节点的检查
        results.push_back(node->val);
        Traverse(node->left);
        Traverse(node->right);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        Traverse(root);
        return results;
    }
};