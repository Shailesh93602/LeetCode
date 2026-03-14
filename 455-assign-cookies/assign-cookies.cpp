class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int ans = 0;

        int n = g.size(), m = s.size();
        int left = 0, right = 0;

        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        while(left < n && right < m) {
            if(g[left] <= s[right]) {
                ans++;
                left++;
            }

            right++;
        }

        return ans;
    }
};