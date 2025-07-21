class Solution {
public:
    int numberOfWays(string corridor) {
        int sofa = 0;
        int res = 0;
        int mod = 1000000007;
        long long multi = 1;
        int count = 0;
        for(char x : corridor){
            if(x == 'S'){
                count += 1;
            }
        }
        if(count == 0 || count%2 == 1){
            return 0;
        } 
        
        for (int i = 0; i < corridor.size(); i++) {
            if (corridor[i] == 'S') {
                sofa++;
            }
            if (sofa == 2) {
                int temp = 0;
                int j = i + 1;
                while (j < corridor.size() && corridor[j] == 'P') {
                    temp++;
                    j++;
                    if(j == corridor.size()){
                        temp = 0;
                    }
                }
                multi = (multi * (temp + 1)) % mod;
                sofa = 0;
            }
        }
        return (multi) % mod ;
    }
};