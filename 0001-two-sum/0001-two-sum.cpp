class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> num = nums;
        sort(nums.begin() , nums.end());
        int n = nums.size() - 1;
        int m = 0;
        while(m < n){
            if(nums[n] + nums[m] == target) {
                break;
            }
            else if(nums[n] + nums[m] > target) n--;
            else m++;
        }
        for(int i = 0 ; i < num.size() ; i++){
            if(num[i] == nums[m]) {
                m = i;
                break;
            };
        }
        for(int i = num.size() - 1 ; i >= 0 ; i--){
            if(num[i] == nums[n]) {
                n = i;
                break;
            };
        }
        
        return {m,n};
    }
};