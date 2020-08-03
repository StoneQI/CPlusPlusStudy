// #include "headers.h"
#include <iostream>
#include <vector>

// 找出数组中重复的数字
// 长度为n的数组里所有数字都在0~n-1里。数组中有数字重复，但不知道几个数组重复，输出其中任意一个重复数字

// 方法1：先排序，然后逐个查找重复值
// 方法2：使用hashmap，查找每一位是否有重复值

class findDuplicate
{
public:
    findDuplicate();
    findDuplicate(findDuplicate &&) = default;
    findDuplicate(const findDuplicate &) = default;
    findDuplicate &operator=(findDuplicate &&) = default;
    findDuplicate &operator=(const findDuplicate &) = default;
    ~findDuplicate();
    static int findDuplicate2(std::vector<int> data);

    static int findDuplicate3(std::vector<int> data);

private:
};

int findDuplicate::findDuplicate2(std::vector<int> data){
    if(data.size()==0){
        return -1;
    }

    for (int i = 0; i < data.size(); i++)
    {
        if (data[i]< 0 || data[i]>data.size()-1)
        {
            return -1;
        }
    }
    for (int i = 0; i < data.size(); i++)
    {
        if(data[i]!= i){
            if (data[data[i]] == data[i])
            {
                return data[i];
            }else
            {
                int temp = data[i];
                data[i] = data[data[i]];
                data[temp] = temp;
                i--;
            }
            
        }
    }
    return -1;
    

}

int findDuplicate::findDuplicate3(std::vector<int> data){
    if(data.size()==0){
        return -1;
    }

    for (int i = 0; i < data.size(); i++)
    {
        if (data[i]< 0 || data[i]>data.size()-1)
        {
            return -1;
        }
    }
    for (int i = 0; i < data.size(); i++)
    {
        if(data[i]!= i){
            if (data[data[i]] == data[i])
            {
                return data[i];
            }else
            {
                int temp = data[i];
                data[i] = data[data[i]];
                data[temp] = temp;
                i--;
            }
            
        }
    }
    return -1;
    

}

// int main(int argc, const char** argv) {
    
//     return 0;
// }
// int max(int a, int b){
//     if(a>b) return a;
//     return b;
// }
