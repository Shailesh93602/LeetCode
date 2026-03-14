class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26, 0);
        int left = 0, right = 0, n = s.length();
        int maxFreq = 0;

        while(right < n) {
            char ch = s[right];
            freq[ch - 'A']++;

            if(freq[ch - 'A'] > maxFreq) maxFreq = freq[ch - 'A'];

            if(right - left - maxFreq + 1 > k) {
                freq[s[left] - 'A']--;
                left++;
            }

            right++;
        }
        return right - left;
    }
};