#include <bits\stdc++.h>
using namespace std;
// values range -50000 - 50000;
vector<int> countSortForNegativeValuesV1(vector<int> &nums){
    vector<int> frequency(100001, 0);
    cout << frequency.size() << endl;
    for (int  i = 0; i < nums.size(); i++)
    {
        frequency[nums[i] + 50000]++;
    }
    int j = 0;
    for(int i = 0; i < frequency.size(); i++){
        while(frequency[i]){
            nums[j] = i - 50000;
            j++;
            frequency[i]--;
        }
    }
    return nums;
    
}
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
    // make the maxNum shift by 50000 to handle negative values
    maxNum += 50000;
    vector<int> frequency(maxNum + 1);
    
    for(int i = 0; i < nums.size(); i++){
        frequency[nums[i] + 50000]++;
    }
    int idx = 0;
    for(int i = 0; i < (maxNum + 1); i++){
        while(frequency[i]){
            nums[idx] = i - 50000;
            frequency[i]--;
            idx++;
        }
    }
    
}

int main(){

    vector<int> nums {-5, 2, -3, 1, 1234, -2453};
    countSortForNegativeValuesV2(nums);
    for(auto x : nums){
        cout << x << " ";
    }
    cout << "\nNO RTE.\n";

return 0;
}
