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
    TreeNode* findNode(TreeNode* root, int key) {
        if (root == NULL) {
            return NULL;
        }

        if (root->val == key) {
            return root;
        }

        TreeNode* leftNode = findNode(root->left, key);
        TreeNode* rightNode = findNode(root->right, key);

        return leftNode != NULL ? leftNode : rightNode;
    }
    TreeNode* findMax(TreeNode* root){
        if(root==NULL){
            return NULL;
        }

        while(root->right){
            root=root->right;
        }

        return root;
    }
    TreeNode* solve(TreeNode* root, int key) {
        if (root == NULL) {
            return NULL;
        }

        if(root->val == key){
            if(root->left == NULL){
                TreeNode* rightNode = root->right;
                delete root;
                return rightNode;
            }
            if(root->right==NULL){
                TreeNode* leftNode = root->left;
                delete root;
                return leftNode;
            }

            TreeNode* rightBST = root->right;
            TreeNode* leftBST = root->left;
            TreeNode* maxLeft = findMax(root->left);
            maxLeft->right = rightBST;
            delete root;
            return leftBST;
        }

        if (root->val > key) {
            root->left = solve(root->left, key);
        } else {
            root->right = solve(root->right, key);
        }

        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL) {
            return NULL;
        }

        TreeNode* keyNode = findNode(root, key);

        if (keyNode == NULL)
            return root;

        return solve(root, key);
    }
};