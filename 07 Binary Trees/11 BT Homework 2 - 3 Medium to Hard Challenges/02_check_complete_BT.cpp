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
    int max_hight(TreeNode *current){
        if(!current)
            return 0;
        int left_hight = max_hight(current->left);
        int right_hight = max_hight(current->right);

        return max(left_hight, right_hight) + 1;
    }
    bool is_leaf(TreeNode *current){
        if(!current)
            return true;

        if(!current->left && !current->right)
            return true;
        return false;
    }
    bool is_complete(TreeNode *current, int hight){
        if(is_leaf(current)){
            return hight == 0;
        }
        if(current->right && !current->left)
            return false;
        if(current->left && current->right){
            if(is_leaf(current->left) && !is_leaf(current->right))
                return false;
        }
        bool left_complete = is_complete(current->left, hight -1);
        bool right_complete = is_complete(current->right, hight -1);

        return left_complete && right_complete;

    }
    // Dr code
    bool complete(TreeNode *current){
	queue<TreeNode *> queue_nodes;
	queue_nodes.push(current);
    bool no_more_allowed = false;
	while(!queue_nodes.empty()){
		int sz = queue_nodes.size();
		
		while(sz--){
			TreeNode *curr = queue_nodes.front();
			queue_nodes.pop();
			if(curr->left){
				if(no_more_allowed)
					return false;	
                queue_nodes.push(curr->left);
			}
			else
				no_more_allowed = true;
			if(curr->right){
				if(no_more_allowed)
					return false;
                queue_nodes.push(curr->right);
			}
			else
				no_more_allowed = true;
			
		}
	}
	return true;
}

};


int main(){

BinaryTree myTree(2);
    myTree.add( {3}, {'L'});
    myTree.add({13, 8}, {'R', 'R'});
    myTree.add({13, 7}, {'R', 'L'});
    myTree.print_inorder(myTree.root);
    cout <<"is complete myTree " << myTree.complete(myTree.root) << endl;
   

BinaryTree leet_1(1);
    leet_1.add({2, 4}, {'L', 'L'});
    leet_1.add({2, 5}, {'L', 'R'});
    leet_1.add({3, 6}, {'R', 'R'});
    cout <<"is complete leet_1 "  << leet_1.complete(leet_1.root) << endl;

	 BinaryTree tree(1);
	 tree.add( { 2, 4, 7 }, { 'L', 'L', 'L' });
	 tree.add( { 2, 4, 8 }, { 'L', 'L', 'R' });
	 tree.add( { 2, 5, 9 }, { 'L', 'R', 'R' });
	 tree.add( { 3, 6, 10 }, { 'R', 'R', 'L' });
    cout <<"is complete tree " << tree.complete(tree.root) << endl;

BinaryTree Complete(1);
    Complete.add({2, 4}, {'L', 'L'});
    Complete.add({2, 5}, {'L', 'R'});
    Complete.add({3, 7}, {'R', 'R'});
    Complete.add({3, 6}, {'R', 'L'});
    cout <<"is complete tree Complete " << Complete.complete(Complete.root) << endl;
 
return 0;
}
