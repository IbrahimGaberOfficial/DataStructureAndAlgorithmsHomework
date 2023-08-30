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
   void zigzag_level_order_(TreeNode *current){
    deque<TreeNode *> nodes_deque;
    bool left_first = true;
    TreeNode *curr ;
    nodes_deque.push_front(current);
    int level = 0;
    while (!nodes_deque.empty()){
        int sz = nodes_deque.size();
        cout << "level " << level << " : ";
        while (sz--)
        {
            if(left_first){
                curr = nodes_deque.front();
                nodes_deque.pop_front();
                cout << curr->val << " ";

                if(curr->left)
                    nodes_deque.push_back(curr->left);
                if(curr->right)
                    nodes_deque.push_back(curr->right);
                
                
            }
            else{
                curr = nodes_deque.back();
                nodes_deque.pop_back();
                cout << curr->val << " ";

                if(curr->right)
                    nodes_deque.push_front(curr->right);
                if(curr->left)
                    nodes_deque.push_front(curr->left);
                
            }
            //if it left frist
            //if it not left first
        }
        cout << endl;
        level++;
        left_first = !left_first;
    }
    

    }


   /////////////////sol as leetcode
   vector<vector<int>> zigzag_level_order(TreeNode *current){
        vector<vector<int>> results;
        deque<TreeNode *> nodes_deque;
        bool left_first = true;
        TreeNode *curr ;
        nodes_deque.push_front(current);
        int level = 0;
        while (!nodes_deque.empty()){
            vector<int> lvl_resuls;

            int sz = nodes_deque.size();
            cout << "level " << level << " : ";
            while (sz--){
                if(left_first){
                    curr = nodes_deque.front();
                    nodes_deque.pop_front();
                    cout << curr->val << " ";

                    if(curr->left)
                        nodes_deque.push_back(curr->left);
                    if(curr->right)
                        nodes_deque.push_back(curr->right);
                    
                    
                }
                else{
                    curr = nodes_deque.back();
                    nodes_deque.pop_back();
                    cout << curr->val << " ";

                    if(curr->right)
                        nodes_deque.push_front(curr->right);
                    if(curr->left)
                        nodes_deque.push_front(curr->left);
                    
                }
                //if it left frist
                //if it not left first
                lvl_resuls.push_back(curr->val);
            }
            cout << endl;
            level++;
            left_first = !left_first;
            results.push_back(lvl_resuls);
        }
        return results;
   }

};


int main(){

BinaryTree myTree(2);
myTree.add( {3}, {'L'});
myTree.add({13, 8}, {'R', 'R'});
myTree.add({13, 7}, {'R', 'L'});
myTree.print_inorder(myTree.root);
cout << endl;

 vector<vector<int>> results = myTree.zigzag_level_order(myTree.root);
// while(!results.empty()){
//     vector<int> internal_lvl = results.back();
//     while(!internal_lvl.empty()){
//         cout << internal_lvl.back() << " ";
//         internal_lvl.pop_back();

//     }
//     results.pop_back();
// }
for (auto  col: results) {
		for (auto row : col)
			cout << row << " ";
		cout << "\n";
	}
return 0;
}
