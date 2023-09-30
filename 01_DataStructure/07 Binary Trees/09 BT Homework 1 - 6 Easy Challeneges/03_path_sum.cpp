//code link: https://leetcode.com/problems/path-sum

#include <bits\stdc++.h>
using namespace std;

struct TreeNode{
    int val{ };
    TreeNode *left{ };
    TreeNode *right{ };
    TreeNode(int data): val(data){
        // val = data;
    }


};
struct BinaryTree{
    TreeNode *root;

    BinaryTree(int val) : root(new TreeNode(val)){
        
    }
    void print_inorder(TreeNode *current){
        if(!current)
            return;
        print_inorder(current->left);
        cout << current->val << " ";
        print_inorder(current->right);
                
    }
    void add(vector<int> values, vector<char> directions){
        assert(values.size() == directions.size());
        int size = values.size();
        TreeNode *current = this->root;
        for(int i = 0; i < size; i++){
            if(directions[i] == 'L'){
                if(!current->left){
                    current->left = new TreeNode(values[i]);
                    current = current->left;
                }
                else{
                    assert(current->left->val == values[i]);
                    current = current->left;
                }
            }
            else if(directions[i] == 'R'){
                if(!current->right){
                    current->right = new TreeNode(values[i]);
                    current = current->right;
                }
                else{
                    current = current->right;
                }
            }
        }
        
    }

///////////////////////
    bool is_leaf(TreeNode *current){
        if(!current->left && !current->right)
            return true;
        return false;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(is_leaf(root)){
            if(root->val == targetSum)
                return true;
            return false;
        }
        bool left_sum, right_sum;
        if(root->left)
            left_sum = hasPathSum(root->left, targetSum - root->val);
        if(root->right)
            right_sum = hasPathSum(root->right, targetSum - root->val);

        return (left_sum || right_sum);
        
    }

};


int main(){

BinaryTree myTree(5);
myTree.add({4, 11, 7}, {'L', 'L', 'L'});
myTree.add({4, 11, 2}, {'L', 'L', 'R'});
myTree.add({8, 4, 1}, {'R', 'R', 'R'});
myTree.add({8, 13}, {'R', 'L'});
myTree.print_inorder(myTree.root);
cout << endl;
cout << myTree.hasPathSum(myTree.root, 22);

return 0;
}
