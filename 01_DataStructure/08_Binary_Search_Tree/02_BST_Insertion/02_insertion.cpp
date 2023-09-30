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
struct BinarySearchTree{
    TreeNode *root;

    BinarySearchTree(int val) : root(new TreeNode(val)){
        
    }
    void print_inorder(TreeNode *current){
        if(!current)
            return;
        print_inorder(current->left);
        cout << current->val << " ";
        print_inorder(current->right);
                
    }
    bool _search(TreeNode *current, int traget){
        if(!current)
            return false;
        if(current->val == traget)
            return true;
        bool found;
        if(traget < current->val)
            found = _search(current->left, traget);
        else
            found = _search(current->right, traget);
        return found;
    }
    void insert(TreeNode *current, int value){
        if(_search(current, value)){
            cout << "\nDublicate not allowed value " << value << " is exsisted.\n";
            return;
        }
       
        if(value < current->val){
            if(!current->left)
                current->left = new TreeNode(value);
            else
                insert(current->left, value);
        }
        else if(value > current->val){
            if(!current->right)
                current->right = new TreeNode(value);
            else 
                insert(current->right, value);
        }


    }
    TreeNode* _insert(TreeNode *current, int value){
        if(_search(current, value)){
            cout << "\nDublicate not allowed value " << value << " is exsisted.\n";
            return nullptr;
        }
        if(!current){
            TreeNode *ptr = new TreeNode(value);
            return (ptr);
        }
        if(value < current->val)
            current->left = _insert(current->left, value);
        else if(value > current->val)
            current->right = _insert(current->right, value);


    }

    


};


int main(){

BinarySearchTree myTree(10);
    myTree.insert(myTree.root, 5);
    myTree.insert(myTree.root, 15);
    myTree.print_inorder(myTree.root);
    cout << endl;
    myTree.insert(myTree.root, 20);
    myTree.insert(myTree.root, 14);
    myTree.insert(myTree.root, 4);
    myTree.insert(myTree.root, 9);
    myTree.print_inorder(myTree.root);

    myTree.insert(myTree.root, 20);
    myTree.insert(myTree.root ,10);
    cout << endl;
    myTree.print_inorder(myTree.root);



return 0;
}