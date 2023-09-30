//two sum problem
#include <bits\stdc++.h>

using namespace std;

pair<int, int> twoSumV1(vector<int> nums, int target){
    for(int i = 0; i < nums.size(); i++){
        for(int j = 0; j < nums.size(); j++){
            if(nums[i] == nums[j])
                continue;
            if(nums[i] + nums[j] == target){
                return make_pair(i, j);
            }
        }
    }
    return make_pair(-1, -1);
}
pair<int, int> twoSumV2(vector<int> nums, int target){
    unordered_map<int, int> hash_table;
    for(int i = 0; i < nums.size(); i++){
        hash_table[nums[i]] = i;
    }
    for(int i = 0; i < nums.size(); i++){
        if(hash_table.count(target - nums[i])){
            return make_pair(i, hash_table[target - nums[i]]);
        }
    }
    return {-1, -1};


}
// there is a solution with binary search, but I did not study binary search yet
// solution using two pointers technique
pair<int, int> twoSumV3(vector<int> nums, int target){
    int vectro_size = nums.size();
    int P1= 0; 
    int P2 = vectro_size - 1;

    for(int i = 0; i < vectro_size; i++){
        if(nums[P1] + nums[P2] > target)
            P2--;
        if(nums[P1] + nums[P2] < target){
            P1++;
        }
        if(nums[P1] + nums[P2] == target)
            return {P1, P2};
    }
    return {-1, -1};


}

int main(){

    vector<int> nums = {-1, 0};
    int target = -;
    pair<int, int> result = twoSumV3(nums, target);
    if(result.first == -1){
        cout << "\n target sum: " << target << " not found.\n";
    }
    else{
        cout << "\ntarget sum: " << target << " is found in index " 
        << result.first << " = " << nums[result.first] << " \nand  in index "
        << result.second << " = " << nums[result.second] << endl;
    }

return 0;
}
