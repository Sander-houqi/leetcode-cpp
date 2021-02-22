/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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


// class Solution {
// public:
//     //递归
//     bool isSymmetric(TreeNode* root) {
//         if(root==nullptr) return true;
        
//         return helper(root->left,root->right);
//     }

//     bool helper(TreeNode* node1, TreeNode* node2){
//         if(!node1 && !node2) return true;
//         //只有一个子树为空，不队称
//         if(!node1 || !node2) return false;
//         //不相等
//         if(node1->val != node2->val) return false;

//         return helper(node1->left,node2->right) && helper(node1->right,node2->left);

//     }
// };

#include<queue>
using namespace std;

//非递归
class Solution{
public:
    //使用队列
    bool isSymmetric(TreeNode* root){
        if(root==nullptr) return true;

        return helper(root->left,root->right);
    }

    bool helper(TreeNode* node1, TreeNode* node2){
        queue<TreeNode*> q;
        q.push(node1);
        q.push(node2);

        while (!q.empty())
        {
            node1 = q.front(); q.pop();
            node2 = q.front(); q.pop();
            // 都为空
            if(!node1 && !node2) continue;
            if(!node1 || !node2) return false;
            if(node1->val != node2->val) return false;

            q.push(node1->left); q.push(node2->right);
            q.push(node1->right); q.push(node2->left);

        }
        return true;
    }
};


// @lc code=end

