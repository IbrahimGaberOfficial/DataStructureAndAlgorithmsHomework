#include <bits\stdc++.h>
using namespace std;


struct Node{
    char val{ };
    Node *left{ };
    Node *right{ };
    Node(char data): val(data){
        // val = data;
    }


};
void print_inorder(Node root){
    cout << root.left->val << " ";
    cout << root.val << " ";
    cout << root.right->val << " \n";
}

int main(){

//create nodes staticlly 
Node root('+');

Node node2('2');

Node node3('3');

root.left = &node2;
root.right = &node3;

print_inorder(root);

return 0;
}
