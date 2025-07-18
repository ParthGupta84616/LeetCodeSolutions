class Solution {
public:
    string smallestSubsequence(string s) {
        int n = s.length();
        vector<bool> taken(26, false);
        vector<int> lastSeen(26);

        for (int i = 0; i < n; i++) {
            lastSeen[s[i] - 'a'] = i;
        };

        string res = "";

        for (int i = 0; i < n; i++) {
            if (taken[s[i] - 'a'] == true) {
                continue;
            }
            while (res.length() >= 1 && res.back() > s[i] &&
                   lastSeen[res.back()- 'a'] > i) {
                taken[res.back() - 'a'] = false;
                res.pop_back();
            }
            res += s[i];
            taken[res.back() - 'a'] = true;
        }
        return res;
    }
};