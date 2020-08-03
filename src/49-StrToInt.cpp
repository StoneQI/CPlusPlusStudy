
#include "headers.h"

class Solution {
public:
    int StrToInt(std::string str) {
        if(str.size() ==0 ) return 0;
        long long number = 0;
        
        for (int i = str.size() - 1; i >= 0; i--)
        {
            if( str[i] == '+' ){
                if (i==0)
                {
                    return number;
                }else
                {
                    return 0;
                }
            }

            if( str[i] == '-' ){
                if (i==0)
                {
                    return -number;
                }else
                {
                    return 0;
                }
            }

            if( (str[i] < '0') || (str[i] >'9')){
                return 0;
            }else
            {
                int a = str[i]-'0';
                for (size_t j = 0; j < str.size()-1-i; j++)
                {
                    a *= 10;
                }
                number += a;

            }

        }

        return number;
    }


// 链接：https://www.nowcoder.com/questionTerminal/1277c681251b4372bdef344468e4f26e?answerType=1&f=discussion
// 来源：牛客网

// 越界的简单解决方案：让符号位参与运算，并合理利用 INT_MAX/10

// 众所周知，这道题逻辑并不复杂，只是要判断结果是否出界却有点让人手忙脚乱，这里给出以下两种情景的解决方案（若有发现缺漏之处，望及时指出纠正！）：

// 能够处理最小负数：-2147483648
// 判断是否超出最小负数 ~ 最大正数的范围
// 一、关于最小负数：从true、false到 -1、1
// 一般而言，我们习惯性地使用 bool 类型来表示数字是否为负数（标志位 isNegtive），并在计算过程中使用正数来表示中间结果，只有在最后一步才根据标志 isNegtive 将结果取负，这样一样，因为最大正数的绝对值小于最小负数绝对值，所以当值为 INT_MIN 时，将导致结果出错

// 事实上， 只要将正负标志的类型由 bool 类型改成 int 类型，当符号为正时，标志为1，符号为负时，标志为 -1，从而使正负标志位可以参与到运算过程中去，就可以巧妙地解决这一问题，：

// 原先中间值的计算：value = value * 10 + digit;
// 此时中间值的计算：value = value * 10 + isNegtive * digit;
// 如此一来，当数值为负时，中间结果也为负，并执行的是减法操作，就可以取得 -2147483648 的值
// 而当数值为正时，中间结果为正，执行的是加法操作。

// 二、关于数值越界：合理利用 INT_MAX/10
// 数值越界，即大于 2147483647，或小于 -2147483648。通过观察程序结构，我们发现，每次循环时 value 的值都会扩大10倍（乘以10），那么，我们是否就可以利用 INT_MAX/10 的值来提前一步判断是否会越界呢？这里我们以正数的越界为例进行解释：

// 当 value > INT_MAX/10 时，说明本轮扩大10倍后，value 必将越界（超过 INT_MAX）；
// 当 value == INT_MAX/10 时，说明扩大10倍后，value 可能越界，也可能不越界，需要利用当前的加数 digit 来进行进一步的判断：当 digit > 7 时（以正数为例），越界；
// 否则，当 value < INT_MAX/10 时，本轮循环必不越界（扩大10倍后也小于 INT_MAX）；
// 三、将正数、负数的越界判断合并起来：
// 为了保证代码简洁高效，这里我们不得不寻求一种方法，使正数、负数的越界判断可以合并起来进行（同样，这里我们也利用了数值化的正负标记位 isNegtive）：
// 我们设置一个变量 overValue 来表示当前的值和 INT_MAX/10 的差，因为 INT_MAX/10 为正数，所以当当前值为负数时，需要统一转化为正数，故而有：

// overValue = isNegtive*value - INT_MAX/10;
// 这样，当 overValue > 0 时，越界，overValue < 0 时，不越界，而当 overValue == 0 时：
// 正数时（isNegtive == 1），digit > 7 越界，负数时（isNegtive == -1），digit > 8 越界，通过 (isNegtive+1)/2 来将 -1、1转换为0、1，从而使有关 digit 的判断统一转化为：

// 当 (isNegtive+1)/2 + digit > 8 时，数值越界；
// 综上，令：

// overValue = isNegtive*value - INT_MAX/10
//           + (((isNegtive+1)/2 + digit > 8) ? 1:0);
// 则当 overValue > 0 时，数值将会越界，反之，则不会
    int StrToInr( std::string str){

const int length = str.length();
        int isNegtive = 1, overValue = 0;
        int digit = 0, value = 0;

        if (length == 0) return 0;
        else {
            int idx = 0;
            if (str[0] == '-') { isNegtive = -1; idx = 1;}
            else if (str[0] == '+') {idx = 1;}

            for (; idx<length; idx++) {
                digit = str[idx]-'0';
                // overValue表示本轮循环是否会越界
                overValue = isNegtive*value - std::INT_MAX/10
                          + (((isNegtive+1)/2 + digit > 8) ? 1:0);

                if (digit<0 || digit>9) return 0;
                else if (overValue > 0) return 0;

                value = value*10 + isNegtive*digit;
            }
            return value;
        }
    }
};

int main(int argc, const char** argv) {

    Solution solution;
    std::cout << solution.StrToInt("123")<<std::endl;
    return 0;
}