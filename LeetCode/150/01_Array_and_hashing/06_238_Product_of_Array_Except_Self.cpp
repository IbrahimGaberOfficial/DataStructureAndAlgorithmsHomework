//https://leetcode.com/problems/product-of-array-except-self/description/
#include <bits\stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int numsSize = nums.size();
        vector<int> results(numsSize, 1);

        int prefiex = 1;
        // check if i = 0 or i = 1
        // if the initial value of prefiex = nums[0], then i = 1
        // and if the initial value of prefiex = 1 , then i = 0
        for(int i = 0; i < numsSize; i++){
            results[i] = prefiex;
            prefiex = prefiex * nums[i];
        }
        int postfix = nums[numsSize - 1];
        // check if it numsSize -1 or numsSize - 2
        // if the initial value of postfix = nums[numsSize -1], then i = numsSize -2
        // and if the initial value of postfix = 1 , then i = numsSizew -1
        for(int i = numsSize - 2; i >= 0; i--){
            results[i] *= postfix;
            postfix = postfix * nums[i];
        }
        return results;
    }
};

void test(){
    vector<int> nums = {2, 3, 4, 5};
    Solution mySol;
    nums = mySol.productExceptSelf(nums);
    for(auto x : nums)
        cout << x << " ";
    cout << endl;
}

int main(){

    test();

return 0;
}
