class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.length();
        int n = t.length();

        if (n > m) {
            return "";
        }

        unordered_map<char, int> store;
        int l = 0;
        int r = 0;
        int countRequired = n;
        int minWindowSize = INT_MAX;
        int minWindowStart = 0;

        for (int i = 0; i < n; ++i) {
            store[t[i]]++;
        }

        while (r < m) {
            if (store[s[r]] > 0) {
                --countRequired;
            }
            --store[s[r]];

            while (l <= r && countRequired == 0) {
                if (minWindowSize > r - l + 1) {
                    minWindowSize = r - l + 1;
                    minWindowStart = l;
                }
                ++store[s[l]];
                if (store[s[l]] > 0) {
                    ++countRequired;
                }
                ++l;
            }
            ++r;
        }

        if(minWindowSize==INT_MAX) return "";

        return s.substr(minWindowStart,minWindowSize);
    }
};