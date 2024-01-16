class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0;
        int start = 0;
        unordered_map<char, int> charMap;;
        for(int i=0; i<s.length(); i++){
            char curr = s[i];
            if(charMap.find(curr) != charMap.end() and charMap[curr] >= start){
                start = charMap[curr]+1;
            }
            charMap[curr] = i;
            maxLen = max(maxLen, i - start + 1);
        }
        return maxLen;
    }
};