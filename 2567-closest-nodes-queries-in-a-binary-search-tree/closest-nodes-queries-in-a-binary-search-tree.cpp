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
    vector<int> arr;
    void inorder(TreeNode* root) {
        if(!root) 
            return;
        inorder(root->left);
        arr.push_back(root->val);
        inorder(root->right);
    }
    int lower(int val) {
        int i = 0, j = arr.size()-1, ans = -1;
        while(i <= j) {
            int m = i + ((j-i) >> 1);
            if(arr[m] <= val) {
                ans = m;
                i = m+1;
            } else {
                
                j = m-1;
            }
        }
        return ans;
    }
    int upper(int val) {
        int i = 0, j = arr.size()-1, ans = -1;
        while(i <= j) {
            int m = i + ((j-i) >> 1);
            if(arr[m] >= val) {
                ans = m;
                j = m-1;
            } else {
                i = m+1;
            }
        }
        return ans;
    }
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        inorder(root);
        vector<vector<int>> ans;
        for(int &qry : queries) {
            int x = lower(qry), y = upper(qry);
            if(x != -1)
                x = arr[x];
            if(y != -1)
                y = arr[y];
            ans.push_back({x, y});
        }
        return ans;
    }
};