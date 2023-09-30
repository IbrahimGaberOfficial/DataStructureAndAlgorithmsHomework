#include <bits\stdc++.h>
using namespace std;

void mergeSortedArrays(int arr1[], int arr2[], int arr3[3], int size1, int size2, int size3){
    
    int P1 = 0, P2 = 0;
    for(int i = 0; i < size3; i++){
        if(P1 < size1 && P2 < size2){
            if(arr1[P1] < arr2[P2]){
                arr3[i] = arr1[P1];
                P1++;
            }
            else{
                arr3[i] = arr2[P2];
                P2++;
            }
        }
        else if(P1 >= size1 && P2 < size2){
            arr3[i] = arr2[P2];
            P2++;
        }
        else if(P1 < size1 && P2 >= size2){
            arr3[i] = arr1[P1];
            P1++;
        }
    }
}

int main(){


    int arr1[3] = {1, 2, 4};
    int arr2[4] = {2, 5, 6, 8};
    int arr3[7];
    mergeSortedArrays(arr1, arr2, arr3, 3, 4, 7);
    for(int i = 0; i < 7; i++){
        cout << arr3[i] << " ";
    }

return 0;
}
