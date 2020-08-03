#include "headers.h"
class Solution {
public:
    std::vector<std::vector<int> > FindContinuousSequence(int sum) {
        std::vector<std::vector<int> > result;
        std::vector<int> preffix_sum(sum+1,0);
        for (int i = 1; i <= sum; i++)
        {
            preffix_sum[i] =preffix_sum[i-1]+i;
        }

        for (int i = 0,j =1; i<j && j < sum;)
        {
            if((preffix_sum[j]-preffix_sum[i]) == sum){
                
                    std::vector<int> resultItem;
                    for (int k = i; k <j; k++)
                    {
                        resultItem.push_back(k+1);
                    }
                    result.push_back(resultItem);
                
                i++;
                j++;
            }else if((preffix_sum[j]-preffix_sum[i]) < sum){
                j++;
            }else
            {
                i++;
            }
        }
        return result;
    }

    // bool FindSequence(int start,int end,int sum, std::vector<int> result) {
    //     if (start >=end)
    //     {
    //         return false;
    //     }
    //     if(sum  == 0) return true;
    //     if (sum < 0)return false;
    //     for (int i = start; i <=end; i++)
    //     {
    //         if (FindSequence(i+1,end,sum-i,result)) {
    //             result.push_back(i);
    //             return true;
    //         }
             
    //          return false;
    //     }
    // }

    
};
int main(int argc, const char** argv) {
    Solution solution;
    auto result= solution.FindContinuousSequence(3);
    for (size_t i = 0; i < result.size(); i++)
    {
        for (size_t j = 0; j < result[i].size(); j++)
        {
            std::cout << result[i][j] <<" " ;
        }
        std::cout  << std::endl;
    }
    return 0;
}