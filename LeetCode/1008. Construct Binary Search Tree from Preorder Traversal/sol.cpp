// https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/

#include <iostream>
#include <cassert>
#include <vector>
#include<algorithm>
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
	int val { };
	TreeNode* left { };
	TreeNode* right { };
	TreeNode(int val) : val(val) { }
};


class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
    	return sortedArrayToBST(nums, 0, (int) nums.size() - 1);
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        sort(preorder.begin(), preorder.end());
        return sortedArrayToBST(preorder, 0, (int)preorder.size() -1);
    }

    TreeNode* sortedArrayToBST(vector<int>& values, int start, int end) {
    	if (start > end)
    		return nullptr;

    	// The best root for N sorted numbers is their middle number
    	// as N/2 numbers before and after. Keep applying recursively
    	int mid = (start + end) / 2;
    	TreeNode *root = new TreeNode(values[mid]);
    	root->left = sortedArrayToBST(values, start, mid - 1);
    	root->right = sortedArrayToBST(values, mid + 1, end);

    	return root;
    }
};


int main() {
    vector<int> v{ 1, 5, 8, 9, 6, 7, 3, 4, 2, 0 };
  
    sort(v.begin(), v.end());
  
    cout << "Sorted \n";
    for (auto x : v)
        cout << x << " ";
	return 0;
}
