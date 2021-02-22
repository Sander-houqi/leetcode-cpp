/*
 * @lc app=leetcode.cn id=1110 lang=cpp
 *
 * [1110] 删点成林
 */

// @lc code=start
// struct TreeNode {
//      int val;
//      TreeNode *left;
//      TreeNode *right;
//      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// };

#include<vector>
#include<unordered_set>
#include<iostream>
using namespace std;

class Solution {
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> res;
        unordered_set<int> dict(to_delete.begin(),to_delete.end());
        root = helper(root, dict, res);
        if(root){
            res.push_back(root);
        }
        return res;
    }

    TreeNode* helper(TreeNode* root, unordered_set<int>& dict, vector<TreeNode*>& res){
        if(!root){
            return root;
        }

        root->left = helper(root->left,dict,res);
        root->right = helper(root->right,dict,res);
        // 如果存在就加入到节点中，后续输出的结果是leetcode自行组装的
        if(dict.count(root->val)){
            if(root->left){
                res.push_back(root->left);
            }
            if(root->right){
                res.push_back(root->right);
            }
            root = nullptr;
        }

        return root;
    }
};

// int main(){
//     vector<int> tree{1,2,3,4,5,6,7};
//     vector<int> del{3,5};

// }

// @lc code=end

