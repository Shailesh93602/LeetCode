class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.length(), m = p.length();
        vector<int> ans;

        if(m > n) return ans;

        int left = 0, right = m-1; 
        vector<int> freq1(26, 0), freq2(26, 0);

        for(char ch: p) freq1[ch - 'a']++;
        for(int i=left; i<right; i++) freq2[s[i] - 'a']++;

        while(right < n) {
            freq2[s[right] - 'a']++;
            bool same = true;

            for(int i=0; i<26; i++) {
                if(freq1[i] != freq2[i]) {
                    same = false;
                    break;
                }
            }

            if(same) ans.push_back(left);

            freq2[s[left] - 'a']--;
            left++;
            right++;
        }

        return ans;
    }
};