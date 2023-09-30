#include <bits\stdc++.h>
using namespace std;

void test_normal(){
    vector<int> nums = {9, 2, 10, 0, 5, 3, 90, 85};
    sort(nums.begin(), nums.end());
    for(auto x : nums)
        cout << x << " ";
}
bool compare_right(int a, int b){
    return a < b;
}
bool compare_wrong(int a, int b){
    return a <= b;
}
void test_for_many_values(){
    vector<int> nums(10000000, 5);
    // for(int i = 10000000; i >= 0; i--){
    //     nums.push_back(i);
    // }
    sort(nums.begin(), nums.end(), compare_right);
    // for(auto x : nums)
    //     cout << x << " ";
}
int main(){

    test_for_many_values();
    cout << "\nNo RTE.\n";

return 0;
}
