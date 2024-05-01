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
    bool solve(TreeNode* root,int k,map<int,bool>&m){
        if(root==NULL){
            return false;
        }

        if(m.find(k - root->val)!=m.end()){
            return true;
        }

        m[root->val] = true;

        bool left = solve(root->left,k,m);
        bool right = solve(root->right,k,m);

        return left || right;
    }
    bool findTarget(TreeNode* root, int k) {
        map<int,bool>m;
        return solve(root,k,m);
    }
};