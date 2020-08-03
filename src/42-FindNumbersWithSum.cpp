#include "headers.h"

class Solution {
public:
    std::vector<int> FindNumbersWithSum(std::vector<int> array,int sum) {
        int start =0;
        int end = array.size()-1;
        int  min = INT32_MAX;
        int number1=0;
        int number2=0;
        while (start < end)
        {   
            if((array[start]+array[end]) == sum && (array[start]*array[end]) < min ){
                std::cout << start <<" " <<end << std::endl;
                number1 = array[start];
                number2 = array[end];
                min = array[start]*array[end];
                start++;
                end--;
            }
            if( (array[start]+array[end]) < sum){
                start++;
            }else
            {
                end--;
            }
        }
        std::vector<int> result;
        result.push_back(number1);
        result.push_back(number2);
        return result;
    }
};

int main(int argc, const char** argv) {
    Solution solution;
    std::cout << (solution.FindNumbersWithSum({1,2,4,7,11,15},15))[0] << std::endl;
    return 0;
}