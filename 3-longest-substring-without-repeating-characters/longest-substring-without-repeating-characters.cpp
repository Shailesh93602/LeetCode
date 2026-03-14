class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> freq(256, 0);
        int left = 0, right = 0, maxLen = 0, n = s.length();

        while(right < n) {
            unsigned char ch = s[right];
            freq[ch]++;

            while(freq[ch] > 1) {
                freq[(unsigned char)s[left]]--;
                left++;
            }
            
            maxLen = max(maxLen, right-left+1);
            right++;
        }

        return maxLen;
    }
};