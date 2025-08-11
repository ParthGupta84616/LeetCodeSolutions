class Solution {
public:
    long long MOD = 1000000007;

    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        string binary = bitset<32>(n).to_string();
        vector<int> finalArr;
        vector<int> res;
        for (int i = binary.size() - 1; i >= 0; i--) {
            if (binary[i] == '1') {
                finalArr.push_back(pow(2, 32 - i - 1));
            }
        }
        for(int i = 0 ; i < queries.size() ; i++){
            long long product = 1;
            for(int j = queries[i][0] ; j <= queries[i][1]; j++){
                product *= finalArr[j];
                product %= MOD;
            }
            res.push_back(product);
        }
        return res;
    }
};