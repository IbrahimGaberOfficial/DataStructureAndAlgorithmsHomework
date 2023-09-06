#include <bits\stdc++.h>
using namespace std;

class AVLTree{
private:
    struct BinaryNode
    {
        int data{ };
        // default value for height is 0
        int height{ };
        BinaryNode* left{ };
        BinaryNode* right{ };

        BinaryNode(int data) : data(data){

        }
        int ch_height(BinaryNode* node){
            if(!node)
                return -1;
            return node->height;
        }
        int update_height(){
            height = 1 + max(ch_height(left), ch_height(right));
            return height;
        }
        int balance_factor(){
            return ch_height(left) - ch_height(right);
        }

    };
    BinaryNode* root{ };
    
    BinaryNode* right_rotation(BinaryNode* Q){
        cout << "right rotation : " << Q->data << "\n";
        BinaryNode* P = Q->left;
        Q->left = P->right;
        P->right = Q;
        Q->update_height();
        P->update_height();
        return P;
    }
    BinaryNode* left_rotation(BinaryNode* P){
        BinaryNode* Q = P->right;
        P->right = Q->left;
        Q->left = P;

        P->update_height();
        Q->update_height();
        return Q;
    }
    BinaryNode* balance(BinaryNode* node){
        if(node->balance_factor() == -2){
            if(node->right->balance_factor() == 1) 
                node->right = right_rotation(node->left);
            node = left_rotation(node);
        }
        else if(node->balance_factor() == 2){
            if(node->left->balance_factor() == -1) // LR case
                node->left = left_rotation(node->left);
            node = right_rotation(node->right);
        }
        return node;
    }
    BinaryNode* insert_node(int target, BinaryNode* node){
        if(!node)
            return nullptr;
        if(target < node->data){
            if(!node->left)
                node->left = new BinaryNode(target);
            else
                node->left = insert_node(target, node->left);
        }
        else if(target > node->data){
            if(!node->right)
                node->right = new BinaryNode(target);
            else
                node->right = insert_node(target, node->right);
        }
        node->update_height();
        node = balance(node);
         // check may problem here
        return node;
    }

    void print_inorder(BinaryNode* node){
        if(!node)
            return;
        print_inorder(node->left);
        cout << node->data << " ";
        print_inorder(node->right);
    }

public:
    void print_inorder(){
        print_inorder(root);
    }
        // insert caller
    void insert_value(int target){
        if(!root)
            root = new BinaryNode(target);
        else
            root = insert_node(target, root);
    }
    
};

void AVL_test(){
    AVLTree* myAVL = new AVLTree;
    vector<int> values = {3, 5, 9, 1, 0, 2, 6, 10, 7, 4, 8};
    for(int i = 0; i < values.size(); i++){
        myAVL->insert_value (values[i]);
        myAVL->print_inorder();
        cout << "\n NO RTE \n";

    }

}
int main(){
 
AVL_test();


return 0;
}
