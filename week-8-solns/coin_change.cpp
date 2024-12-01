class Solution {
public:

    int coinChange(vector<int>& coins, int amount) {
        vector<int> min_needed (amount + 1, amount + 1);

        min_needed[0] = 0;

        for(int i = 1 ; i <= amount ; i++) {
            for(int j = 0 ; j < coins.size() ; j++) {
                if (i - coins[j] >= 0) {
                    min_needed[i] = min(min_needed[i], 1 + min_needed[i - coins[j]]);
                }
            }
        }

        return min_needed[amount] != amount + 1 ? min_needed[amount] : -1;
    }
};