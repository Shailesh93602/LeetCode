class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.length(), m = s2.length();

        if(n > m) return false;

        vector<int> freq1(26, 0), freq2(26, 0);

        for(char ch: s1) freq1[ch - 'a']++;

        int left = 0, right = n-1;

        for(int i=left; i<right; i++) {
            freq2[s2[i] - 'a']++;
        }

        while(right < m) {
            char ch = s2[right];
            freq2[ch - 'a']++;
            bool isChanged = false;

            for(int i=0; i<26; i++) {
                if(freq1[i] != freq2[i]) {
                    isChanged = true;
                    break;
                }
            } 

            if(!isChanged) return true;

            freq2[s2[left] - 'a']--;
            left++;
            right++;
        }

        return false;
    }
};