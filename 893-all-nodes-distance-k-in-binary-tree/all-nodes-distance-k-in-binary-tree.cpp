/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> res;
        map<TreeNode*, TreeNode*> parent;
        queue<TreeNode*> q;
        map<TreeNode*, bool> visited;

        q.push(root);

        while (!q.empty()) {
            int size = q.size();

            for (int i = 0; i < size; ++i) {
                TreeNode* temp = q.front();
                q.pop();

                if (temp->left) {
                    q.push(temp->left);
                    parent[temp->left] = temp;
                }

                if (temp->right) {
                    q.push(temp->right);
                    parent[temp->right] = temp;
                }
            }
        }

        int dist = 0;
        q.push(target);
        visited[target] = true;

        while (!q.empty()) {
            int size = q.size();
            if (dist++ == k)
                break;

            for (int i = 0; i < size; ++i) {
                TreeNode* temp = q.front();
                q.pop();

                if (temp->left && !visited[temp->left]) {
                    visited[temp->left] = true;
                    q.push(temp->left);
                }
                if (temp->right && !visited[temp->right]) {
                    visited[temp->right] = true;
                    q.push(temp->right);
                }
                if (parent[temp] && !visited[parent[temp]]) {
                    visited[parent[temp]] = true;
                    q.push(parent[temp]);
                }
            }
        }

        while (!q.empty()) {
            res.push_back(q.front()->val);
            q.pop();
        }

        return res;
    }
};