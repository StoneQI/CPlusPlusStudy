#include "headers.h"

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max=0;
        int minCuros= 0;
        for(int i = 1; i < prices.size(); i++){
            int profit = prices[i] - prices[minCuros];
            if(profit <= 0){
                minCuros = i;
            }else{
                max = std::max(max,profit);
            }

        }
        return max;
    }
};