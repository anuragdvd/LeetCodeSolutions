// 938. Range Sum of BST :: https://leetcode.com/problems/range-sum-of-bst/

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
    int rangeSumBST(TreeNode* root, int L, int R) {
        // if root-> val is less than L then only the right subtree matters 
        // if root-> val is greather than R then only the left subtree matters 
        // else both subtree matters 
        
        if(!root)   return 0;
        if(root->val < L)
        {
            return rangeSumBST(root->right,L,R);
        }
        else if(root->val > R)
        {
            return rangeSumBST(root->left,L,R);
        }
        else{
            return rangeSumBST(root->left,L,R)+root->val+rangeSumBST(root->right,L,R);
        }
            
        
    }
};