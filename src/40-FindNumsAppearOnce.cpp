#include "headers.h"

class Solution {
public:
    void FindNumsAppearOnce(std::vector<int> data,int* num1,int *num2) {
        int xor1=0;
        for (int i = 0; i < data.size(); i++)
        {
            xor1 = xor1^data[i];
        }
        int index = 1;
        while((index & xor1)==0)
            index = index <<1;

        for(int i=0; i < data.size(); i++){
            if((index & data[i]) == 0)
                (*num1) = (*num1)^data[i];
            else
                (*num2) =(*num2)^data[i];
        }
    }
};