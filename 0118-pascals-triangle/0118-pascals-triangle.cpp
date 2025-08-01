class Solution {
public:
    vector<int> generateRow(int row) {
        long long ans = 1;
        vector<int> res;
        res.push_back(1);
        for (int i = 1; i < row; i++) {
            ans = ans * (row - i);
            ans = ans / i;
            res.push_back(ans);
        }
        return res;
    };

    vector<vector<int>> generate(int numRows) {
        vector <vector <int>> output;
        for(int j = 1 ; j < numRows + 1 ; j++){
            output.push_back(generateRow(j));
        }
        return output;
    }
};