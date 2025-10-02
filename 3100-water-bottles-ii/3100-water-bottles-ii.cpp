class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int res = numBottles;
        int empty = numBottles;
        while (empty >= numExchange && empty / numExchange >= 1) {
            res++;
            empty -= numExchange;
            empty++;
            numExchange++;
        }
        return res;
    }
};