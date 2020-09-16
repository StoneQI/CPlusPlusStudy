#include "headers.h"

using std::vector;
using std::string;
class Solution {
public:
    vector<string> findItinerary(vector<vector<string>> && tickets) {
        std::sort(tickets.begin(),tickets.end(),[](const vector<string> &a1,const vector<string> &a2)->bool{
            for (size_t i = 0; i < 3; i++)
            {
                if(a1[1][i] > a2[1][i]){
                    return false;
                }
                if(a1[1][i] < a2[1][i]){
                    return true;
                }
            }
            return false;
        });
        
        std::set<string> result;
        string start = "JFK";
        result.emplace(start);
        bool flag = true;
        while(flag){
            bool isfind = false;
            for (const auto &item: tickets)
            {
                if(item[0] == start){
                    if(result.count(item[1]) == 0){
                        result.emplace(item[1]);
                        start = item[1];
                        isfind =true;
                        break;
                    }
                }
            }
            if(isfind ==false)
                flag = false;
        }
        int a=0;
        return vector<string>(result.begin(),result.end());

    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    sol.findItinerary({{"JFK","SFO"},{"JFK","ATL"},{"SFO","ATL"},{"ATL","JFK"},{"ATL","SFO"}});
    return 0;
}
