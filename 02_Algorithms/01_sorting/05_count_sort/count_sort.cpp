#include <bits\stdc++.h>
using namespace std;

void countSort(vector<int> &nums){
    vector<int> result;
    int max_value = 0;
    // get max value
    for(int i = 0; i < nums.size(); i++){
        if(max_value < nums[i])
            max_value = nums[i];
    }
    // frequency size must be max_value 1 to avoid segmentatin fault
    // wheh access frequency[max_value]
    vector<int> freqency(max_value + 1);
    for(int i = 0; i < nums.size(); i++){
        freqency[nums[i]]++;
    }
    for(int i = 0; i < max_value; i++){
        while(freqency[i]--){
            result.push_back(i);
        }
    }

    swap(result, nums);
}

int main(){

    vector<int> nums = {9, 3, 10, 9, 5, 3, 90, 9};
    countSort(nums);
    for(auto x : nums){
        cout << x << " ";
    }
    cout << "\nNo RTE.\n";

return 0;
}
