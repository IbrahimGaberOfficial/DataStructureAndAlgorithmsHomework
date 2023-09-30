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
    void right_rotate(){
        int tmp = arr[size - 1];
        for(int i = size - 1; i > 0; i--){
            arr[i] = arr[i - 1];
        }
        arr[0] = tmp;
    }
    ~Vector(){
        delete[] arr;
        arr = nullptr;
        cout << "vector with size " << capacity << " and address " << this << " deleted.\n";
    }

    ///////////////////////////
    void left_rotate(){
        int tmp = arr[0];
        for(int i = 0; i < size - 1; i++){
            arr[i] = arr[i + 1];
        }
        arr[size - 1] = tmp;
    }
};


void test2(){
    Vector myvector;
    
    for(int i = 0; i < 12; i++){
        myvector.push_back(i);
    }
    myvector.print();
    cout << "\n";
    myvector.insert(2, 10);
    myvector.print();
    
}
void test_R_rotate(){
    Vector myVector;
    myVector.push_back(0);
    myVector.print();
    myVector.left_rotate();
    myVector.print();
    myVector.push_back(1);
    myVector.push_back(2);
    myVector.push_back(3);
    myVector.push_back(4);
    myVector.push_back(5);

    
}

int main(){
    
    //  test2();
    test_R_rotate();
return 0;
}
