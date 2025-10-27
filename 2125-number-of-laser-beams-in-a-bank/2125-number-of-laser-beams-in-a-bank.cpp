class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        // vector<int> res;
        int lastLayer = 0;
        long long output = 0;
        for (int i = 0; i < bank.size(); i++) {
            int layerSum = 0;
            for (int j = 0; j < bank[0].length(); j++) {
                if (bank[i][j] == '1') {
                    layerSum += 1;
                }
            }
            if (layerSum > 0) {
                if (lastLayer == 0) {
                    lastLayer = layerSum;
                } else {
                    output += layerSum * lastLayer;
                    lastLayer = layerSum;
                }
            }
        }
        return output;
    }
};