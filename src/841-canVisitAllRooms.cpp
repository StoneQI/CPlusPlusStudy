#include "headers.h"

using std::vector;
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>&& rooms) {
        std::map<int,int> degreeIn;
        std::map<int,int> degreeOut;
        if(rooms.size() ==1) return true;
        for (int i = 0; i < rooms.size(); i++)
        {   
            if(!degreeIn.count(i))
                    degreeIn[i]=0;
            degreeOut[i] =0;
            for (int j = 0; j < rooms[i].size(); j++)
            {   
                if( i==rooms[i][j] ) continue;
                degreeOut[i]++;
                if(degreeIn.count(rooms[i][j])){
                    degreeIn[rooms[i][j]]++;
                }else
                {
                    degreeIn[rooms[i][j]] =1;
                }
                
            }
        }
        int count = 0;
        for (size_t i = 0; i < rooms.size(); i++)
        {
            if(degreeOut[i] ==0 && degreeIn[i]==0) return false;
            if(degreeIn[i] == 0) count++;
        }
        return count <2;
    }
};
int main(int argc, const char** argv) {
    Solution sol;
    std::cout<< sol.canVisitAllRooms({{4},{3},{},{2,5,7},{1},{},{8,9},{},{},{6}});
    return 0;
}