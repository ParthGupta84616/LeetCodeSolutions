class Solution {
public:
    string breakPalindrome(string palindrome) {
        bool done = false;
        for (int i = 0; i < palindrome.size(); i++) {
            if (palindrome.size() % 2 == 1) {
                if (i == (palindrome.size()) / 2) {
                    continue;
                }
            }
            if (palindrome[i] != 'a') {
                palindrome[i] = 'a';
                done = true;
                break;
            }
        }

        if (!done) {
            if (palindrome.size() == 1) {
                return "";
            }
            palindrome[palindrome.size() - 1] = 'b';
        }

        return palindrome;
    }
};