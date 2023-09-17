#include <iostream>
#include <cassert>
#include <queue>
using namespace std;

// this is my solution
class AVLTree {
private:
	struct BinaryNode {
		int data { };
		int height { };
        int taskPriority{};
		BinaryNode* left { };
		BinaryNode* right { };

		BinaryNode(int data, int taskPriority) :
				data(data), taskPriority(taskPriority) {
		}

		int ch_height(BinaryNode* node) {	// child height
			if (!node)
				return -1;			// -1 for null
			return node->height;	// 0 for leaf
		}
		int update_height() {	// call in end of insert function
			return height = 1 + max(ch_height(left), ch_height(right));
		}
		int balance_factor() {
			return ch_height(left) - ch_height(right);
		}
	};

	BinaryNode *root { };
    pair<int, int> main_priority{ };
    // int nextMainPriority{ };

	///////////////////////////
	pair<bool, BinaryNode*> search(int target, BinaryNode* node) {
		if(!node)
			return make_pair(false, nullptr);

		if (target == node->data)
			return make_pair(true, node);

		if (target < node->data)
			return search(target, node->left);

		return search(target, node->right);
	}

	BinaryNode* right_rotation(BinaryNode* Q) {
		cout << "right_rotation " << Q->data << "\n";
		BinaryNode* P = Q->left;
		Q->left = P->right;
		P->right = Q;
		Q->update_height();
		P->update_height();
		return P;
	}

	BinaryNode* left_rotation(BinaryNode* P) {
		cout << "left_rotation " << P->data << "\n";
		BinaryNode* Q = P->right;
		P->right = Q->left;
		Q->left = P;
		P->update_height();
		Q->update_height();
		return Q;
	}

	BinaryNode* balance(BinaryNode* node) {
		if (node->balance_factor() == 2) { 			// Left
			if (node->left->balance_factor() == -1)	// Left Right?
				node->left = left_rotation(node->left);	// To Left Left

			node = right_rotation(node);	// Balance Left Left
		} else if (node->balance_factor() == -2) {
			if (node->right->balance_factor() == 1)
				node->right = right_rotation(node->right);

			node = left_rotation(node);
		}
		return node;
	}

	BinaryNode* insert_node(int target, int taskPriority, BinaryNode* node) {
		if (target < node->data) {
			if (!node->left)
				node->left = new BinaryNode(target, taskPriority);
			else	// change left. update left as it might be balanced
				node->left = insert_node(target, taskPriority, node->left);
		} else if (target > node->data) {
			if (!node->right)
				node->right = new BinaryNode(target, taskPriority);
			else
				node->right = insert_node(target, taskPriority, node->right);
		}
		node->update_height();
		return balance(node);
	}

	BinaryNode* min_node(BinaryNode* cur) {
		while (cur && cur->left)
			cur = cur->left;
		return cur;
	}

	BinaryNode* delete_node(int target, BinaryNode* node) {
		if (!node)
			return nullptr;

		if (target < node->data)
			node->left = delete_node(target, node->left);
		else if (target > node->data)
			node->right = delete_node(target, node->right);
		else {
			BinaryNode* tmp = node;

			if (!node->left && !node->right)	// case 1: no child
				node = nullptr;
			else if (!node->right) 	// case 2: has left only
				node = node->left;		// connect with child
			else if (!node->left)	// case 2: has right only
				node = node->right;
			else {	// 2 children: Use successor
				BinaryNode* mn = min_node(node->right);
				node->data = mn->data;	// copy & go delete
				node->right = delete_node(node->data, node->right);
				tmp = nullptr;	// Don't delete me. Successor will be deleted
			}
			if (tmp)
				delete tmp;
		}
		if (node) {
			node->update_height();
			node = balance(node);
		}
		return node;
	}

	bool is_bst(BinaryNode* node) {
		bool left_bst = !node->left || node->data > node->left->data && is_bst(node->left);

		if (!left_bst)
			return false;

		bool right_bst = !node->right || node->data < node->right->data && is_bst(node->right);
		return right_bst;
	}

    void verify() {
        if(!root)
            return;
        assert(abs(root->balance_factor()) <= 1);
        assert(is_bst(root));
    }

	void print_inorder(BinaryNode* node) {
		if(!node)
			return;

		print_inorder(node->left);
		cout << node->data << " ";
		print_inorder(node->right);
	}


public:
	void enqueue(int target, int taskPriority) {
		if (!root)
			root = new BinaryNode(target, taskPriority);
		else{
			root = insert_node(target, taskPriority, root);
            // main_priority = max(main_priority, taskPriority);
        }

		verify();
	}

	int dequeue() {
		if (root) {
            main_priority = make_pair(0, 0);
            maximum_priority(root);
            // nextMainPriority = 0;
            // target is the task_id is the key
           
			root = delete_node(main_priority.first, root);
			verify();
            return main_priority.first;
		}
        return 0;
	}

	pair<bool, BinaryNode*> search(int target) {
		return search(target, root);
	}

	void print_inorder() {
		print_inorder(root);
	}

	void level_order_traversal() {
		if (!root)
			return;

		cout << "******************\n";
		queue<BinaryNode*> nodes_queue;
		nodes_queue.push(root);

		int level = 0;
		while (!nodes_queue.empty()) {
			int sz = nodes_queue.size();

			cout << "Level " << level << ": ";
			while (sz--) {
				BinaryNode*cur = nodes_queue.front();
				nodes_queue.pop();

				cout << cur->data << " ";
				if (cur->left)
					nodes_queue.push(cur->left);
				if (cur->right)
					nodes_queue.push(cur->right);
			}
			level++;
			cout << "\n";
		}
	}

    /////////////////////////////////
    // implement priority queue in alv
    // get maximum priority
    void maximum_priority(BinaryNode* node){
        if(!node)
            return;
        if(node->taskPriority >= main_priority.second){
            // nextMainPriority = main_priority;
            main_priority.first = node->data;
            main_priority.second = node->taskPriority;

        }
        if(node->left)
            maximum_priority(node->left);
        if(node->right)
            maximum_priority(node->right);
    }

};




int main() {

    AVLTree Tasks;
    Tasks.enqueue(1131, 1);
    Tasks.enqueue(3111, 3);
    Tasks.enqueue(2211, 2);
    Tasks.enqueue(3161, 3);
    Tasks.enqueue(7761, 7);

    cout << Tasks.dequeue() << endl;
    cout << Tasks.dequeue() << endl;
    cout << Tasks.dequeue() << endl;
    cout << Tasks.dequeue() << endl;
    cout << Tasks.dequeue() << endl;
	cout << "\nbye\n";

	return 0;
}




