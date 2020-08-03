#include "headers.h"

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

class Solution {
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
        if(pRoot == nullptr) return true;
        int left = IsBalanced(pRoot->left);
        int rigft = IsBalanced(pRoot->right);
        if(left==-1 || rigft == -1) return false;
        if(abs(left-rigft)<=1 ){
            return true;
        } else if (abs(left-rigft)>1)
        {
           return false;
        }
    }
    int IsBalanced(TreeNode *pRoot){
        if(pRoot == nullptr) return 0;
        int left = IsBalanced(pRoot->left);
        int rigft = IsBalanced(pRoot->right);
        if(left==-1 || rigft == -1) return -1;
        if(abs(left-rigft)<=1 ){
            return std::max(left,rigft)+1;
        } else if (abs(left-rigft)>1)
        {
           return -1;
        }
        
    }
};