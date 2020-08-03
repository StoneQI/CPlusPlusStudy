#include "headers.h"

class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        if(index <7) return index;
        std::vector<int> ugly_list(index,-1);
        ugly_list[0]=1;
        int i=0,j=0,k=0;
        
        for(int f=1;f<index;f++){
           ugly_list[f]= std::min(ugly_list[i]*2, std::min(ugly_list[j]*3,ugly_list[k]*5));
            if(ugly_list[f]%2 ==0) i++;
            if(ugly_list[f]%3 ==0 ) j++;
            if(ugly_list[f]%5==0) k++;
        }
        return ugly_list[index-1];
    }
};