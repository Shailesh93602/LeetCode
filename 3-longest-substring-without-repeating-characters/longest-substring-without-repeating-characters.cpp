class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0, maxLen = 0;
        vector<int> lastIndex(256, -1);

        for (int i=0; i<s.length(); i++) {
            if(lastIndex[s[i]] != -1) left = max(left, (lastIndex[s[i]] + 1));

            lastIndex[s[i]] = i;
            maxLen = max(maxLen, i - left + 1);
        }

        return maxLen;
    }
};