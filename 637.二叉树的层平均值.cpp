/*
 * @lc app=leetcode.cn id=637 lang=cpp
 *
 * [637] 二叉树的层平均值
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

#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    //广度优先搜素，二叉树层级遍历
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        if(!root){
            return ans;
        }

        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty())
        {
            int count = q.size();
            double sum = 0;
            for(int i=0; i<count; ++i){
                TreeNode* node = q.front();
                q.pop();
                sum += node->val;

                if(node->left){
                    q.push(node->left);
                }

                if(node->right){
                    q.push(node->right);
                }
            }

            ans.push_back(sum/count);
        }
        return ans;
    }
};
// @lc code=end

