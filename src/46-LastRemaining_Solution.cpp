#include "headers.h"

class Solution {
public:
    int LastRemaining_Solution(int n, int m)
    {
        std::deque<int> number;
        if(n <=0|| m< 0) return -1;
        if(n<2) return n;
        for (int i = 0; i < n; i++)
        {
            number.push_back(i);
        }
        int current = 0;
        while (number.size()>1)
        {
            int temp = number.front();
            number.pop_front();
            if(current == m-1) {
                current =0;
            }else
            {
                number.push_back(temp);
                current++;
            }
            
        }
        return number.front();
        
    }
};

int main(int argc, const char** argv) {

    Solution solution;

    std::cout << solution.LastRemaining_Solution(5,3);
    return 0;
}