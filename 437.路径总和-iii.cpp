/*
 * @lc app=leetcode.cn id=437 lang=cpp
 *
 * [437] 路径总和 III
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
/* class Solution {
public:
    //O(n^2)的思路，但是好理解
    //以每个节点为根节点，算和为sum的路径有多少条
    int pathSum(TreeNode* root, int sum) {
        if(root== nullptr){
            return 0;
        }
        return helper(root,sum) + pathSum(root->left,sum) + pathSum(root->right,sum);
    }

    //用来计算连续节点的路径
    int helper(TreeNode* root, int sum){
        if(root==nullptr){
            return 0;
        }

        sum -= root->val;
        // 如果等于0，相当于找到了，否则搜索左右节点
        return (sum == 0 ? 1 : 0) + helper(root->left, sum) + helper(root->right, sum);
    }
}; */

#include<unordered_map>
using namespace std;

class Solution{
    //key表示前缀和，value表示出现次数
    unordered_map<int,int> hash;

public:
    // 利用前缀和优化时间复杂度，最终只遍历一遍，时间复杂度为O(n)
    int pathSum(TreeNode* root, int sum){
        //前缀和为0有一条路径
        hash[0] = 1;
        return helper(root,0,sum);

    }

    int helper(TreeNode* root, int currsum, int sum){
        if(root==nullptr) return 0;

        int res = 0;
        // 当前路径和
        currsum += root->val;
        //如果两个数的前缀总和是相同的，那么这些节点之间的元素总和为零。进一步扩展相同的想法，如果前缀总和currSum，在节点A和节点B处相差target，则位于节点A和节点B之间的元素之和是target。
        res += hash[currsum - sum];
        // 更新当前节点前缀和的个数;
        hash[currsum]++;
        //dfs遍历子节点
        res += helper(root->left,currsum,sum);
        res += helper(root->right,currsum,sum);
        //回溯
        hash[currsum]--;

        return res;
    }
};
// @lc code=end

