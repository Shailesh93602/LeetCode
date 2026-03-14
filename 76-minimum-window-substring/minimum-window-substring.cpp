class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.length(), n = t.length();
        vector<int> freq1(256, 0), freq2(256, 0);

        for(unsigned char ch: t) {
            freq1[ch]++;
        }

        int left = 0, right = 0, minLen = INT_MAX, minLeft = 0, minRight = m-1;

        while(right < m) {
            unsigned char ch = s[right];
            freq2[ch]++;
            bool isChanged = false;

            for(int i=0; i<256; i++) {
                if(freq2[i] < freq1[i]) {
                    isChanged = true;
                    break;
                }
            }

            while(freq2[s[left]] > freq1[s[left]]) {
                freq2[s[left]]--;
                left++;
            }

            if(!isChanged) {
                if(right-left+1 < minLen) {
                    minLen = right-left+1;
                    minLeft = left;
                    minRight = right;
                }
            }

            right++;
        }

        if(minLen == INT_MAX) return "";

        return s.substr(minLeft, minLen);
    }
};