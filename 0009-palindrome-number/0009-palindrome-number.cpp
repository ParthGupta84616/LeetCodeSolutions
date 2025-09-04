class Solution {
public:
    bool isPalindrome(int x) {
        string num = to_string(x);
        string original = num;
        reverse(num.begin(), num.end());
        return (original == num);
    }
};
