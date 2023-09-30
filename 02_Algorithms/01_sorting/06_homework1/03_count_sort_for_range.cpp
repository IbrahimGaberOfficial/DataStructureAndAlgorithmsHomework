#include <bits\stdc++.h>
using namespace std;

void countSortForNegativeValuesV2(vector<int> &nums){
    // get the max value in the vector
    int maxNum = nums[0];
    int minNum = nums[0];
    for(int i = 1; i < nums.size(); i++){
        if(maxNum < nums[i])
            maxNum = nums[i];
        else if( minNum > nums[i])
            minNum = nums[i];
    }
    int suitable_size = abs(maxNum - minNum);

    // make the maxNum shift by 50000 to handle negative values

    vector<int> frequency(suitable_size + 1);
    
    for(int i = 0; i < nums.size(); i++){
        int x = nums[i] - minNum;
        frequency[x]++;
    }
    int idx = 0;
    for(int i = 0; i < (suitable_size + 1); i++){
        while(frequency[i]){
            nums[idx] = i +minNum;
            frequency[i]--;
            idx++;
        }
    }
    
}

int main(){

    vector<int> nums {10000107,10000035,10000001};
    countSortForNegativeValuesV2(nums);
    for(auto x : nums){
        cout << x << " ";
    }
    cout << "\nNO RTE.\n";

return 0;
}