class Solution {
public:
    int reverse(int x) {
        long long num = x;
        stack<int> st;
        long long res = 0;
        bool negative = false;
        if (num < 0) {
            negative = true;
            num *= -1;
        }
        while (num) {
            res *= 10;
            res += num % 10;
            num /= 10;
        }

        if (negative) {
            return (res > 2147483648) ? 0 : res * (-1);
        }

        return (res > 2147483647) ? 0 : res;
    }
};