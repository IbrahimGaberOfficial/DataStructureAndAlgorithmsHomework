#include <bits\stdc++.h>
using namespace std;

void selection_sort(vector<int> &arr){
    for(int i = 0; i < arr.size(); i++){
        int tmp = i;
        for(int j = i ; j < arr.size(); j++){
            if(arr[j] < arr[tmp]){
                tmp = j;
            }
        }
        swap(arr[i], arr[tmp]);
    }
}

int main(){

    vector<int> arr = {3, 2, 4, 0, 1};
    selection_sort(arr);
    for(auto x : arr){
        cout << x << " ";
    }

return 0;
}
