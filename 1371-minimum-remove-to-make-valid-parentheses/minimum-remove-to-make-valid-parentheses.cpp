class Solution {
public:
    string minRemoveToMakeValid(string s) {
         int leftCount = 0;
        int rightCount = 0;
        stack<char> st;

        for (char ch : s) {
            if (ch == '(') {
                leftCount++;
            } else if (ch == ')') {
                rightCount++;
            }
            if (rightCount > leftCount) {
                rightCount--;
                continue;
            } else {
                st.push(ch);
            }
        }

        string result = "";
        
        while (!st.empty()) {
            char currentChar = st.top();
            st.pop();
            if (leftCount > rightCount && currentChar == '(') {
                leftCount--;
            } else {
                result += currentChar;
            }
        }

        reverse(result.begin(), result.end());
        return result;
    }
};