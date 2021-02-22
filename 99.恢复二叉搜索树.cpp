/*
 * @lc app=leetcode.cn id=99 lang=cpp
 *
 * [99] 恢复二叉搜索树
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

class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode* mis1 = nullptr, *mis2 = nullptr, *prev = nullptr;
        inorder(root,mis1,mis2,prev);
        if(mis1 && mis2){
            int tmp = mis1->val;
            mis1->val = mis2->val;
            mis2->val = tmp;
        }
    }

    void inorder(TreeNode* root, TreeNode*& mis1, TreeNode*& mis2, TreeNode*& prev){
        if(!root){
            return;
        }
        //中序遍历
        if(root->left){
            inorder(root->left,mis1,mis2,prev);
        }

        // 二叉搜索树，中序遍历一定是有序的，否则就是出错的点
        if(prev && root->val < prev->val){
            //一次次序错误，说明相邻节点要被交换
            if(!mis1){
                mis1 = prev;
                mis2 = root;
            }else  //否则就是当前节点和之前出错节点
            {
                mis2 = root;
            }
        }
        prev = root;
        if(root->right){
            inorder(root->right,mis1,mis2,prev);
        }
    }
};
// @lc code=end

