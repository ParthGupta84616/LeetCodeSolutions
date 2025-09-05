class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        int t = 1;
        while (t < 60) { 
            long long lhs = (long long)num1 - (long long)t * num2;
            if (lhs < 0) return -1; 
            
            string binary = bitset<64>(lhs).to_string(); 
            int OneCount = 0;
            for (char c : binary) {
                if (c == '1') OneCount++;
            }
            if (OneCount <= t && lhs >= t) {
                return t;
            }
            t++;
        }
        return -1;
    }
};
