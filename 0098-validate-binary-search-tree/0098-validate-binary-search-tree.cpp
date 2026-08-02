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
    bool helper(TreeNode* root , long l , long r){
        if(!root) return true;
        if(root->val <= l || root->val >= r) return false;

        return helper(root->right , root->val , r) && helper(root->left , l ,root->val);
    }
    bool isValidBST(TreeNode* root) {
        return helper(root, LONG_MIN , LONG_MAX);
    }
};