class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        string temp = "";
        for(int i=0; i<s.length(); i++) {
            if(s[i] == ' ') {
                if(temp != "") st.push(temp);
                temp = "";
            }
            else temp += s[i];
        }
        if(temp != "") st.push(temp);
        string rev = "";
        while(!st.empty()) {
            if(st.top() != "") rev += st.top();
            st.pop();
            if(!st.empty() and st.top() != "") rev += " ";
        }
        return rev;
    }
};