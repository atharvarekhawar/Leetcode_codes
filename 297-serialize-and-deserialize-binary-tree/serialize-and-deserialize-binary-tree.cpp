/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
     string convert(TreeNode* node) {
        string hashed = "";
        queue<TreeNode*> Q;
        Q.push(node);
        while(!Q.empty()) {
            TreeNode* u = Q.front();
            Q.pop();
            if(hashed.size()!=0) {
                hashed += ",";
            }
            if(u==nullptr) {
                hashed += "null";
                continue;
            } else {
                hashed += to_string(u->val);
            }
            Q.push(u->left);
            Q.push(u->right);
        }
        return hashed;
    }

    vector<string> split(string str, char del){
        // declaring temp string to store the curr "word" upto del
        string temp = "";
        cout<<endl;
        vector<string> splittedValues;
        for(int i=0; i<(int)str.size(); i++){
            // If cur char is not del, then append it to the cur "word", otherwise
            // you have completed the word, print it, and start a new word.
            if(str[i] != del) {
                temp += str[i];
            } else {
                splittedValues.push_back(temp);
                temp = "";
            }
        }
        splittedValues.push_back(temp);
        return splittedValues;
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        return convert(root);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> splits = split(data, ',');
        int next = 1;
        unordered_map<int, TreeNode*> M;
        TreeNode* head = nullptr;
        for(int i=0;i<splits.size();i++) {
            TreeNode* cr;
            if(splits[i]=="null") {
                //next += 1;
                continue;
            }
            if(M[i]) {
                cr = M[i];
            } else {
                cr = new TreeNode();
                M[i] = cr;
                if(head==nullptr) {
                    head = cr;
                }
            }
            cr->val = stoi(splits[i]);
            if((next<splits.size()) && splits[next]!="null") {
                TreeNode* left = nullptr;
                if(M[next]) {
                    cr->left = M[next];
                } else {
                    left = new TreeNode();
                    M[next] = left;
                    cr->left = left;
                }
                left -> val = stoi(splits[next]);
            }
            if((next+1<splits.size()) && splits[next+1]!="null") {
                TreeNode* right = nullptr;
                if(M[next+1]) {
                    cr->right = M[next];
                } else {
                    right = new TreeNode();
                    M[next+1] = right;
                    cr->right = right;
                }
                right -> val = stoi(splits[next+1]);
            }
            next += 2;
            
        }
        return head;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));