#include <bits\stdc++.h>
using namespace std;

struct mystruct{
    void f1(){
        cout<< ++global << endl;
    }
    int global = 10;
    void f2(){
        f1();
    }
};
int main(){

mystruct LL;
LL.f1();

return 0;
}
