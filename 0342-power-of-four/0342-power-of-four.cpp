class Solution {
public:
    bool isPowerOfFour(int n) {

        string binary = bitset<32>(n).to_string();
        int count = 0;
        int idx = 0;
        for (int i = 0; i < 32; i++) {
            if (binary[i] == '1'){
                count++;
                
                idx = i;
            }
            

        }
        return (count == 1 && idx%2 == 1 ) ? true : false;
    }
};