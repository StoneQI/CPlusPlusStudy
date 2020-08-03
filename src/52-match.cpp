#include "headers.h"

class Solution {
public:
    bool match2(char* str, char* pattern)
    {   
        if(str ==nullptr && pattern==nullptr){
            return true;
        }
        int strLen = strlen(str);
        std::cout << strLen <<std::endl;
        int patternLen = strlen(pattern);


        int strPosi = 0;
        int patternPosi1= 0;
        int patternPosi2 = 1;
        int mode =0;

        // if(strLen ==0 && patternLen==0){
        //     return true;
        // }else if(strLen ==0 && patternLen==1 && pattern[patternPosi1] =='.'){
        //     return false;
        // }else if
        // if(patternPosi2 < patternLen){
        //         if(pattern[patternPosi2] =='*' && pattern[patternPosi2] =='.') return true;
        //     }



        while (patternPosi1 < patternLen)
        {   
            if( strPosi >=strLen) break;
            mode =0;
            
            if(pattern[patternPosi1] == '.') mode =1;

            if(patternPosi2 < patternLen){
                if(pattern[patternPosi2] =='*') mode =2;
            }
            
            switch (mode)
            {
            case 0:
                if(!isSame(str[strPosi],pattern[patternPosi1])) return false;
                strPosi++;
                patternPosi1++;
                patternPosi2++;
                break;
            case 1: 
                strPosi++;
                patternPosi1++;
                patternPosi2++;
                break;
            case 2:
                while(strPosi <strLen){
                    if(isSame(str[strPosi],pattern[patternPosi1])){
                        strPosi++;
                    }else
                    {
                        break;
                    }
                    
                }
                patternPosi1+=2;
                patternPosi2+=2;
                break;
            
            default:
                break;
            }
        } 
        if (strPosi >strLen && patternPosi1 >patternLen){
            return true;
        }
        return false; 
    }

    bool isSame(char a,char b){
        if(b=='.' || a ==b){
            return true;
        }
        return false;
    }

     bool match(char* s, char* p)
    {    // 如果 s 和 p 同时为空
        if (*s == '\0' && *p == '\0') return true;
        // 如果 s不为空， 但是 p 为空
        if (*p == '\0') return false;
        // 如果没有 '*'
        if (*(p+1) != '*') {
            if (*s != '\0' && (*s == *p || *p == '.'))
                return match(s+1, p+1);
            else
                return false;
        }
        // 如果有 '*'
        else {
            bool ret = false;
            // 重复 1 次或多次
            if (*s != '\0' && (*s == *p || *p == '.'))
                ret = match(s+1, p);
            // 重复 0 次
            return ret || match(s, p+2);
        }
    }
};

int main(int argc, const char** argv) {
    Solution solution;
    char str[]  ="..ab..abc";
    char patt[] =".*ab";
    std::cout<<solution.match(str,patt);

    return 0;
}