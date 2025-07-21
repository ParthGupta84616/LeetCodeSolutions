class Solution {
public:
    int beautifulSubstrings(string s, int k) {
        int vowel = 0;
        int consonant = 0;
        int res = 0;
        for (int j = 0; j < s.length(); j++) {
            for (int i = j; i < s.length(); i++) {
                if (s[i] == 'i' || s[i] == 'o' || s[i] == 'a' || s[i] == 'u' ||
                    s[i] == 'e') {
                    vowel += 1;
                } else {
                    consonant += 1;
                }
                res += ((vowel * consonant) % k == 0 && vowel == consonant) ? 1
                                                                            : 0;
            }
            vowel = 0;
            consonant = 0;
        }
        return res;
    }
};