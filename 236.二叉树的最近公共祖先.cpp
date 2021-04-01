/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
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
    //时间和空间复杂度都为O(n)
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //当前节点为空或者遍历到p或者q，返回当前节点
        if(!root || root == p || root == q) return root;

        //递归遍历左右子树
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        //如果左右子树查到p，q节点都不为空，则表明p,q分别在左右子树中，当前节点就为最近的公共祖先
        if(left && right) return root;

        // 如果其中一个节点不为空，则返回不空的节点，说明另一个节点是在当前节点的左子树或者右子树中。
        return left ? left : right;

    }
};
// @lc code=end

