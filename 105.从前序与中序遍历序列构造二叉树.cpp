/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
#include<unordered_map>
#include<vector>
using namespace std;

class Solution {
    //用于中序遍历快速定位根节点，key是节点的值，value是位置
    unordered_map<int,int> hash;
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty()) return nullptr;

        for(int i=0; i< preorder.size(); ++i){
            hash[inorder[i]] = i;
        }
        int n = preorder.size()-1;
        return mybuildTree(preorder,inorder,0,n,0,n);
 
    }

    TreeNode* mybuildTree(vector<int>& preorder, vector<int>& inorder, int pre_l, int pre_r, int in_l, int in_r){
        if(pre_l>pre_r){
            return nullptr;
        }
        // 前序数组的第一个就是根节点
        int pre_root = pre_l;
        // 从hash中获得中序的根节点所在位置
        int in_root = hash[preorder[pre_root]];
        
        //建立根节点
        TreeNode* root = new TreeNode(preorder[pre_root]);
        //左子节点的数目
        int size_l = in_root - in_l;
        //前序遍历中的左子树和中序遍历的左子树对应
        root->left = mybuildTree(preorder,inorder, pre_l+1, pre_l+size_l, in_l, in_root-1);
        //前序遍历中的右子树和中序遍历的右子树对应
        root->right = mybuildTree(preorder,inorder, pre_l+1+size_l ,pre_r, in_root+1, in_r);
        return root;
    }
};
// @lc code=end

