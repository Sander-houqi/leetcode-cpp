/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层序遍历
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
#include<deque>
#include<queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;

        queue<TreeNode*> q;
        q.push(root);
        bool flag = true;

        while (!q.empty()){   
            // 双端队列存储每层结果
            deque<int> tmp;
            int level_size = q.size();

            for(int i = 0; i < level_size; ++i){

                auto node = q.front();
                q.pop();

                if(flag){
                    tmp.push_back(node->val);
                }else
                {
                    tmp.push_front(node->val);
                }
                
                if(node->left){
                    q.push(node->left);
                }

                if(node->right)
                {
                    q.push(node->right);
                }
            }
            
            res.push_back(vector<int>{tmp.begin(),tmp.end()});
            flag = !flag;
        }
        
        return res;
    }
};
// @lc code=end

