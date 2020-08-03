#include "headers.h"

class Solution {
public:
    std::string addStrings(std::string num1, std::string num2) {
        int max = std::max(num1.size(),num2.size());
        int num1_cur =num1.size()-1;
        int num2_cur = num2.size()-1;
        std::vector<char> ret(max+1,'0');
        int ret_cur = max;
        int  sum = 0;
        int jingwei = 0;
        for(;ret_cur >0;--num1_cur,--num2_cur,--ret_cur){

            if( num1_cur <0  ){
                sum = num2[num2_cur] +ret[ret_cur]-'0'-'0';
            }else if (num2_cur <0 )
            {
                sum = num1[num1_cur] +ret[ret_cur]-'0'-'0';
            }else
            {
                sum = num1[num1_cur]+num2[num2_cur] +ret[ret_cur]-'0'-'0'-'0';
            }
            
            jingwei = sum/10;
            int yusu = sum % 10;
            if( jingwei !=0){
                ret[ret_cur-1] = jingwei+'0';
            }
            ret[ret_cur] = yusu+'0';
        }
        ret[ret_cur] = jingwei+'0';
        if( (*ret.begin()) == '0')
            return std::string(ret.begin()+1,ret.end());
        return std::string(ret.begin(),ret.end());
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;
    std::cout << sol.addStrings("8888","08") <<std::endl;
    return 0;
}
