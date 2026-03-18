class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        stack<int> st;

        for (int i : nums2) {
            while (!st.empty() && st.top() < i) {
                mp[st.top()] = i;
                st.pop();
            }

            st.push(i);
        }

        int n = nums1.size();
        vector<int> ans(n, -1);

        for (int i=0; i<n; i++) if (mp.count(nums1[i])) ans[i] = mp[nums1[i]];

        return ans;
    }
};