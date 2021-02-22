/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
 */

// @lc code=start

// struct TreeNode
// {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0),left(nullptr),right(nullptr) {}
//     TreeNode(int x) : val(x) ,left(nullptr) , right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

#include<cmath>
using namespace std;

class Solution {
public:
    //自底向上 时间复杂度O(n),n是二叉树的节点数
    bool isBalanced(TreeNode* root) {
        return helper(root)!=-1;
    }

    int helper(TreeNode* root){
        if(root==nullptr){
            return 0 ;
        }

        int left = helper(root->left) , right = helper(root->right);
        if(left ==-1 || right == -1 || abs(left-right)>1 ){
            return -1;
        }else
        {
            return max(left,right) +1;
        }

    }
};
// @lc code=end

