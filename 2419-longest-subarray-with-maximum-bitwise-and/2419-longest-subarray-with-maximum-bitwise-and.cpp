class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int count  = 0 ;
        int Cmax = 0 ;
        int res = 0;
        for(int num : nums){
            if(Cmax < num){
                count = res = 1;

                Cmax = num;
            }else{
                if(Cmax == num){
                    count++;
                }else{
                    count = 0;
                }
            }
            res = max(res , count);
        }
        return res;
    }
};