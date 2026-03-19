class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans = 0, n = heights.size();
        stack<pair<int, int>> st;

        for(int i=0; i<n; i++) {
            int start = i;

            while(!st.empty() && st.top().second > heights[i]) {
                auto [j, height] = st.top();
                st.pop();

                ans = max(ans, height * (i - j));
                start = j;
            }

            st.push({ start, heights[i] });
        }

        while(!st.empty()) {
            auto [j, height] = st.top();
            st.pop();

            ans = max(ans, height * (n - j));
        }

        return ans;
    }
};

// 2 1 5 6 2 3
// 2 - push to stak, self height 2, maxH = 2
// 1 < 2, self height 1, height with 2 is 2, maxH = 2, pop 2 from stack, push 1 to stack 
// 5 > 1, self height 5, height with 1 is 3(that means we need to store index of 2 along with 1 to calculate the difference), keep 1 in stack, push 5 to stack, maxH = 5
// 6 > 5, self height 6, height with 5 is 10, height with 1 is 4, push 6 to stack, keep 5 & 1 in stack, maxH = 10;
// 2 < 6, self height 2, height with 6 is 4, height with 5 is 6, height with 1 is 4, pop 5 & 6, keep 1, push 2, maxH = 10
// 3 > 2, self height 3, height with 2 is 4, height with 1 is 5, push 3, maxH = 10