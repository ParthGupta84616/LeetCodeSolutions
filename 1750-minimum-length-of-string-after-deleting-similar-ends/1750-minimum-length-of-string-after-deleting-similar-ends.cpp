class Solution {
public:
    int minimumLength(string s) {
        if (s.size() == 1)
            return 1;

        int i = 0;
        int j = s.size() - 1;

        while (i < j && s[i] == s[j]) {
            char ch = s[i];
            while(i <= j && ch == s[i]){
                i++;
            }
            while(i <= j && ch == s[j]){
                j--;
            }
        }

        return  j - i + 1;
    }
};