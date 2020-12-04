// 111. Minimum Depth of Binary Tree :: https://leetcode.com/problems/minimum-depth-of-binary-tree/

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
    int minDepth(TreeNode* root) {
        queue<TreeNode*> q;
        if(!root)   return 0;
        q.push(root);
        int d=0;
        while(!q.empty())
        {
            d++;
            int sz=q.size();
            for(int i=0;i<sz;i++)
            {
                auto node=q.front();
                q.pop();
                if(node->left)  q.push(node->left);
                if(node->right) q.push(node->right);
                if(!node->left&&!node->right)   return d;
            }
        }
        return d;
    }
};