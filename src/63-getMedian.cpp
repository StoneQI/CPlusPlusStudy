
#include "headers.h"

class Solution {
public:

    std::priority_queue<int,std::vector<int>,std::less<int> > big_heap;

    std::priority_queue<int,std::vector<int>,std::greater<int> > small_heap;
    void Insert(int num)
    {
       if(big_heap.size() == small_heap.size()){
           big_heap.push(num);
           small_heap.push(big_heap.top());
           big_heap.pop();
       }else{
           small_heap.push(num);
            big_heap.push(small_heap.top());
           small_heap.pop();
          
       }


    }

    double GetMedian()
    { 
        if(small_heap.size() == big_heap.size()){
            return (small_heap.top() + big_heap.top())/2.0;
        }else
        {
            return small_heap.top();
        }
        
    }

};

int main(int argc, const char** argv) {
    std::vector<int> num {5,2,3,4,1,6,7,0,8};
    Solution solution;
    for(auto var : num)
    {
        solution.Insert(var);
        std::cout << solution.GetMedian()<<" ";
    }
    std::cout<<std::endl;
    return 0;
}