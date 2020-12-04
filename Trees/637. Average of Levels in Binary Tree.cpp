// 637. Average of Levels in Binary Tree :: https://leetcode.com/problems/average-of-levels-in-binary-tree


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
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        
        queue<TreeNode*> q;
        if(!root)   return ans;
        int lvl=-1;
        q.push(root);
        while(!q.empty())
        {
            lvl++;
            ans.push_back(0.00);
            int sz=q.size();
            for(int i=0;i<sz;i++)
            {
                auto node=q.front();
                q.pop();
                ans[lvl]=(ans[lvl]+node->val);
                if(node->left)  q.push(node->left);
                if(node->right) q.push(node->right);
            }
            ans[lvl]=ans[lvl]/sz;
        }
        return ans;
        
    }
};