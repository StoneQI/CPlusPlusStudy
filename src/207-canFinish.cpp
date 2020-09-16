#include "headers.h"
class Solution {
public:
    bool canFinish(int numCourses, const std::vector<std::vector<int>>& prerequisites) {
         if(prerequisites.size() == 0 ) return true;
        if (prerequisites.size() == 1 && numCourses >=1) return true;
        std::map<int,int> in_Num;
        for(int i =0; i < prerequisites.size();i++){
            if(!in_Num.count(prerequisites[i][0])){
                in_Num[prerequisites[i][0]] = 0;
            }
            if(in_Num.count(prerequisites[i][1])){
                in_Num[prerequisites[i][1]] +=1;
            }else{
                in_Num[prerequisites[i][1]] = 1;
            }
        }
        int count = 0;

        for(auto item = in_Num.begin(); item != in_Num.end();){
            if( item->second != 0) {
                item++;
                continue;
            }
            for(auto &item2:prerequisites){
                if(item2[0] == item->first){
                    in_Num[item2[1]] -= 1;
                }
            }
            in_Num[item->first] = -1;
            count++;
            item = in_Num.begin();
        }
        return count!=0 && count== in_Num.size() && count <= numCourses;
    }

};

int main(int argc, char const *argv[])
{
    Solution sol;
    std::cout << sol.canFinish(3,{{1,0},{2,0}});
    return 0;
}
