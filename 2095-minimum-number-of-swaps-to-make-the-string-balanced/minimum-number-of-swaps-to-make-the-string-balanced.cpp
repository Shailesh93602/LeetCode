class Solution {
public:
    int minSwaps(string s) {
        int ans = 0;
        int n = s.length();

        for(char ch: s) {
            if(ch == '[') ans++;
            else if(ans > 0) ans--;
        }

        return (ans + 1) / 2;
    }
};