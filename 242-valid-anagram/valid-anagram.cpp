class Solution {
public:
    bool isAnagram(string a, string b) {
        if(a.length() != b.length()) return false;
        int freq[26] = {0};
        for(int i=0; i<a.length(); i++) {
            freq[a[i]-'a']++;
            freq[b[i]-'a']--;
        }
        for(int i=0; i<26; i++) if(freq[i] != 0) return false;
        return true;
    }
};