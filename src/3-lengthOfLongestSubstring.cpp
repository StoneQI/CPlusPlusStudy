#include "headers.h"
class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        std::unordered_set<char> occ;
        unsigned len = s.size();
        if(s.size() <2) return s.size();

        int rk = -1,ans =0;
        for (int i = 0; i < len; i++)
        {
            if(i != 0){
                occ.erase(s[i-1]);
            }
            while (rk+1 <len && !occ.count(s[rk+1]))
            {
                occ.insert(s[rk+1]);
                ++rk;
            }
            ans = std::max(ans,rk-i+1);
            
        }
        return ans;
    
    }
};
int main(int argc, char const *argv[])
{
    Solution sol;
    std::cout << sol.lengthOfLongestSubstring("abba");
    return 0;
}
