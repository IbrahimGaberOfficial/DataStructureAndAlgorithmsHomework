#include <bits\stdc++.h>
using namespace std;

class Solution{
public:
    bool two_sum(vector<int> &nums, int K){
        int numsSize = nums.size();
        unordered_map<int, int> hashTable;
        for(int i = 0; i < numsSize; i++){
            hashTable[nums[i]] = i;
        }
        for(int i = 0; i < numsSize; i++){
            int check = K - nums[i];
            if(hashTable.count(check) && (hashTable[check] != hashTable[nums[i]]))
                return true;
        }
        return false;
    }
    // the solution for the leetcode two sum problem
     vector<int> twoSum(vector<int>& nums, int target) {
        int numsSize = nums.size();
        unordered_map<int, int> hashTable;
        vector<int> theResult;
        for(int i = 0; i < numsSize; i++){
            hashTable[nums[i]] = i;
        }
        for(int i = 0; i < numsSize; i++){
            int check = target - nums[i];
            if(hashTable.count(check) && (hashTable[check] != i)){
                theResult.push_back(i);
                theResult.push_back(hashTable[check]);
                return theResult;
            }
                
        }
        return {0, 0};
        
     }
};

int main(){
    Solution mySol;
    vector<int> nums = {3,3};
    vector<int> theResult;
    cout << mySol.two_sum(nums, 6) << endl;
    theResult = mySol.twoSum(nums, 6);
    for(auto x : theResult)
        cout << x << " ";
    cout << endl;



return 0;
}
