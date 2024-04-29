/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    bool solve(TreeNode* root,long long leftRange,long long rightRange){
        if(root==NULL){
            return true;
        }

        if(root->val<=leftRange || root->val>=rightRange){
            return false;
        }

        bool leftBST = solve(root->left,leftRange,root->val);
        bool rightBST = solve(root->right,root->val,rightRange);

        return leftBST && rightBST;
    }
    bool isValidBST(TreeNode* root) {
        long long int min = -1000000000000;
        long long int max = 1000000000000;
        return solve(root,min,max);
    }
};