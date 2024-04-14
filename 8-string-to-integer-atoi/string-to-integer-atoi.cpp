class Solution {
public:
    int myAtoi(string s) {
        int i=0;
        bool flag = true;
        long ans = 0;
        while(i < s.length() && s[i]== ' ') i++;
        if(s[i] == '-') {
            flag = false;
            i++;
        }
        else if(s[i] == '+') i++;
        while(i < s.length()) {
            if(s[i] >= '0' && s[i] <= '9') {
                ans *= 10;
                ans += s[i]-'0';
                if(ans > INT_MAX) {
                    if(flag) return INT_MAX;
                    return INT_MIN;
                }
                i++;
            }
            else return flag ? ans : -ans;
        }
        return flag ? ans : -ans;
    }
};