/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
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
#include<algorithm>
using namespace std;

// class Solution {
// public:
//     vector<int> postorderTraversal(TreeNode* root) {
//         vector<int> ans;
//         if(!root) return ans;
//         postorder(root,ans);
//         return ans;
        
//     }

//     void postorder(TreeNode* root, vector<int>& ans){
//         if(!root) return;

//         postorder(root->left,ans);
//         postorder(root->right,ans);
//         ans.push_back(root->val);
//     }
// };


// class Solution {
// public:
//     //三种遍历统一模板的迭代写法,最后还需要逆序不是一次完成后序遍历
//     vector<int> postorderTraversal(TreeNode* root) {
//         vector<int> res;
//         stack<TreeNode*> stk;
//         while (root!=nullptr || !stk.empty())
//         {   
//             while (root!=nullptr)
//             {      
//                 // 使用emplace，省去拷贝构造函数的创建
//                 res.emplace_back(root->val);
//                 stk.emplace(root);
//                 // res.push_back(root->val);
//                 // stk.push(root);
//                 root = root->right;
//             }

//             root = stk.top();
//             stk.pop();
//             root = root->left;
//         }
//         //和前序遍历相反，然后在逆序
//         reverse(res.begin(),res.end());
//         return res;
//     }
// };


class Solution {
public:
    // leetcode 版本，直接在loop中体现后序遍历
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> res;
        if (root == nullptr) {
            return res;
        }

        stack<TreeNode *> stk;
        TreeNode *prev = nullptr;
        while (root != nullptr || !stk.empty()) {
            while (root != nullptr) {
                stk.emplace(root);
                root = root->left;
            }
            root = stk.top();
            stk.pop();
            // prev 是上一个节点，标记有右节点是不是访问过，访问过就直接添加当前节点
            if (root->right == nullptr || root->right == prev) {
                res.emplace_back(root->val);
                prev = root;
                root = nullptr;
            } else {
                stk.emplace(root);
                root = root->right;
            }
        }
        return res;
    }
};

// @lc code=end

