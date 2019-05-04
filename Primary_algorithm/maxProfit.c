#include <stdio.h>

int maxProfit(int* prices, int pricesSize){
    int maxProfit = 0;
    int i = 0;

    for (; i < pricesSize - 1; ++i){
        if (prices[i] < prices[i + 1])
            maxProfit += prices[i + 1] - prices[i];
    }

    return maxProfit;
}

int main(void){
    int prices[] = {7,1,5,3,6,4};
    int pricesSize = sizeof(prices) / sizeof(prices[0]);
    
    printf("max profit: %d", maxProfit(prices, pricesSize));

    return 0;
}