class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int res = numBottles;
        int empty = numBottles;
        while(empty >= numExchange){
            int newFull = empty / numExchange;
            empty =  (empty % numExchange) + (newFull);
            res += newFull;
        }
        return res ;
    }
};