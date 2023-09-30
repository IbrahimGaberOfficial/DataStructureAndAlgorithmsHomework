#include <bits\stdc++.h>
using namespace std;
struct TreeNode{
    int val { };
    TreeNode *left{ };
    TreeNode *right{ };
    TreeNode(int value) : val(value){}
};

bool _search(TreeNode *current, int target){
    if(!current)
        return false;
    if(current->val == target)
        return true;
    bool found;
    if(target < current->val)
        found = _search(current->left, target);
    else    
        found = _search(current->right, target);
    return found;
}
int main(){



return 0;
}
