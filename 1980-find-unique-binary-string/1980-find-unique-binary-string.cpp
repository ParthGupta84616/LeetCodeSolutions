class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        sort(nums.begin() , nums.end());
        int n = nums.size();
        string base = "";
        for (int i = 0; i < n; i++) {
            base += '0';
        }
        for(int i = 0 ; i < n ; i ++){
            if(base != nums[i]){
                return base;
            }else{
                int num = stoi(base, nullptr, 2);
                num += 1;
                bitset<16> b(num);
                base = b.to_string().substr(16-n);
            }
        }
        return base;
    }
};