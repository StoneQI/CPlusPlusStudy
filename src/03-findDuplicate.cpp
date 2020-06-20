// #include "headers.h"
#include <iostream>
#include <vector>

// 找出数组中重复的数字
// 长度为n的数组里所有数字都在0~n-1里。数组中有数字重复，但不知道几个数组重复，输出其中任意一个重复数字

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

private:
};

int findDuplicate::findDuplicate2(std::vector<int> data){
    if(data.size()==0){
        return 0;
    }
    

}

int max(int a, int b){
    if(a>b) return a;
    return b;
}
