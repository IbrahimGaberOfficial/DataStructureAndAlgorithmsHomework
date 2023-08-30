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

    void level_order_traversal(TreeNode *current){
        queue<TreeNode*> myQueue;
        myQueue.push(current);
        while(!myQueue.empty()){
            TreeNode *curr = myQueue.front();
            myQueue.pop();
            cout << curr->val << " ";
            if(curr->left)
                myQueue.push(curr->left);
            if(curr->right)
                myQueue.push(curr->right);
            
        }
        cout << endl;
    }
    void level_order_traversalV2(TreeNode *current){
        queue<TreeNode*> nodes_queue;
        nodes_queue.push(current);

        int level = 0;
        while (!nodes_queue.empty()){
            cout << "level " << level << " : ";
            int sz = nodes_queue.size();
            while (sz--)
            {
                TreeNode *curr = nodes_queue.front();
                nodes_queue.pop();
                cout << curr->val << " ";
                if(curr->left)
                    nodes_queue.push(curr->left);
                if(curr->right)
                    nodes_queue.push(curr->right);

            }
            cout << endl;
            level++;
            
        }
        
    }
};


int main(){

BinaryTree myTree(2);
myTree.add( {3}, {'L'});
myTree.add({13, 8}, {'R', 'R'});
myTree.add({13, 7}, {'R', 'L'});
myTree.print_inorder(myTree.root);
cout << endl;
myTree.level_order_traversal(myTree.root);
cout << endl;
myTree.level_order_traversalV2(myTree.root);

return 0;
}
