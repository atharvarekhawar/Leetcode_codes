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
    int maxDiff = 0;
    int maxAncestorDiff(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        int minVal = root->val;
        int maxVal = root->val;

        solve(root, minVal, maxVal);

        return maxDiff;
    }

    void solve(TreeNode* root, int minVal, int maxVal) {
        if (root == NULL) {
            return;
        }

        maxDiff = max(maxDiff, max(abs(minVal - root->val), abs(maxVal - root->val)));
        minVal = min(minVal, root->val);
        maxVal = max(maxVal, root->val);

        solve(root->left, minVal, maxVal);
        solve(root->right, minVal, maxVal);
    }
};