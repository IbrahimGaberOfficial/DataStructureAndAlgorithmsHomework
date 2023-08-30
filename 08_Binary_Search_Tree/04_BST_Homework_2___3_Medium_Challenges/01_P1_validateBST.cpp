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
        // if(!current)
        //     return;
        if(current->left)
            print_inorder(current->left);
        cout << current->val << " ";
        if(current->right)
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
    ////////
    //Convert BT to vector<in> "not sorted"
    void _BT_to_vector(TreeNode *current){
       
        if(current->left){
            (_BT_to_vector(current->left));
        }
        result.push_back(current->val);
        if(current->right){
            (_BT_to_vector(current->right));
        }
    }
     vector<int> result;
    vector<int> BT_to_vector(TreeNode *current){
        _BT_to_vector(current);
        return result;
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
        // if(!current)
        //     return false;
        // if(current->val == traget)
        //     return true;
        // bool found;
        // if(traget < current->val)
        //     found = _search(current->left, traget);
        // else
        //     found = _search(current->right, traget);
        // return found;
        for(int i = 0; current; i++){
            if(!current)
                return false;
            if(traget == current->val){
                cout << endl <<  traget << " was found after " << i << "iterations.";
                return true;
            }
            if(traget < current->val)
                current = current->left;
            else
                current = current->right;
        }
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
    //////////////////////////////////////////
    bool valid = true;
    bool _44IsValid(TreeNode* current, TreeNode *parent, bool is_left){
        IsValidate(current, parent, is_left);
        return valid;
    }
    bool IsValidate(TreeNode* current, TreeNode *parent, bool is_left){
        bool L_valid, R_valid;
        if(is_left && valid){
            L_valid = current->val <= parent->val;
            if(!L_valid)
                valid = false;
        }
        else{
            R_valid = current->val > parent->val;
            if(!R_valid)
                valid = false;
        }
        if(current->left && valid){
            IsValidate(current->left, current, true);
        }
        if(current->right && valid){
            IsValidate(current->right, current, false);
           
        }
    }
    /////////////////////////////
    //Dr's Sol is more elegent than my code :) but I think I it is that same logic that the child 
    //checks -based on he is left or right- if he is less than his father or bigger than his father
    bool isValidBST(TreeNode *current, long long father_min = LONG_LONG_MIN, long long father_max = LONG_LONG_MAX){

        bool status = current->val > father_min && current->val < father_max;
        if(!status)
            return false;
        bool left_valid = !current->left || isValidBST(current->left, father_min, current->val);
        if(!left_valid)
            return false;
        
        bool right_valid = !current->right || isValidBST(current->right, current->val, father_max);
        return right_valid;

    }
    bool find_chain(TreeNode *current, int target, vector<TreeNode*> &ancestors){
        ancestors.push_back(current);
        if(current->val == target)
            return true;
        if(current->left && target < current->val)
            return find_chain(current->left, target, ancestors);
        if(current->right && target > current->val)
            return find_chain(current->right, target, ancestors);
    }
    //get minimum value in BST
    int min_value(TreeNode *current){
        while (current->left && current)
            current = current->left;
        
        return current->val;

        
    }
    TreeNode *get_next(vector<TreeNode*> &ancestors){
        if(!ancestors.size())
            return nullptr;
        TreeNode *node = ancestors.back();
        ancestors.pop_back();
        return node;
    }
    pair<bool, int> getSucessor(TreeNode *current, int target){

        vector<TreeNode*> ancestors;
        //if we did not find the target value in the BST
        if(!find_chain(current, target, ancestors)){
            return make_pair(false, -1);
        }
        TreeNode *child = get_next(ancestors);
        if(child->right){
            return make_pair(true, min_value(child->right));
        }
        TreeNode *parent = ancestors.back();
        ancestors.pop_back();
        //in the while loop condition "parent" must be put before parent->right 
        // as in last parent will be null"check get_next()", so we can not "parent->right" because this will 
        //give us segmentation fault 
        while(parent && parent->right == child ){
            child = parent;
            parent = get_next(ancestors);
        }
        if(parent){
            return make_pair(true, parent->val);
        }
        return make_pair(false, -1);

    }

    


};

void test1(){
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

    cout << endl << "valid mytree : " << myTree.isValidBST(myTree.root) << endl;

 BinaryTree NotValid(10);
    NotValid.add({2, 4, 3}, {'L', 'L', 'L'});
    NotValid.add({2, 5}, {'L', 'R'});
    NotValid.add({3, 6, 15}, {'R', 'R', 'R'});
    NotValid.print_inorder(NotValid.root);
    cout << endl;

    cout << "valid NotValid : " << myTree.isValidBST(NotValid.root) << endl;
}


int main(){



cout << "\nNo RTE.\n";

return 0;
}