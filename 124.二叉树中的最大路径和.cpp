/*
 * @lc app=leetcode.cn id=124 lang=cpp
 *
 * [124] 二叉树中的最大路径和
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

#include<limits.h>
#include<algorithm>
using namespace std;

class Solution {
private:
    int maxSum = INT_MIN;

public:
    int maxPathSum(TreeNode* root) {
        if(!root) return 0;
        maxGain(root);
        return maxSum;
    }

    int maxGain(TreeNode* node){
        if(node== nullptr) return 0;

        // 递归计算左右子节点，只有大于0，才选取
        int leftGain = max(maxGain(node->left), 0);
        int rightGain = max(maxGain(node->right), 0);

        //当前最大路经和
        int tmp = node->val + leftGain + rightGain;

        //更新全局最大和
        maxSum = max(maxSum,tmp);

        //当前节点的最大贡献值
        return node->val + max(leftGain,rightGain);
    }
};
// @lc code=end

