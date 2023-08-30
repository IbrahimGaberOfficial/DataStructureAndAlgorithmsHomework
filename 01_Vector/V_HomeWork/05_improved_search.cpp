#include <iostream>
#include <cassert>
//#include<stack>

using namespace std;

class Vector{
private:

    int *arr{ };
    int size{ };
    int capacity{0};

public:
    Vector(int size) : capacity(size){
        if(size <= 0)
        capacity = 10;
        arr = new int [capacity];
        
    }
    Vector(){
       capacity = 10;
        arr = new int [capacity];
    }
    void capacity_trick(){
        capacity = capacity * 2;
        int *arr2 = new int[capacity];
        for(int i = 0; i < size; i++)
            arr2[i] = arr[i];

        swap(arr, arr2);
        delete[] arr2;
        arr2 = nullptr;

    }
    int get(int idx){
        assert(idx >= 0 && idx < size);
        return arr[idx];
    }
    void set(int idx, int value){
        assert(idx >= 0 && idx < size);
        arr[idx] = value;
    }
    void print(){
        for(int i = 0; i < size; i++){
            
            if(arr[i] == INT16_MIN)
                continue;
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    pair<bool,int> found(int val){
        for(int i = 0; i < size; i++){
            if(arr[i] == val)
                return make_pair(true, i);
        }
        return make_pair(false, -1);


    }
    int _size(){
        return size;
    }
    //////////////////////////////////
    int get_front(){
        return arr[0];
    }
    int get_back(){
        return arr[size - 1];
    }
    //appending operation using capcity trick
    void push_back(int value){
        if(size == capacity)
            capacity_trick();
            arr[size++] = value;
        
    }

    ///////////////////
    void insert(int idx, int value){
        assert(idx >= 0 && idx < size);
        if(size == capacity)
            capacity_trick();
        //make shift right 
        for(int i = size; i > idx; i--){
            arr[i] = arr[i - 1];
        }
        arr[idx] = value;
        ++size;
    }
    //////////////////////////////////
    //mySol
    int find_transposition(int find){
        for(int i = 0; i < size; i++){
            if(arr[i] == find){
                if(i == 0){
                    return i;
                }
                swap(arr[i], arr[i - 1]);
                return i - 1;
            }
        }
        return -1;
    }
    ~Vector(){
        delete[] arr;
        arr = nullptr;
        cout << "vector with size " << capacity << " and address " << this << " deleted.\n";
    }
};



void test_find_transposition(){
    Vector myVector;
    myVector.push_back(77);

    myVector.push_back(1);
    myVector.push_back(2);
    myVector.push_back(3);
    myVector.push_back(4);
    myVector.push_back(5);
    myVector.print();
   cout << myVector.find_transposition(2) << endl;
    myVector.print();
   cout << myVector.find_transposition(2) << endl;
    myVector.print();
   cout << myVector.find_transposition(2) << endl;
    myVector.print();
   cout << myVector.find_transposition(5) << endl;
    myVector.print();
}

int main(){
    
    //  test2();
    test_find_transposition();
return 0;
}
