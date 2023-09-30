#include <bits\stdc++.h>
using namespace std;

void insertionSort(vector<int> &nums){
    
    for(int i = 1; i < nums.size(); i++){
        // start putting the key in temp variable
        int key = nums[i];
        // start the comparison from i - 1
        int j = i - 1;
        // the condittioin have j >= 0 as the equality never go nums[-1] but nums[0]
        while(key < nums[j] && j >= 0){
            // shift right all bigger values
            nums[j + 1] = nums[j];
            j--;
        }
        // now j is less by 1 from the wanted place after breaking 
        // while loop condition
        // os we put the key at nums[j + 1]
        nums[j + 1] = key;
    }
}
void insertionSortDes(vector<int> &nums){
    for(int i = 0; i < nums.size(); i++){
        int key = nums[i];
        int j = i - 1;
        while(j >= 0 && key > nums[j]){
            nums[j + 1] = nums[j];
            j--;
        }
        nums[j + 1] = key;
    }
}

int main(){
vector<int> nums{5, 3, 4, 7, 2, 8, 6, 9, 1};
insertionSortDes(nums);
for(auto x : nums)
    cout << x << " ";


return 0;
}
