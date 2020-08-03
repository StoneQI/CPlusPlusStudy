// 大数乘法
#include "headers.h"
class Solution {
public:
    std::string multiply(std::string num1, std::string num2) {


        if((*num1.begin())=='0' || (*num2.begin())=='0') return std::string("0");

        std::vector<uint8_t> ret(num1.size()+num2.size(),0);
        
        for(int i =num2.size()-1; i >= 0; --i){
            for (int j = num1.size()-1; j>=0; --j)
            {
               ret[i+j+1] = ret[i+j+1]+ (num2[i] -'0')*(num1[j]-'0');
            }
            
        }
        
        int i = ret.size()-1;
        for (; i >=0; i--)
        {
            // if( ret [i] ==0) break;
            uint8_t m = ret[i]/10;
            uint8_t n = ret[i]%10;
            if( i!= 0 && m !=0){
                 ret[i-1] =ret[i-1]+m; 
            }
            ret[i] = n+'0';
        }
        if(ret[0]=='0' && ret.size()>1) return std::string(ret.begin()+1,ret.end());
        return std::string(ret.begin(),ret.end());
        
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;

    std::cout << sol.multiply("8","8");
    return 0;
}
