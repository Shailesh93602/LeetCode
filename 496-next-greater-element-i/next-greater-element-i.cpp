class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int, int> mp;

        for(int num: nums2) {
            while(!st.empty() && st.top() < num) {
                int top = st.top();

                mp[top] = num;
                st.pop();
            } 

            st.push(num);
        }

        int n = nums1.size();
        vector<int> ans(n, -1);
        for(int i=0; i<n; i++) if(mp.count(nums1[i])) ans[i] = mp[nums1[i]];
        
        return ans;
    }
};