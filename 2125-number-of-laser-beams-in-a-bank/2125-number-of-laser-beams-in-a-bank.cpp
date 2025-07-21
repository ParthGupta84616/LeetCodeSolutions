class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        vector<int> res;
        for (int i = 0; i < bank.size(); i++) {
            int layerSum = 0;
            for (int j = 0; j < bank[0].length(); j++) {
                if (bank[i][j] == '1') {
                    layerSum += 1;
                }
            }
            if (layerSum > 0) {
                res.push_back(layerSum);
            }
        }
        long long output = 0;
        if(res.size() < 2){
            return 0;
        }
        for(int i = 0 ; i < res.size() - 1 ; i++){
            cout<< res[i + 1];
            output += res[i] * res[i+1];
        }
        return output;
    }
};