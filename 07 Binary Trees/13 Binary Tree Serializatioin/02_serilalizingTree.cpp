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
    
    string parenthesizing_canonical(TreeNode *current){
        // if(!current)
        //     return "()";
        // string result = "(";
        // vector<string> thor;
        // result += to_string(current->val);

        // thor.push_back(parenthesizing_canonical(current->left));
        // thor.push_back(parenthesizing_canonical(current->right));

        // sort(thor.begin(), thor.end());
        // for(int i = 0; i < thor.size(); i++){
        //     result += thor[i];
        // }
        // result += ")";
        // return result;
        if (!current)
			return "()";

		string repr = "(" + to_string(current->val);

		vector<string> v;

		if (left)
			v.push_back(parenthesizing_canonical(current->left));
		else
			v.push_back("()");

		if (right)
			v.push_back(parenthesizing_canonical(current->right));
		else
			v.push_back("()");

		sort(v.begin(), v.end());
		for (int i = 0; i < (int) v.size(); ++i)
			repr += v[i];

		repr += ")";

		return repr;
	}
    

};


int main(){

BinaryTree myTree(1);
    myTree.add({2, 4}, {'L', 'L'});
    myTree.add({2, 5}, {'L', 'R'});
    myTree.add({3, 6}, {'R', 'R'});
    cout << endl <<"maxDiameter myTree " << myTree.parenthesizing_canonical(myTree.root) ;
   

BinaryTree leet_1(1);
    leet_1.add({3, 6}, {'L', 'L'});
    leet_1.add({2, 4}, {'R', 'R'});
    leet_1.add({2, 5}, {'R', 'L'});
    cout << endl<<"maxDiameter leet_1 " << leet_1.parenthesizing_canonical(leet_1.root) ;

BinaryTree tree(1);
	tree.add({3, 6}, {'L', 'R'});
    tree.add({2, 5}, {'R', 'L'});
    tree.add({2, 4}, {'R', 'R'});
    cout << endl<<"maxDiameter tree   " << tree.parenthesizing_canonical(tree.root);

BinaryTree dublicate(1);
    dublicate.add({2, 3}, {'L', 'L'});
    dublicate.add({4, 5, 6, 8, 9}, {'R', 'R' ,'R', 'R', 'R'});
    dublicate.add({4, 2, 3}, {'R', 'L', 'L'});
    dublicate.add({4, 5, 6, 7}, {'R', 'R', 'R', 'L'});
    dublicate.add({4, 5, 6, 7}, {'R', 'R', 'L', 'L'});
    dublicate.add({4, 5, 6, 8, 9}, {'R', 'R', 'L', 'R', 'R'});
    cout << endl;
    dublicate.print_preOrder(dublicate.root);
    cout << endl << dublicate.parenthesizing_canonical(dublicate.root);




 
return 0;
}
