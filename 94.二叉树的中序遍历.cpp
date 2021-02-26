/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
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

/* class Solution {
public:
    //递归最简单
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;
        inorder(root,ans);
        return ans;

    }
    void inorder(TreeNode* root, vector<int>& ans){
        if(!root) return;
        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);

    }
}; */


#include<stack>
#include<vector>
using namespace std;

class Solution {
public:
    //迭代法
    vector<int> inorderTraversal(TreeNode* root){
        vector<int> res;
        if(!root) return res;
        
        stack<TreeNode*> stk;

        while (root!= nullptr || !stk.empty())
        {   
            //root入栈，然后访问左子树
            while (root!=nullptr)
            {
                stk.push(root);
                root = root->left;
            }

            root = stk.top(); 
            stk.pop();
            //访问当前值
            res.push_back(root->val);
            root = root->right;
            
        }
        return res;
    }
};
// @lc code=end

