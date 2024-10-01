class Solution {
public:
    unordered_map<string, bool> store;
    bool solve(string s1, string s2) {
        int n = s1.size();

        if (s1.length() != s2.length()) {
            return false;
        }

        if (s1 == s2)
            return true;

        if (n == 1) {
            return false;
        }

        string key = s1 + " " + s2;

        if (store.find(key) != store.end()) {
            return store[key];
        }

        for (int i = 1; i < n; i++) {
            bool swapping = solve(s1.substr(0, i), s2.substr(n - i)) &&
                            solve(s1.substr(i), s2.substr(0, n - i));

            if (swapping)
                return true;

            bool notSwapping = solve(s1.substr(0, i), s2.substr(0, i)) &&
                               solve(s1.substr(i), s2.substr(i));

            if (notSwapping)
                return true;
        }

        store[key] = false;
        return false;
    }
    bool isScramble(string s1, string s2) {
        if (s1 == s2) {
            return true;
        }

        if (s1.length() != s2.length()) {
            return false;
        }

        return solve(s1, s2);
    }
};