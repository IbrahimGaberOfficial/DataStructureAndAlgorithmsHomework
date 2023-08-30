#include <bits\stdc++.h>
using namespace std;


void test(){
    
deque<int> myDeque(10);
int x;
myDeque.push_front(3);
cout << "level " << 0 << " : ";
x = myDeque.front();
myDeque.pop_front();
cout << x << " ";
cout << endl;

myDeque.push_back(9);
myDeque.push_back(20);

cout << "level " << 1 << " : ";
x = myDeque.back();
myDeque.pop_back();
cout << x << " ";
x = myDeque.back();
myDeque.pop_back();
cout << x << " ";

}
int main(){

string x = "ali";
string y = "alii";
cout << "same : " << (x == y) << endl;
return 0;
}
