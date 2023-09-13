#include <bits\stdc++.h>
using namespace std;

void print_set(set<int> &st){
    for(auto x : st){
        cout << x << " ";
    }
    cout << endl;
}
void set_test(){
    set<int> st;
    st.insert(10);
    st.insert(20);
    st.insert(40);
    st.insert(30);
    print_set(st);
    

    if(st.count(10))
        cout << "YES\n";
    if(st.count(60))
        cout << "60 Yes.\n";
}
//////////////////////////////
void print_multi_set(multiset<int> &Mset){
    for(auto x : Mset) 
        cout << x << " ";
    cout << endl;
}
void multi_set_test(){
    multiset<int> Mset;
    Mset.insert(10);
    Mset.insert(10);
    Mset.insert(20);
    Mset.insert(30);
    Mset.insert(30);
    Mset.insert(50);

    print_multi_set(Mset);
    if(Mset.count(10))
        cout << "\n10 Exist in multi set.\n";
    if(Mset.count(55))
        cout << "\n55 exist in multi set.\n";

}

//////////////////////////////////////////
void print_map(map<string, int> &mapTest){
    for(auto x : mapTest)
        cout << x.first << " " << x.second << " \n";
    cout << "\n";
}
void map_test(){

    map<string, int> mapTest;
    mapTest["alin"] = 10;
    mapTest["ibrahim"] = 20;
    mapTest["said"] = 18;
    mapTest["alin"] = 33;
    print_map(mapTest);
}

int main(){

    // set_test();
    // multi_set_test();
    map_test();

return 0;
}
