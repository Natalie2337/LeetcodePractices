// 通过！
// 原来我自己写的版本check也有77/85的通过率

#include <climits>

// Definition for a binary tree node.
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

    //bool isValid = true;

    // void check(TreeNode* node){
    //     // 这个版本会错了意，它的意思是所有右子节点都要满足比父节点大，所有左子节点都要满足比父节点小
    //     if(isValid && node!=nullptr){ //不要写while呀，我要递归呀
    //         TreeNode* left = node->left;
    //         TreeNode* right = node->right;
    //         // if(left == nullptr || right == nullptr){
    //         //     return;
    //         // }  这两个不能一起写，因为可能一边到头了，另外一边还没有到
            
    //         if(left != nullptr && left->val >= node->val){
    //             isValid = false;
    //             return; 
    //         }
    //         if(right != nullptr && right->val <= node->val){
    //             isValid = false;
    //             return;
    //         }

    //         check(left);
    //         check(right);
    //     }
    //     else{
    //         return;
    //     }
    // }


    // bool isValidBST(TreeNode* root) {
    //     if(root == nullptr){
    //         return true; // 一个空树（即没有节点的树）被认为是有效的二叉搜索树，因为它不违反任何规则
    //     }
    //     check(root);
    //     return isValid;
    // }


    // 为了解决这个问题，加一个含有上下界的helper
    bool helper(TreeNode * node, long long lower, long long upper){
        if (node == nullptr){
            return true;
        }

        TreeNode * left = node->left;
        TreeNode * right = node->right;
        if (left == nullptr || right == nullptr){
            return true;
        }
        // if (left->val > lower || right->val < upper){
        //     return false;
        // } 
        // 这里关注条件写错了，我们应该判断的是左子节点是否大于上界或者右子节点是否小于下界
        if (left->val >= upper || right->val <= lower){
            return false;
        }

        bool l = helper(left, LLONG_MIN, left->val);
        bool r = helper(right, right->val, LLONG_MAX);

        // 这样写是不好的
        // 递归我们应该关心的是该层内的问题，而不是去关注左右子节点是否满足条件！！！
        return l&r;
    }

    bool helper2(TreeNode * node, long long lower, long long upper){
        if (node == nullptr){
            return true;
        }
        
        // 只关心层内的事情
        if (node->val <= lower || node->val >= upper){
            return false;
        }

        TreeNode * left = node->left;
        TreeNode * right = node->right;


        // bool l = helper(left, LLONG_MIN, left->val);
        // bool r = helper(right, right->val, LLONG_MAX);
        
        // 这两种写法是有区别的，比如[5,4,6,null,null,3,7]例子，会出现右子树的左子树不满足比该根节点大的情况
        // 所以这些子树的上界和下界都会随时更新（每次l或者r都在更新上界或者下界）
        
        bool l = helper2(left, lower, node->val);
        bool r = helper2(right, node->val, upper);

        return l&r;
    }


    bool isValidBST(TreeNode* root) {
        return helper2(root, LLONG_MIN, LLONG_MAX);
    }
};