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
    vector<int> path1, path2;
   void _vectorPath1(TreeNode *current, int target){
        if(!current)
            return;
        path1.push_back(current->val);

        if(target < current->val)
            _vectorPath1(current->left, target);

        if(target > current->val)
            _vectorPath1(current->right, target);
    }

    void _vectorPath2(TreeNode *current, int target){
        if(!current)
            return;
        path2.push_back(current->val);

        if(target < current->val)
            _vectorPath2(current->left, target);

        if(target > current->val)
            _vectorPath2(current->right, target);
    }

    int LowestCommonAnsestorV1(TreeNode *current, int target1, int target2){
        _vectorPath1(current, target1);
        _vectorPath2(current, target2);
        int sz = path1.size();
        int LCA;
        for(int i = 0; i < sz; i++){
            if(path1[i] == path2[i]){
                LCA = path1[i];
                // cout << LCA << " ";
            }
        }
        return LCA;
    }
    int LowestCommonAnsestorV2(TreeNode *current, int target1, int target2){

        if(target1 > current->val && target2 > current->val)
           return  LowestCommonAnsestorV2(current->right, target1, target2);

        if(target1 < current->val && target2 < current->val)    
            return  LowestCommonAnsestorV2(current->left, target1, target2);

        return current->val;
       
    }

    


};

void test1(){
    BinarySearchTree myTree(50);
    myTree.insert(myTree.root, 20);
    myTree.insert(myTree.root, 60);
    
    myTree.insert(myTree.root, 15);
    myTree.insert(myTree.root, 45);
    myTree.insert(myTree.root, 58);
    myTree.insert(myTree.root, 70);
    

    myTree.insert(myTree.root, 16);
    myTree.insert(myTree.root ,35);
    myTree.insert(myTree.root ,73);

    myTree.insert(myTree.root ,36);
    myTree.insert(myTree.root ,75);
  
    // myTree.print_inorder(myTree.root);

    cout << myTree.LowestCommonAnsestorV1(myTree.root, 16, 15) << endl;
    cout << myTree.LowestCommonAnsestorV2(myTree.root, 16, 15) << endl;

  
}
void test2(){
    vector<int> v1 = {1, 2, 3, 4, 5, 6};
    int vector_sz = v1.size();

    for(int i = 0; i < (vector_sz/2); i++){
        swap(v1[i], v1[vector_sz - 1 - i]);
    }
    for(int i = 0; i < vector_sz; i++){
        cout << v1[i] << " ";
    }
    cout << endl;
}
int main(){
test1();
// test2();



cout << "\nNO RTE.\n";

return 0;
}