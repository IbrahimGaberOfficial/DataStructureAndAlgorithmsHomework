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
    //mySol
    bool is_prefect(TreeNode *current){
        if(!current)
            return false; //check problem here

        bool left_prefect = false, right_prefect = false;

        if(current->left)
            left_prefect = is_prefect(current->left);
        if(current->right)
            right_prefect = is_prefect(current->right);

        if(is_leaf(current))
            return true;
        if(current->left && !current->right || !current->left && current->right)
            return false;
        
        else if(is_leaf(current->left) && is_leaf(current->right)){
            return true;
        }
        return left_prefect && right_prefect;

    }
    //Dr.Code
    //based on that when we reach to child the hight for it will be zero for all childs on last level 
    //other that it will be not prefect tree
    int max_depth(TreeNode *current){
        if(!current)
            return 0;
        int Left_depth = max_depth(current->left);
        int right_depth = max_depth(current->right);

        return max(Left_depth , right_depth) + 1;
    }
    bool is_prefect(TreeNode *current, int hight){
        if(is_leaf(current))
            return hight == 0;
        
        if(!current->left && current->right || current->left && !current->right)
            return false;
        
        bool left_prefect = is_prefect(current->left, hight - 1);
        bool right_prefect = is_prefect(current->right, hight - 1);

        return left_prefect && right_prefect;

    }
    bool isPrefect(TreeNode *current){
        return is_prefect(current, max_depth(current) - 1);
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
cout << myTree.is_prefect(myTree.root) << endl;
cout << "max depth " << myTree.max_depth(myTree.root) << endl;
cout << "is prefect of dr ." << myTree.isPrefect(myTree.root) << endl;

BinaryTree Leet(2);
    Leet.add({3, 5}, {'L', 'L'});
    Leet.add({3, 6}, {'L', 'R'});
    Leet.add({13, 8}, {'R', 'R'});
    Leet.add({13, 7}, {'R', 'L'});
    Leet.print_inorder(Leet.root);
    cout << endl;
    cout << Leet.is_prefect(Leet.root) << endl;
    cout << "is prefect of dr ." << Leet.isPrefect(Leet.root) << endl;


return 0;
}
