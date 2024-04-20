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
    void solve(TreeNode* root, string path, vector<string>& res) {
        if (root == NULL) {
            return;
        }

        path += to_string(root->val);

        if (root->left == NULL && root->right == NULL) {
            res.push_back(path);
            return;
        } else {
            solve(root->left, path+"->", res);

            solve(root->right, path+"->", res);
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        solve(root, "", res);
        return res;
    }
};