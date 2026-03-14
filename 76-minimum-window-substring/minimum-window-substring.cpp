#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> freq(256, 0);

        for(char c : t)
            freq[c]++;

        int left = 0, right = 0;
        int matched = 0;
        int start = 0;
        int minLen = INT_MAX;

        while(right < s.size()) {
            char c = s[right];

            if(freq[c] > 0)
                matched++;

            freq[c]--;
            right++;

            while(matched == t.size()) {

                if(right - left < minLen) {
                    minLen = right - left;
                    start = left;
                }

                char leftChar = s[left];
                freq[leftChar]++;

                if(freq[leftChar] > 0)
                    matched--;

                left++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};