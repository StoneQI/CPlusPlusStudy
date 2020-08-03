

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(nullptr), right(nullptr) {
    }
};

class Solution {
public:
    bool isSymmetrical(TreeNode* pRoot)
    {
        if(pRoot== nullptr) return true;
        return isSame(pRoot->left,pRoot->right);
    }

    bool isSame (TreeNode *left,TreeNode *right){
        if (left == nullptr && right == nullptr)
        {
            return true;
        }
        if (left == nullptr || right == nullptr)
        {
            return false;
        }
        if(left->val != right->val){
                return false;
        }
        return isSame(left->left,right->right) && isSame(left->right,right->left);
    }

};