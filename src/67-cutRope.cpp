#ifndef SOLUTION
#define SOLUTION
#include <exception>
#include <algorithm>
#include <vector>

class Solution {
public:

    int cutRope(int number) {


        if (number == 2) {
            return 1;
        }
        else if (number == 3) {
            return 2;
        }
        if (number <2 || number >60)
        {
            throw new std::exception();
        }
        return solution(number);

        std::vector<int> mark(number+1,-1);
        // return solution(number, mark);
        // return solution2(number, mark);

        
    }

    //暴力递归
    int solution(int number)
    {
        if (number<=4)
        {
            return number;
        }
     
        int ret = 0;
        for (int i = 1; i < number/2+1; i++)
        {
            ret= std::max(ret, i*solution(number-i));
            
        }
        return ret;
    }

    //暴力递归+记忆
    int solution(int number, std::vector<int> &mark)
    {
        if (number<=4)
        {
            return number;
        }
        if (mark[number] != -1)
        {
            return mark[number];
        }
        int ret = 0;
        for (int i = 1; i < number; i++)
        {
            ret= std::max(ret, i*solution(number-i, mark));
           
            
        }
        mark[number] = ret;
        return ret;
    }

    //动态规划
    int solution2(int number, std::vector<int> &mark)
    {
        
        for (int i = 1; i <= 4; ++i) {
            mark[i] = i;
        }
        int ret = 0;
        for (int i = 5; i <= number; i++)
        {
            for (int j = 1; j < i; j++)
            {
                //计算第cutRope(i)的最大值。
                mark[i]= std::max(mark[i], j*mark[i-j]);
            }
        }
        return mark[number];
    }


};

// s

#endif // !SOLUTION

