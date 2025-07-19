class Solution {
public:
    int countHomogenous(string s) {
        long long count = 1;
        long long res = 0;
        long long mod = 1000000007;
        for (int i = 0; i < s.length() - 1; i++) {
            if (s[i] == s[i + 1]) {
                count++;
            } else {
                res = (res + ((count) * (count + 1) / 2) % mod) ;
                count = 1;
            }
        }
        res = (res + ((count) * (count + 1) / 2) % mod) ;
        return res;
    }
};