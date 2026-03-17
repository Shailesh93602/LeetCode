class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans = 0;
        unordered_set<int> s(nums.begin(), nums.end());

        for(int num: s) {
            if(!s.count(num - 1)) {
                int i = num, len = 1;
                while(s.count(++i)) len++;

                ans = max(ans, len);
            }
        }

        return ans;
    }
};