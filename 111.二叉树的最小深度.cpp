/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
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
    int minDepth(TreeNode* root) {
        if(root==nullptr) return 0;

        //左子树深度
        int left = minDepth(root->left);
        //右子树深度
        int right = minDepth(root->right);
        //如果左子树或者右子树为空,是包含了两个都为空的情况，当前子树的最小深度就是子树的深度+1
        if(left == 0 || right == 0) return left+right+1;
        // 如果两个子树都存在,取最小的深度+1
        return min(left,right) + 1;
    }
};
// @lc code=end

