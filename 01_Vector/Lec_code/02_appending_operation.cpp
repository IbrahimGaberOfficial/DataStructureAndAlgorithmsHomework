#include <iostream>
#include <cassert>
//#include<stack>

using namespace std;

class Vector{
private:

    int *arr{ };
    int size{ };

public:
    Vector(int size) : size(size){
        if(size <= 0)
            size = 1;
        arr = new int [size];
    }
    Vector(){
        size = 1;
        arr = new int [size];
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
    //appending operation
    void push_back(int value){
        int *arr2 = new int[size + 1];
        for(int i = 0; i < size; i++)
            arr2[i] = arr[i];
        arr2[size++] = value;
        swap(arr, arr2);
        delete[] arr2;
        arr2 = nullptr;
    }


    ~Vector(){
        delete[] arr;
        arr = nullptr;
        cout << "vector with size " << size << " and address " << this << " deleted.\n";
    }
};

// void test(){


// using namespace std;




// 	pair<int, string> p = make_pair(10, "mostafa");
// 	cout<<p.first<<" "<<p.second<<"\n";

// 	stack< pair<int, string> > s;
// 	s.push(p);
// 	s.push(p);

// 	pair<int, pair<int, string> > my_p = make_pair(10, make_pair(20, "ali"));
// 	my_p = make_pair(10, p);

	

// }
void test1(){
    Vector myVector(10);
    myVector.set(0, 10);
    myVector.set(1, 11);
    cout << myVector.get(0) << endl;
    cout << myVector.get(1) << endl;
    cout << myVector.get(4) << endl;
   // cout << myVector.get(11) << endl;
    pair<bool, int> result = myVector.found(10);
    if(result.first){
        cout << "found in index " << result.second << endl;
    }
    else{
        cout << "not found .\n";
    }
    cout << "*************************\n";
    myVector.print();

}

void test2(){
    Vector myvector;
    for(int i = 0; i < 1000000; i++){
        myvector.push_back(i);
    }
    myvector.print();
    
}
int main(){
    
    test2();
    
return 0;
}
