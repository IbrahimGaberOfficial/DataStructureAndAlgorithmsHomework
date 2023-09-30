#include <bits\stdc++.h>
using namespace std;
// handling negative values
int hash_num(int value, int n = 65407){
    cout << endl << "( " << value << " % " << n << " + " <<  n << " ) % " << n << endl;
    return (value % n + n) % n;
}
void test_hash_num(){
    cout << hash_num(10) << endl;
    cout << hash_num(20) << endl;
    cout << hash_num(23) << endl;
    cout << hash_num(-23) << endl;

    // test over flow
    cout << hash_num(2147483646, 2147483646) << endl;
}
// handling negative values overflow
int hash_num2(int value , int n = 65407){
    long long n2 = n;
    cout << endl << "( " << value << " % " << n2 << " + " <<  n2 << " ) % " << n2 << endl;
    return (value % n2 + n2) % n2;
}
void test_hash_num2(){
    cout << hash_num2(2147483646, 2147483647);
}


int main(){

    // test_hash_num();
    test_hash_num2();

    cout << "\nbye\n";

return 0;
}
