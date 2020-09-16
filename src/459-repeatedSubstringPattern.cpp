#include "headers.h"

using namespace std;
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int len = s.size();
        int step=-1;
        for(int i=0; s[i] != s[len-1];i++) step = i;
       if( step ==-1) step =1;
       else step += 2;
        string subPattern = s.substr(0,step);
        if(len % step != 0) return false;
        for (int i = 0; i < len/step; i+=step)
        {
            if(s.substr(i,step) != subPattern){
                return false;
            }
        }
        return true;
    }
};

int main(int argc, const char** argv) {
    Solution sol;
    std::cout << sol.repeatedSubstringPattern("abab") << std::endl;
    return 0;
}