class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0, right = 0, n = s.length();

        if(n == 0) return 0;
        
        int maxLeft = 0, maxRight = 0;
        vector<int> freq(256, 0);

        while(right < n) {
            char ch = s[right];
            freq[ch]++;

            if(freq[ch] == 1) {
                if(maxRight - maxLeft < right - left) {
                    maxLeft = left;
                    maxRight = right;
                }
            } else {
                while(freq[ch] > 1) {
                    freq[s[left]]--;
                    left++;
                }
            }

            right++;
        }

        return maxRight - maxLeft + 1;
    }
};