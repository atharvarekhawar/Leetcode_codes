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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>res;
        map<int,map<int,multiset<int>>>store;
        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push({root,{0,0}});

        while(!q.empty()){
            auto data = q.front();
            q.pop();

            TreeNode* temp = data.first;
            int vertical = data.second.first;
            int level = data.second.second;

            store[vertical][level].insert(temp->val);

            if(temp->left!=NULL){
                q.push({temp->left,{vertical-1,level+1}});
            }

            if(temp->right!=NULL){
                q.push({temp->right,{vertical+1,level+1}});
            }
        }

        for(auto p:store){
            vector<int>vertical;
            for(auto q:p.second){
                vertical.insert(vertical.end(),q.second.begin(),q.second.end());
            }
            res.push_back(vertical);
        }

        return res;
    }
};