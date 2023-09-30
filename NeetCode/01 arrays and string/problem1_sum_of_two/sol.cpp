#include <iostream>
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        for(int i = 0; i < nums.size(); i++){
            int sum = nums[i];
            for(int j = 0; j < nums.size(); j++){
                if(j == i)
                    continue;
                if(sum + nums[j] == target){
                    result.push_back(i);
                    result.push_back(j);
                    return result;
                }
                    
            }
        }

    }
};


int main(){

    vector<int> nums = {3,3}, result; 
    int target = 6;
    Solution sol;
    result = sol.twoSum(nums, target);
    cout << "[";
    bool is_first = true;
    for (int  i = 0; i < result.size(); i++)
    {
        if(!is_first){
            cout << ",";
        }
        cout << result[i];
        is_first = false;
        
    }
     cout << "]";
    
    
    return 0;
}