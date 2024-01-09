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
private:
    void solve(TreeNode* root,vector<int>&store) {
        if (root == NULL){
            return;
        }

        if(root->left==NULL && root->right==NULL){
            store.push_back(root->val);
        }

        solve(root->left,store);
        solve(root->right,store);
    }

public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        if (root1->left == NULL && root1->right == NULL &&
            root2->left == NULL && root2->right == NULL) {
            if (root1->val == root2->val) {
                return true;
            } else {
                return false;
            }
        }
        vector<int> store1;
        vector<int> store2;
        solve(root1,store1);
        solve(root2,store2);

        return (store1==store2);
    }
};