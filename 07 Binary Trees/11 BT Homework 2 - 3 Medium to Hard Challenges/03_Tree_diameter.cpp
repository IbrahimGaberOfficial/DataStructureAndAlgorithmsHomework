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
    //////////////////////
    
    //Dr sol
    int max_daimeter_so_far = 0;
    int maxDaimeter(TreeNode *current){
        if(!current){
            return 0;
        }
        int left_diameter = maxDaimeter(current->left);
        int right_diameter = maxDaimeter(current->right);

        max_daimeter_so_far = max(max_daimeter_so_far, (left_diameter + right_diameter));

        return max(left_diameter, right_diameter) + 1;
    }
};


int main(){

BinaryTree myTree(2);
    myTree.add( {3}, {'L'});
    myTree.add({13, 8}, {'R', 'R'});
    myTree.add({13, 7}, {'R', 'L'});
    myTree.print_inorder(myTree.root);
    cout <<"maxDiameter myTree " << myTree.maxDaimeter(myTree.root) << endl;
   

BinaryTree leet_1(1);
    leet_1.add({2, 4}, {'L', 'L'});
    leet_1.add({2, 5}, {'L', 'R'});
    leet_1.add({3, 6}, {'R', 'R'});
    cout <<"maxDiameter leet_1 "  << leet_1.maxDaimeter(leet_1.root) << endl;

	 BinaryTree tree(1);
	 tree.add( { 2, 4, 7 }, { 'L', 'L', 'L' });
	 tree.add( { 2, 4, 8 }, { 'L', 'L', 'R' });
	 tree.add( { 2, 5, 9 }, { 'L', 'R', 'R' });
	 tree.add( { 3, 6, 10 }, { 'R', 'R', 'L' });
    cout <<"maxDiameter tree " << tree.maxDaimeter(tree.root) << endl;

BinaryTree Complete(1);
    Complete.add({2, 4}, {'L', 'L'});
    Complete.add({2, 5}, {'L', 'R'});
    Complete.add({3, 7}, {'R', 'R'});
    Complete.add({3, 6}, {'R', 'L'});
    cout <<"maxDiameter tree Complete " << Complete.maxDaimeter(Complete.root) << endl;
 
return 0;
}
