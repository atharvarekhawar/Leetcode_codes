class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        vector<int> res;

        for (int i = 0; i < m; ++i) {
            stack<int> st;
            // st.push(-1);
            for (int j = n - 1; j >= 0; --j) {
                if (nums1[i] == nums2[j]) {
                    while (!st.empty() && st.top() <= nums2[j]) {
                        st.pop();
                    }
                    if (st.empty()) {
                        res.push_back(-1);
                    } else {
                        res.push_back(st.top());
                    }
                } else {
                    st.push(nums2[j]);
                }
            }
        }

        return res;
    }
};