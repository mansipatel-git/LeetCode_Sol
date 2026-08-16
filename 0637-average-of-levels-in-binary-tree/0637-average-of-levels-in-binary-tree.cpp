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
    void bfs(TreeNode* root , vector<double>&a){
        if(!root) return ;
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            int sz = q.size();
            double sum = 0;
            for(int i = 0; i < sz ; i++){
                TreeNode* node = q.front();
                q.pop();
                sum += node->val;
                
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            double avg = sum/ sz;
            a.push_back(avg);
        }
    }
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double>a;
        bfs(root, a);
        return a;
    }
};