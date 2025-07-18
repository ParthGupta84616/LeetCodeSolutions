class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int> aplhabet(26, 0);
        int res = 0;
        for (char x : s) {
            aplhabet[x - 'a'] += 1;
        }
        for (int i = 0; i < 26; i++) {
            if (aplhabet[i] >= 2) {
                set<char> temp;
                int start = 0;
                int end = 0;
                for (int j = 0; j < s.length(); j++) {
                    if ('a' + i == s[j]) {
                        start = j;
                        break;
                    }
                }
                for (int j = s.length() - 1; j >= 0; j--) {
                    if ('a' + i == s[j]) {
                        end = j;
                        break;
                    }
                }
                for (int j = start + 1; j < end; j++) {
                    temp.insert(s[j]);
                    
                }
                res += temp.size();
            }
        }
        return res;
    }
};