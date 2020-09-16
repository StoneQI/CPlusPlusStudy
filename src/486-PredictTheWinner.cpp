#include "headers.h"

using std::vector;
class Solution {
public:
    bool PredictTheWinner(vector<int>&& nums) {
        return predcitWinner(0,nums.size()-1,0,0,true,nums);
    }

    bool predcitWinner(int start,int end, int agree1,int agree2, bool isA, vector<int>& nums){
        if(start > end){
            if(agree1 < agree2) return false;
            return true;
        }
        if(start == end){
            if(isA){
                agree1 += nums[start];
                return predcitWinner(start+1,end,agree1,agree2,false,nums);
            }else{
                agree2 += nums[start];
                return predcitWinner(start,end-1,agree1,agree2,true,nums);
            }
        }
        if(isA){
            agree1 += nums[start];
            if(predcitWinner(start+1,end,agree1,agree2,false,nums)) return true;
            agree1 = agree1 - nums[start] + nums[end];
            return predcitWinner(start,end-1,agree1,agree2,false,nums);
        }else{
            agree2 += nums[start];
            if(predcitWinner(start+1,end,agree1,agree2,true,nums)) return true;
            agree2 = agree2 - nums[start] + nums[end];
            return predcitWinner(start,end-1,agree1,agree2,true,nums);
        }

    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    std::cout << sol.PredictTheWinner({1,5,2});
    return 0;
}
