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
    BinarySearchTree(){}
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
    ///////////////////////////////////////
    //Vector to Balanced BST
    TreeNode *_SortedArrayToBST(vector<int>&values, int start, int end){
    if(start > end)
        return nullptr;
    int mid = (start + end) /2;
    int turn = values[mid];
    TreeNode *node = new TreeNode(values[mid]);
    node->left = _SortedArrayToBST(values, start, mid - 1);
    node->right = _SortedArrayToBST(values, mid + 1, end);
    return root;
    }
    TreeNode* SortedArrayToBST(vector<int>&nums){
        TreeNode *root = _SortedArrayToBST(nums, 0, nums.size());
        return root;
    }


    


};


void test_arrayToBST(){
    BinarySearchTree myTree;
    vector<int> nums = {8, 5, 1, 7, 10, 12};
    sort(nums.begin(), nums.end());
    // for(auto a : nums)
    //     cout << a << " ";
    myTree.root = myTree.SortedArrayToBST(nums);
    myTree.print_inorder(myTree.root);
}
void test_BT_To_BST(){
    BinaryTree mytree(10);
    mytree.add({2, 4, 3}, {'L', 'L', 'L'});
    mytree.add({2, 5}, {'L', 'R'});
    mytree.add({3, 6, 15}, {'R', 'R', 'R'});
    mytree.print_inorder(mytree.root);
    cout << endl;
    vector<int> nums;
    nums = mytree.BT_to_vector(mytree.root);
    for(int i = 0; i < nums.size(); i++){
        cout << nums[i] << " ";
    }
    cout << endl;
    sort(nums.begin(), nums.end());
    for(int i = 0; i < nums.size(); i++){
        cout << nums[i] << " ";
    }
    cout << endl;
    BinarySearchTree mytreeSorted;
    mytreeSorted.root = mytreeSorted.SortedArrayToBST(nums);
    
    mytree.print_inorder(mytreeSorted.root);
    cout << endl;

}
int main(){

test_arrayToBST();
// test_BT_To_BST();

cout << "\nNO RTE.\n";

return 0;
}