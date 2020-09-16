#include "headers.h"

class Solution {
public:
    int search(std::vector<int> nums, int target) {
        int start = 0;
        int end = nums.size()-1;
        while (end>start){
            // 注意判断条件
            // if(end-start <=1) return min(nums[end],nums[start]);

            int mid = start +(end-start)/2;
            if(nums[mid] == target) return mid;
            if(nums[end] == target) return end;
            if(nums[start] == target) return start;
            if(nums[mid] < nums[end] ){
                if(target > nums[mid] && target < nums[end])
                    start = mid+1;
                else
                    end = mid-1;
            }else{
                if(target < nums[mid] && target > nums[start])
                    end=mid-1;
                else
                    start = mid+1;
            }

        }
        return -1;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;

    std::cout << sol.search({4,5,6,7,0,1,2},3) << std::endl;
    return 0;
}
