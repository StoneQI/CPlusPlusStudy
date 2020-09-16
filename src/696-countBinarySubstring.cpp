#include "headers.h"

class Solution {
public:

    int countBinarySubstrings(std::string s) {
        if(s.size() < 2) return 0;
        bool flag = true;
        int count_0 =0;
        int count_1 = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if(s[i] == '0' ){
               count_0++;
               if(s[i] != s[i-1])                          
            } 
            if(s[i] == '1') {
                count_1++;
            }
        }
        

    }
    int countBinarySubstrings2(std::string s) {
        if(s.size() < 2) return 0;
        bool flag = true;
        int ret = 0;
        int count = 1;
        for (int i = 0; i < s.size(); i++)
        {   
            flag = true;
            count = 1;
            for (int j = i+1; j < s.size(); j++)
            {
                if(flag && s[j]==s[i]){
                    count++;
                    continue;
                }else{
                    flag = false;
                }
                if(!flag && s[j] != s[i]){
                    count--;
                    continue;
                }else{
                    break;
                }
            }
            if(count <= 0){
                ret++;
            }
            
        }

        return ret;
        
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    std::cout << sol.countBinarySubstrings("00110011");
    return 0;
}
