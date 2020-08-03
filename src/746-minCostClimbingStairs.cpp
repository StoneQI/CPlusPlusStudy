#include "headers.h"

class Solution {
public:
    int minCostClimbingStairs(std::vector<int>& cost) {
        int pre=0; int cur =cost[0]; int temp =0;

        for(int i =1; i< cost.size();i++){
            temp = cur ;
            cur = std::min(pre+cost[i],cur+ cost[i]);
            pre = temp;
            // if((pre+cost[i])<(cur+cost[i])){
            //     cur = pre+cost[i];
            //     pre = cur;
            // }else{
                
            //     cur = cur+cost[i];
            //     pre = cur;
            // }
        }
        return std::min(cur,pre);
    }
};

int main(int argc, const char** argv) {
    Solution sol;
    std::vector<int> dd = {0,0,0,0};
    std::cout<< sol.minCostClimbingStairs(dd);
    return 0;
}