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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL)return {};
        vector<vector<int>>res;
        bool flag = true;
        queue<TreeNode*>q;

        q.push(root);

        while(!q.empty()){
            int size = q.size();
            vector<int>store(size);

            for(int i=0;i<size;++i){
                TreeNode* temp = q.front();
                q.pop();

                int index = flag ? i : size-i-1;
                store[index] = temp->val;

                if(temp->left!=NULL){
                    q.push(temp->left);
                }
                if(temp->right!=NULL){
                    q.push(temp->right);
                }        
            }

            flag=!flag;
            res.push_back(store);
        }
        return res;
    }
};