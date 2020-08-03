#include "headers.h"

class Solution {
public:
    bool IsContinuous( std::vector<int> numbers ) {
        if(numbers.size() !=5) return false;

        std::set<int> cards;
        int min =14; 
        int max =0;
        for(auto var : numbers)
        {
            if(var > 0 ){
                if(cards.count(var) ==1) return false;
                cards.insert(var);
                max = std::max(var,max);
                min = std::min(var,min);
            }

        }

        
       return max-min <5;
    }
};