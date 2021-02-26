/*
 * @lc app=leetcode.cn id=226 lang=cpp
 *
 * [226] 翻转二叉树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include<vector>
using namespace std;

class Solution {
public:
        //先翻转子树后递归内部
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return nullptr;

        //或者创建临时变量交换
        swap(root->left,root->right);
        // TreeNode* tmp = root->left;
        // root->left = root->right;
        // root->right = tmp;

        invertTree(root->left);
        invertTree(root->right);
        return root;
    }


    // 先递归后翻转
    // TreeNode* invertTree(TreeNode* root) {
    //     if(!root) return nullptr;

    //     invertTree(root->left);
    //     invertTree(root->right);
    //     swap(root->left,root->right);
    //     return root;
    // }
};
// @lc code=end

