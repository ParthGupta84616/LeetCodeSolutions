class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(!s.length()){
            return true;
        }
        int ptrS = 0;
        for (int i = 0; i < t.length(); i++) {
            if (t[i] == s[ptrS]) {
                ptrS++;
                if(ptrS == s.length()){
                    return true;
                }
            }
        }
        return false;
    }
};