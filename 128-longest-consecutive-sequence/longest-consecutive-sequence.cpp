class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int ans = 0;

        for(int i: s) {
            if(!s.count(i - 1)) {
                int count = 1;

                while(s.count(i + 1)) {
                    i++;
                    count++;
                }

                ans = max(ans, count);
            } 
        }

        return ans;
    }
};