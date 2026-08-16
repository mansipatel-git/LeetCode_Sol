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
    vector<vector<int>>ans;
    void bfs(TreeNode* root){
        if(!root) return ;
        queue<TreeNode*>q;
        q.push(root);
        bool l2r = true;

        while(!q.empty()){
            int sz = q.size();
            vector<int>res(sz);
            for(int i = 0; i < sz ; i++){
                TreeNode* node = q.front();
                q.pop();
                if(l2r){
                    res[i] = node->val;
                }else{
                    res[sz - i -1] = node->val;
                }
                
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            ans.push_back(res);
            l2r = !l2r;
        }
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        bfs(root);
        return ans;
    }
};