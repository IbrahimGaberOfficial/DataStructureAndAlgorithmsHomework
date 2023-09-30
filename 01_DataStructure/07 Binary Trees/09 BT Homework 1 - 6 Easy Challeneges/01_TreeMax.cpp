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

    int _max(TreeNode* current){
        if(!current)
            return 0;
        int L_max = _max(current->left);
        int R_max =  _max(current->right);
        int me = current->val;
        return max(L_max, max(R_max, me));
    }

};


int main(){

BinaryTree myTree(2);
myTree.add( {3}, {'L'});
myTree.add({13, 8}, {'R', 'R'});
myTree.add({13, 7}, {'R', 'L'});
myTree.print_inorder(myTree.root);
cout << endl;
cout << myTree._max(myTree.root);

return 0;
}
