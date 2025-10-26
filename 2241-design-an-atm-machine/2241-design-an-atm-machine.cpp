class ATM {
public:
    vector<int> Inventory;
    ATM() {
        for (int i = 0; i < 5; i++) {
            Inventory.push_back(0);
        }
    }

    void deposit(vector<int> banknotesCount) {
        for (int i = 0; i < banknotesCount.size(); i++) {
            Inventory[i] += banknotesCount[i];
        }
    }

    vector<int> withdraw(int amount) {
        vector<int> relation = {20, 50, 100, 200, 500};
        vector<int> transaction = {0, 0, 0, 0, 0};

        vector<int> originalInventory = Inventory;
        for (int i = 4; i >= 0; i--) {
            int domination = relation[i];
            while (amount >= domination && Inventory[i] >= 1) {
                int canUse = min(Inventory[i], amount / domination);
                amount -= canUse * domination;
                transaction[i] += canUse;
                Inventory[i] -= canUse;
            }
        }
        if (amount == 0) {
            return transaction;
        } else {
            Inventory = originalInventory;
            return {-1};
        }
    }
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */