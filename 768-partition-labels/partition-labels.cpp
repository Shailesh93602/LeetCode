class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> ans;
        vector<int> freq(26, 0);

        int n = s.length();
        for (int i = 0; i < n; i++)
            freq[s[i] - 'a'] = i;

        int start = 0, end = freq[s[0] - 'a'];
        for (int i = 0; i < n; i++) {
            end = max(end, freq[s[i] - 'a']);

            if (i == end) {
                ans.push_back(i - start + 1);
                start = i + 1;
            }
        }

        return ans;
    }
};