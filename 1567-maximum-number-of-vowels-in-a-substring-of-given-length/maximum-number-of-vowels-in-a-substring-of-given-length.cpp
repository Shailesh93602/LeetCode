class Solution {
public:
    bool isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
    int maxVowels(string s, int k) {
        int count = 0, n = s.length(), left = 0, right = k-1, maxCount = 0;

        for(int i=0; i<right; i++) if(isVowel(s[i])) count++;

        while(right < n) {
            if(isVowel(s[right])) count++;

            maxCount = max(maxCount, count);

            if(isVowel(s[left])) count--;
            left++;
            right++;
        }

        return maxCount;
    }
};