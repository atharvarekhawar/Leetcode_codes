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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        queue<pair<TreeNode*,int>>q;
        int maxWidth = INT_MIN;

        q.push({root,0});

        while(!q.empty()){
            int size = q.size();
            int min_index = q.front().second;
            int first;
            int last;

            for(int i=0;i<size;++i){
                long long curr_index = q.front().second - min_index;
                TreeNode* temp = q.front().first;
                q.pop();

                if(i==0) first=curr_index;
                if(i==size-1) last=curr_index;

                if(temp->left){
                    q.push({temp->left,curr_index*2+1});
                }

                if(temp->right){
                    q.push({temp->right,curr_index*2+2});
                }
            }

            maxWidth = max(maxWidth,last-first+1);
        }

        return maxWidth;
    }
};