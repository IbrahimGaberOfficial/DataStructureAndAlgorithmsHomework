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
        while (current && current->left)
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
        bool found = false;
        found = find_chain(current, target, ancestors);
        if(!found){
            return make_pair(false, -1);
        }
        TreeNode *child = get_next(ancestors);
        if(child->right){
            return make_pair(true, min_value(child->right));
        }
        TreeNode *parent = get_next(ancestors);
        
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

    //////////////////////////////
    //delete node
    	TreeNode* min_node(TreeNode* cur) {
		while (cur && cur->left)
			cur = cur->left;
		return cur;
	}

	// Delete the target node in the tree and return updated tree
	// Caller use updated tree to re-link with children!

    TreeNode* _delete_node(TreeNode* root, int target) {
        if (!root)
            return nullptr;
        if (target < root->val)
            root->left = _delete_node(root->left, target);
        else if (target > root->val)
            root->right = _delete_node(root->right, target);
        else {	// Found the root: Handle deletion
            TreeNode* tmp = root;

            if (!root->left && !root->right)	// case 1: no child
                root = nullptr;
            else if (!root->right) 				// case 2: has left only
                root = root->left;					// connect with child
            else if (!root->left)				// case 2: has right only
                root = root->right;
            else {								// 2 children: Use successor
                TreeNode* mn = min_node(root->right);
                root->val = mn->val;	// copy & go delete
                root->right = _delete_node(root->right, root->val);
                tmp = nullptr;	// Don't delete me. Successor will be deleted
            }
            if (tmp)
                delete tmp;
        }
        return root;
    }

	void delete_node(int target) {
		root = _deleteNode(root, target);
	}
    //
    TreeNode *_deleteNode(TreeNode *current, int target){
        //search for the wanted target
        if(!root)
            return nullptr;
        else if(target < current->val)
            current->left = _deleteNode(current->left, target);
        else if(target > current->val)
            current->right = _deleteNode(current->right, target);
        else{
            TreeNode *tmp = current;
            if(!current->left && !current->right)
                current = nullptr;
            else if(!current->left)
                current = current->right;
            else if(!current->right)
                current = current->left;
            else{
                TreeNode* mn = min_node(current->right);
                current->val = mn->val;
                current->right = _deleteNode(current->right, current->val);
                tmp = nullptr;
            }
            if(tmp)
                delete tmp;
        }
        return current;
    }



    


};

void test_node_have_2children(){
    BinarySearchTree myTree(50);
    {
    myTree.insert(myTree.root, 20);
    myTree.insert(myTree.root, 60);
    myTree.insert(myTree.root, 15);
    myTree.insert(myTree.root, 45);
    myTree.insert(myTree.root, 58);
    myTree.insert(myTree.root, 70);
    myTree.insert(myTree.root, 16);
    myTree.insert(myTree.root, 35);
    myTree.insert(myTree.root, 73);
    myTree.insert(myTree.root, 36);
    myTree.insert(myTree.root, 75);
    }
    myTree.print_inorder(myTree.root);
    cout << "\n";
    myTree.delete_node(20);
    myTree.print_inorder(myTree.root);
}
void test_node_have_1child(){
    BinarySearchTree myTree(50);
   {
    myTree.insert(myTree.root, 20);
    myTree.insert(myTree.root, 60);
    myTree.insert(myTree.root, 15);
    myTree.insert(myTree.root, 45);
    myTree.insert(myTree.root, 58);
    myTree.insert(myTree.root, 70);
    myTree.insert(myTree.root, 16);
    myTree.insert(myTree.root, 35);
    myTree.insert(myTree.root, 73);
    myTree.insert(myTree.root, 36);
    myTree.insert(myTree.root, 75);
    }
    myTree.print_inorder(myTree.root);
    cout << "\n";
    myTree.delete_node(73);
    myTree.print_inorder(myTree.root);
}

void test_node_have_0children(){
    BinarySearchTree myTree(50);
   {
    myTree.insert(myTree.root, 20);
    myTree.insert(myTree.root, 60);
    myTree.insert(myTree.root, 15);
    myTree.insert(myTree.root, 45);
    myTree.insert(myTree.root, 58);
    myTree.insert(myTree.root, 70);
    myTree.insert(myTree.root, 16);
    myTree.insert(myTree.root, 35);
    myTree.insert(myTree.root, 73);
    myTree.insert(myTree.root, 36);
    myTree.insert(myTree.root, 75);
    }
    myTree.print_inorder(myTree.root);
    cout << "\n";
    myTree.delete_node(75);
    myTree.print_inorder(myTree.root);
}


int main(){


// test_node_have_0children();
// test_node_have_1child();
test_node_have_2children();

cout << "\nNo RTE.\n";

return 0;
}