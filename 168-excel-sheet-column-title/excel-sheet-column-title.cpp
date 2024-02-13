class Solution {
public:
    string convertToTitle(int n) {
        string res = "";
        while(n>0){
            n--;
            int a = n % 26;
            res += (a+'A');
            n /= 26;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};