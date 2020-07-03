
#include <algorithm>
#include <vector>
#include <deque>
#include <iostream>

class Solution
{
public:
    //暴力算法
    std::vector<int> maxInWindows(const std::vector<int> &num, unsigned int size)
    {
        if (num.size() <= 1 || size == 1)
        {
            return num;
        }
        std::vector<int> result;
        //当size为0返回空
        if (num.size() == 0 || size < 1 || num.size() < size)
            return result;

        //重点+1
        for (int i = 0; i < num.size() - size + 1; i++)
        {
            int max = num[i];
            for (int j = i; j < i + size; j++)
            {
                max = std::max(max, num[j]);
            }

            result.push_back(max);
        }
        return result;
    }


    std::vector<int> maxInWindows2(const std::vector<int> &num, unsigned int size)
    {
        if (num.size() <= 1 || size == 1)
        {
            return num;
        }
        std::vector<int> result;
        //当size为0返回空
        if (num.size() == 0 || size < 1 || num.size() < size)
            return result;

        int n = num.size();
        std::deque<int> dp;
        for (int i = 0; i < num.size(); i++)
        {
            //类似维护一个大根堆，仅保存最大值
            
            while (!dp.empty() && num[dp.back()]<num[i])
            {
                dp.pop_back();
            }
            dp.push_back(i);
            //移除不在当前滑动窗口的内容
            if(dp.front()+size<=i){
                dp.pop_front();
            }
            //判断形成窗口后，没每移动一步，获得最大值放入窗口
            if(i+1 >= size){
                result.push_back(num[dp.front()]);
            }
            
        }
        return result;
    }
};

int main(int argc, const char** argv) {
    Solution solution;
    for (auto &&i : solution.maxInWindows2({2,3,4,2,6,2,5,1},3))
    {
         std::cout<<i<<std::endl;
    }
    
    // std::cout<<solution.maxInWindows2({2,3,4,2,6,2,5,1},3)<<std::endl;

    return 0;
}