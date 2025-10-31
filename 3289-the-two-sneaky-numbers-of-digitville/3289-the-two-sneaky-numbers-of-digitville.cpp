class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int> res;
        map<int,int> mp;
        for(int n : nums){
            mp[n]++;
        }
        for(auto num : mp){
            if(num.second == 2){
                res.push_back(num.first);
            }
        }
        return res;
    }
};