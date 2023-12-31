class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int n = s.length();
        if (n <= 2) {
            return 0;
        }

        int count = -1;

        for (int i = 0; i < n - 3; i++) {
            char currChar = s[i];

            for (int j = i + 1; j < n; j++) {

                if (s[j] == currChar) {
                    count = max(count, j - i - 1);
                }
            }
        }

        return count;
    }
};