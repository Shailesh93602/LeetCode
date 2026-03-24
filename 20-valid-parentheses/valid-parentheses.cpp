class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        unordered_map<char, char> mp = {
            { '(', ')' },
            { '[', ']' },
            { '{', '}' }
        };

        for(char ch: s) {
            if(ch == '(' || ch == '[' || ch == '{') st.push(ch);
            else if(st.empty()) return false;
            else {
                char top = st.top();

                if(mp[top] == ch) st.pop();
                else return false;
            }
        }

        return st.empty();
    }
};