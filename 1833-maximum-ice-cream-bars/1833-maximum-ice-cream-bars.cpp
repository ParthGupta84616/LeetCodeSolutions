class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int i = 0;
        int res = 0;
        while(i < costs.size()){
            coins -= costs[i];
            if(coins < 0) return res;
            res++;
            i++;
        }
        return res;
    }
};