class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for(int i =  0 ; i < 32 ; i++){
            int temp = 1 << i;
            int count1 = 0;
            for(int j = 0 ; j < nums.size() ; j++){
                if((nums[j] & temp) != 0){
                    count1++;
                }
            }
            if(count1 % 3 == 1){
                res |= temp;
            }
        }
        return res;
    }
};