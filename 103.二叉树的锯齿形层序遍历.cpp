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
        // flag 表示是否逆向遍历
        bool flag = true;

        while (!q.empty()){   
            // 双端队列存储每层结果
            deque<int> tmp;
            int level_size = q.size();

            for(int i = 0; i < level_size; ++i){

                auto node = q.front();
                q.pop();

                if(flag){
                    //添加到对列尾部
                    tmp.push_back(node->val);
                }else
                {   //添加到队列头部
                    tmp.push_front(node->val);
                }
                // 左右节点添加到队列中
                if(node->left){
                    q.push(node->left);
                }

                if(node->right)
                {
                    q.push(node->right);
                }
            }
            
            // 队列转vector
            res.push_back(vector<int>{tmp.begin(),tmp.end()});
            flag = !flag;
        }
        
        return res;
    }
};
// @lc code=end

