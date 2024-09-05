#include<iostream>
#include<vector>
#include<queue>
using namespace std;
//Definition for a binary tree node.
struct TreeNode {
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode() : val(0), left(nullptr), right(nullptr) {}
   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    queue<TreeNode*> nodes;
    vector<vector<int>> rst;

    void searchHelper(TreeNode * root){
        nodes.push(root);
        while(!nodes.empty()){
            TreeNode* node = nodes.front();
            int val = node->val;
            nodes.pop();
            nodes.push(node->left);
            nodes.push(node->right);
        }
    }


    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> rst;
        queue<TreeNode*> nodes;
        nodes.push(root);

        while(!nodes.empty()){

        }


    }
};