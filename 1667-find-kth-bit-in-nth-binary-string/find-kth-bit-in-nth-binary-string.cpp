class Solution {
public:
    string inverse(string &s) {
        for(char &ch: s) {
            if(ch == '0') ch = '1';
            else ch = '0';
        }

        return s;
    }
    string solve(string s) {
        string ans = "";

        for(int i=s.length()-1; i>=0; i--) {
            ans += s[i];
        }

        return inverse(ans);
    }
    char findKthBit(int n, int k) {
        string prev;
        string ans = "0";
        while(n--) {
            prev = ans;
            ans = prev + '1' + solve(prev);
        }

        return ans[k-1];
    }
};