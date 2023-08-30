#include<iostream>
#include<sstream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<climits>
#include<algorithm>
using namespace std;

struct Node {
	int val;
	Node *left;
	Node *right;
	Node() :
			val(0), left(nullptr), right(nullptr) {
	}
	Node(int x) :
			val(x), left(nullptr), right(nullptr) {
	}
	Node(int x, Node *left, Node *right) :
			val(x), left(left), right(right) {
	}
};

class Solution {
public:


	pair<Node*, Node*> treeToDoublyListTraversal(Node* root) {
		if (!root)
			return {nullptr, nullptr};
		//code will be easier if we consider the pari.first is head of sub_tree
		// and pair.last is the tail of sub_tree
		pair<Node*, Node*> left_sub = treeToDoublyListTraversal(root->left);
		pair<Node*, Node*> right_sub = treeToDoublyListTraversal(root->right);

		Node* head = root;	// if no left subtree, then root is the 1st
		Node* tail = root;

		// handle left_sub_tree
		if (left_sub.first) { // connect left last to current root
			//link left_sub.second(tail)->right = root "with root" as tail -> root 
			left_sub.second->right = root;
			//"link" root->left = left_sub.second(tail) tail ⇆ root
			root->left = left_sub.second;
			//"make " head "points to head of left_sub_tree"  = left_sub.first
			head = left_sub.first;
		}
		// handle right_sub_tree
		if (right_sub.first) { // connect root to right first
			//link root->right "with" = right_sub.first "right head" root -> head
			root->right = right_sub.first;
			//"link right head with root" right_sub.first->left "with" = root;  as root ⇆ head
			right_sub.first->left = root;
			//"make" tail "points to tail of right sub_tree"
			tail = right_sub.second;
		}
		// return the head and the tail
		return {head, tail};
	}

	Node* treeToDoublyList(Node* root) {
		if (!root)
			return root;

		pair<Node*, Node*> dll = treeToDoublyListTraversal(root);
		// Make it circular
		dll.first->left = dll.second;
		dll.second->right = dll.first;

		return dll.first;
	}
};

int main() {

	return 0;
}

