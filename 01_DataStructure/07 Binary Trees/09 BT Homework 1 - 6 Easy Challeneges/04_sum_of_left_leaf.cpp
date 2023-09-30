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
    int sumLeftLeaves(TreeNode *current, char direction){
        if(!current || !root)
            return 0;
        int L_sum = 0, R_sum = 0, sum = 0;
        // if(current->left)
            L_sum = sumLeftLeaves(current->left, 'L');

        // if(current->right)
            R_sum = sumLeftLeaves(current->right, 'R');

        if(is_leaf(current) && direction == 'L'){
            sum += current->val;
        }
        sum += (L_sum + R_sum);
        return sum;
        
    }

};


int main(){

BinaryTree myTree(3);
myTree.add({9}, {'L'});
myTree.add({20, 7}, {'R', 'R'});
myTree.add({20, 15}, {'R', 'L'});
myTree.print_inorder(myTree.root);
cout << endl;
cout << myTree.sumLeftLeaves(myTree.root, 'x');

return 0;
}
