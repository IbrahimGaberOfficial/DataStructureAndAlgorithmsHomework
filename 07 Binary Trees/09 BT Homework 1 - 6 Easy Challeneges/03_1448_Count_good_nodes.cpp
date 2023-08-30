//
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
    
    int calcGoodNodes(TreeNode *current, int maxSoFar){
        if(!current)
            return 0;

       

        int good_left = calcGoodNodes(current->left, max(maxSoFar, current->val));
        int good_right = calcGoodNodes(current->right, max(maxSoFar, current->val));

        // if(current->val >= maxSoFar){
        //     return ;
      
        // }
        return good_left + good_right + (current->val >= maxSoFar) ;
    }
    int goodNodes(TreeNode* root) {
        return calcGoodNodes(root, root->val);
        
    }

};


int main(){

BinaryTree myTree(3);
myTree.add({1, 3}, {'L', 'L'});
myTree.add({4, 5}, {'R', 'R'});
myTree.add({4, 1}, {'R', 'L'});
myTree.print_inorder(myTree.root);
cout << endl;
cout << myTree.goodNodes(myTree.root);

return 0;
}
