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
    unordered_map<int, vector<int>> graph;
    int amountOfTime(TreeNode* root, int start) {
        constructGraph(root);

        unordered_set<int> infected;

        queue<int> store;
        store.push(start);

        int time = -1;

        while (!store.empty()) {
            time++;
            for (int i = store.size(); i > 0; i--) {
                int currentNode = store.front();
                store.pop();
                infected.insert(currentNode);

                for (int adjacentNode : graph[currentNode]) {
                    if (!infected.count(adjacentNode)) {
                        store.push(adjacentNode);
                    }
                }
            }
        }

        return time;
    }

    void constructGraph(TreeNode* root) {
        if (!root) {
            return;
        }

        if (root->left) {
            graph[root->val].push_back(root->left->val);
            graph[root->left->val].push_back(root->val);
        }

        if (root->right) {
            graph[root->val].push_back(root->right->val);
            graph[root->right->val].push_back(root->val);
        }

        constructGraph(root->left);
        constructGraph(root->right);
    }
};