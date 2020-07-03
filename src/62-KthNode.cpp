
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
    TreeNode *a; 
    int count = 0;
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {   
        if(pRoot==nullptr || k<1) return nullptr;
        help(pRoot,k);
        return a;
    }

    void help(TreeNode *root,int k){
        if(root == nullptr){
            return;
        }
        count++;
        if(k >count){
            return;
        }
        if(k == count){
            a = root;
        }
        help(root->left,k);
        help(root->right,k);
    }

    
};