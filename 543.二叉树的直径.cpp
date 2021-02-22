/*
 * @lc app=leetcode.cn id=543 lang=cpp
 *
 * [543] 二叉树的直径
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {

public:
    // 直径，其实还是求左子树和右子树的最大深度求和
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        helper(root,diameter);
        return diameter;
    }

    int helper(TreeNode* root, int& diameter){
        if(root == nullptr) return 0;

        int left = helper(root->left,diameter) , right = helper(root->right,diameter);
        diameter = max(left+right, diameter);
        return max(left,right) +1;
    }
};
// @lc code=end

