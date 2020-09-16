#include "headers.h"

class Solution {
public:
    int countSubstrings(std::string s) {
        if(s.size()<2) return true;
        int count=0;
        for(int  i=0; i <s.size(); i++){
            count++;
            int start = i;
            int end = i;
            while(start>0 && end<s.size()-1 &&  s[--start] == s[++end]) count++;
            start = i;
            end = i+1;
            if(end <s.size() && s[start] == s[end]){
                count++;
                while(start > 0 && end<s.size()-1 &&  s[--start] == s[++end]) count++;
            }
        }

        return count;

    }

};


int main(int argc, char const *argv[])
{
    Solution sol;

    std::cout << sol.countSubstrings("aaa");
    return 0;
}
