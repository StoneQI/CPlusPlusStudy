
#include "headers.h"

class Solution {
public:
    std::vector<std::string> restoreIpAddresses(std::string s) {
        std::vector<std::string> ret;
        std::string buf(s.size()+3,'0');
        for (int i = 1; i<s.size() && i <= 3; i++)
        {   
            if( i>1 && s[0] == '0') continue;
            if(std::stoi(s.substr(0,i)) <= 255){
                std::strcpy(&buf[0],s.substr(0,i).c_str());
            }else
            {
                continue;
            }
            
            for (int j = 1; (i+j) <s.size() &&j <= 3; j++)
            {   

                 if( j>1 && s[i] == '0') continue;
                if(std::stoi(s.substr(i,j)) <= 255){
                    buf[i] ='.';
                    std::strcpy(&buf[i+1],s.substr(i,j).c_str());
                }else
                {
                    continue;
                }

                for (int k = 1;  (i+j+k) < (s.size()) && k <= 3; k++)
                {   
                    if( k>1 && s[i+j] == '0') continue;
                    if(std::stoi(s.substr(i+j,k)) <= 255){
                        buf[i+j+1] ='.';
                        std::strcpy(&buf[i+j+2],s.substr(i+j,k).c_str());
                    }else{
                        continue;
                    }
                    int m = s.size()-(i+j+k);
                    if ( m<= 0 || m >3) continue;
                    if( m>1 && s[i+j+k] == '0') continue;
                    if(std::stoi(s.substr(i+j+k,m)) <= 255){
                        buf[i+j+k+2] ='.';
                        std::strcpy(&buf[i+j+k+3],s.substr(i+j+k, m).c_str());
                        ret.emplace_back(buf);
                    }
                }
                
            }
            
        }
        return ret;
        
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;
    sol.restoreIpAddresses("0279245587303");
    return 0;
}
