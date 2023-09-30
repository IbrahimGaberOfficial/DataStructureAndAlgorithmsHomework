#include <bits\stdc++.h>
using namespace std;
// make hash function that convert big numbers to small numbers
// from range 0 - 138
int hash_num(int value, int n = 139){
    // hashing the value in range 0 - 138
    return value % n;
}

void test_hash_num(){
    cout << hash_num(12) << endl;
    cout << hash_num(123) << endl;
    cout << hash_num(1234) << endl;
    cout << hash_num(12345) << endl;
    cout << hash_num(123456) << endl;
    cout << hash_num(1234567) << endl;
    cout << hash_num(12345678) << endl;
    cout << hash_num(123456789) << endl;
}
// make hash funciton that convert string into int
int hash_string1(string str, int n ){
    int sum{ };
    for(int i = 0; i < str.size(); i++){
        sum += str[i] - 'a'; // convert the numbers to range 0 - 25
    }
    return sum % n;
}
void test_hash_string1(){
    cout << "\nstring to int using hash_string1():\n";
    cout << hash_string1("abc", 7) << endl;
    cout << hash_string1("abcde", 70) << endl; // (0 + 1 + 2 + 3 + 4) % 70 = 10
    cout << hash_string1("abcde", 7) << endl;  // (0 + 1 + 2 + 3 + 4) % 7 = 3
    cout << hash_string1("bcdea", 7) << endl; // same chars = as baove = 3 and this
    // is the collision: when differnt values gives the same hash value
    cout << hash_string1("abcwz", 7) << endl;
}
 // best hash function that gives less collison
int hash_string2(string str, int n){
    int sum = 0;
    cout << str << " : " << endl;
    for(int i = 0; i < str.size(); i++){
        cout << endl << sum << " = " << sum << " * 26 + " << str[i] - 'a' << " = ";
        sum = sum * 26 + str[i] - 'a';
        cout << sum << endl;
    }
    return sum % n;
}
void test_hash_string2(){
    cout << hash_string2("abc", 7) << endl;
    cout << hash_string2("abcde", 70) << endl; 
    cout << hash_string2("abcde", 7) << endl;
    cout << hash_string2("bcdea", 7) << endl;

}
 
int main(){

    // test_hash_num();
    // test_hash_string1();
    test_hash_string2();


return 0;
}
