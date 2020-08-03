
#include "headers.h"

class Solution {
public:
    int GetNumberOfK(std::vector<int> data ,int k) {

        int lbound = 0, rbound = 0;
        // 寻找下界
        int l = 0, r = data.size(); //注意设为size
        while (l < r) {
            int mid = l + (r - l) / 2; //不用（r+l）/2防止加法越界。
            if (data[mid] < k) {
                l = mid + 1;
            }
            else {
                r = mid;
            }
        }
        lbound = l;
        // 寻找上界
        l = 0, r = data.size();  //注意设为size，处理最后一个元素的上界
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (data[mid] <= k) {
                l = mid + 1;
            }
            else {
                r = mid;
            }
        }
        rbound = l;
        return rbound - lbound;

        
        
    }
};

int main(int argc, const char** argv) {
    Solution solution;
    std::cout << solution.GetNumberOfK({1,1,2,2,3,4},4) << std::endl;
    return 0;
}