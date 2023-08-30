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
    void print_preOrder(TreeNode *current){
        if(!current)
            return;
        cout << current->val << " ";
        print_preOrder(current->left);
        print_preOrder(current->right);
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
    //////////////////////
    
    void print_preOrder_complete(TreeNode *current){
        if(!current){
            cout << "-1, ";
            return;
        }
        cout << current->val << ", ";
        print_preOrder_complete(current->left);
        
        print_preOrder_complete(current->right);
    }
};


int main(){

BinaryTree myTree(2);
    myTree.add( {3}, {'L'});
    myTree.add({13, 8}, {'R', 'R'});
    myTree.add({13, 7}, {'R', 'L'});
    myTree.print_preOrder(myTree.root);
    cout << endl <<"maxDiameter myTree "; myTree.print_preOrder_complete(myTree.root) ;
   

BinaryTree leet_1(1);
    leet_1.add({2, 4}, {'L', 'L'});
    leet_1.add({2, 5}, {'L', 'R'});
    leet_1.add({3, 6}, {'R', 'R'});
    cout << endl<<"maxDiameter leet_1 " ; leet_1.print_preOrder_complete(leet_1.root) ;

	 BinaryTree tree(1);
	 tree.add( { 2, 4, 7 }, { 'L', 'L', 'L' });
	 tree.add( { 2, 4, 8 }, { 'L', 'L', 'R' });
	 tree.add( { 2, 5, 9 }, { 'L', 'R', 'R' });
	 tree.add( { 3, 6, 10 }, { 'R', 'R', 'L' });
    cout << endl<<"maxDiameter tree " ; tree.print_preOrder_complete(tree.root);

BinaryTree Complete(1);
    Complete.add({2, 4}, {'L', 'L'});
    Complete.add({2, 5}, {'L', 'R'});
    Complete.add({3, 7}, {'R', 'R'});
    Complete.add({3, 6}, {'R', 'L'});
    cout  << endl <<"maxDiameter tree Complete " ; Complete.print_preOrder_complete(Complete.root) ;

BinaryTree pdf(1);
    pdf.add({2}, {'L'});
    pdf.add({3}, {'R'});
    cout << endl;
    pdf.print_preOrder(pdf.root);
    cout << endl;
    pdf.print_preOrder_complete(pdf.root);
 
return 0;
}
