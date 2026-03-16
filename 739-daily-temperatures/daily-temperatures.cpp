class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<pair<int, int>> st;
        vector<int> ans(n, 0);

        for(int i=0; i<n; i++) {
            while(!st.empty()) {
                pair<int, int> top = st.top();

                if(top.second < temperatures[i]) ans[top.first] = i - top.first;
                else break;

                st.pop();
            }

            st.push({ i, temperatures[i] });
        }

        return ans;
    }
};