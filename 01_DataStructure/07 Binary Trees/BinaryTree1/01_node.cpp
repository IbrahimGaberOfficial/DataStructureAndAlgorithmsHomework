#include <bits\stdc++.h>
using namespace std;

struct Node{
    int val{ };
    Node *left{ };
    Node *right{ };
    Node(int data): val(data){
        // val = data;
    }


};


int main(){

Node *root = new Node(0);
Node *node1 = new Node(1);
Node *node2 = new Node(2);
Node *node3 = new Node(3);
Node *node4 = new Node(4);
Node *node5 = new Node(5);
Node *node6 = new Node(6);
Node *node7 = new Node(7);

//connection
root->left = node1;
root->right = node2;

node1->left = node3;
node1->right = node4;

node2->left = node5;
node2->right = node6;


return 0;
}
