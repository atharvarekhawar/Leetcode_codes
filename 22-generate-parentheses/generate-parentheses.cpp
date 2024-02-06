class Solution {
public:
    void solve(vector<string>& res, string curr, int open, int close) {
        if (open == 0 && close == 0) {
            res.push_back(curr);
            return;
        }

        if (open > 0) {
            curr.push_back('(');
            solve(res, curr, open - 1, close);
            curr.pop_back();
        }

        if (close > open) {
            curr.push_back(')');
            solve(res, curr, open, close - 1);
            curr.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string curr = "";
        int open = n;
        int close = n;
        solve(res, curr, open, close);
        return res;
    }
};