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
    TreeNode* findNode(TreeNode* root,int start){
        if(root==NULL){
            return NULL;
        }

        if(root->val == start){
            return root;
        }

        TreeNode* left = findNode(root->left,start);
        TreeNode* right = findNode(root->right,start);

        return left==NULL ? right : left;

        
    }
    int amountOfTime(TreeNode* root, int start) {
        map<TreeNode*,TreeNode*>parent;
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();

            for(int i=0;i<size;++i){
                TreeNode* temp = q.front();
                q.pop();

                if(temp->left){
                    q.push(temp->left);
                    parent[temp->left] = temp;
                }

                if(temp->right){
                    q.push(temp->right);
                    parent[temp->right] = temp;
                }
            }
        }

        TreeNode* startNode = findNode(root,start);

        int totalTime = -1;
        map<TreeNode*,bool>visited;

        q.push(startNode);
        visited[startNode] = true;

        while(!q.empty()){
            int size = q.size();
            totalTime++;

            for(int i=0;i<size;++i){
                TreeNode* temp = q.front();
                q.pop();

                if(temp->left && !visited[temp->left]){
                    q.push(temp->left);
                    visited[temp->left] = true;
                }

                if(temp->right && !visited[temp->right]){
                    q.push(temp->right);
                    visited[temp->right] = true;
                }

                if(parent[temp] && !visited[parent[temp]]){
                    q.push(parent[temp]);
                    visited[parent[temp]] = true;
                }
            }
        }

        return totalTime;

    }
};