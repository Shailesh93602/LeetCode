class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        vector<int> ans(n, -1);

        for(int i=0; i<2*n-1; i++) {
            while(!st.empty() && nums[st.top()] < nums[i % n]) {
                int top = st.top();

                ans[top] = nums[i % n];
                st.pop();
            }

            if(i < n) st.push(i);
        }

        return ans;
    }
};