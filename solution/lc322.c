/**
 * 322. Coin Change
 * https://leetcode.cn/problems/coin-change/
 * 
 */

#include <stdio.h>
#include <stdlib.h>

int dp(int* coins, int coinsSize, int amount, int* meno) {
    if (amount == 0) {
        return 0;
    }
    if (amount < 0) {
        return -1;
    }
    if (meno[amount] != -2) {
        return meno[amount];
    }
    int res = 10001;
    int temp = 0;
    for (int i = 0; i < coinsSize; i++) {
        temp = dp(coins, coinsSize, amount - coins[i], meno);
        if (temp == -1) {
            continue;
        }
        res = res > ++temp ? temp : res;
    }
    meno[amount] = (res != 10001 ? res : -1);
    return meno[amount];
}

int coinChange(int* coins, int coinsSize, int amount){
    int* meno = malloc(sizeof(int) * (amount + 1));
    for (int i = 0; i < amount + 1; i++) {
        meno[i] = -2;
    }
    return dp(coins, coinsSize, amount, meno);
}

int main() {
    int coins[] = {1, 2, 5};
    int coinsSize = 3;
    int amount = 11;
    int res = coinChange(coins, coinsSize, amount);
    return 0;
}
