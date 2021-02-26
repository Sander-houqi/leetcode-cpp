/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
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
#include<stack>
using namespace std;

// class Solution {
// public:
//     //递归
//     vector<int> preorderTraversal(TreeNode* root) {
//         vector<int> res;
//         if(root==nullptr) return res;
//         preorder(root,res);
//         return res;
//     }

//     void preorder(TreeNode* root, vector<int>& res){
//         if(root==nullptr) return;

//         res.push_back(root->val);
//         preorder(root->left,res);
//         preorder(root->right,res);
//     }
// };

// class Solution {
// public:
//     //迭代法，使用栈
//     vector<int> preorderTraversal(TreeNode* root) {
//         vector<int> res;
//         if(!root) return res;

//         stack<TreeNode*> s;
//         s.push(root);
//         while (!s.empty())
//         {
//             TreeNode* node = s.top();
//             s.pop();
//             res.push_back(node->val);
//             //一定是先右节点，再左节点，因为是栈，先进后出。
//             if(node->right){
//                 s.push(node->right);
//             }
//             if(node->left){
//                 s.push(node->left);
//             }
//         }
//         return res;
//     }
// };


class Solution {
public:
    //三种遍历统一模板的迭代写法
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stk;
        while (root!=nullptr || !stk.empty())
        {   
            while (root!=nullptr)
            {      
                // 使用emplace，省去拷贝构造函数的创建
                res.emplace_back(root->val);
                stk.emplace(root);
                // res.push_back(root->val);
                // stk.push(root);
                root = root->left;
            }

            root = stk.top();
            stk.pop();
            root = root->right;
        }
        return res;
    }
};
// @lc code=end

