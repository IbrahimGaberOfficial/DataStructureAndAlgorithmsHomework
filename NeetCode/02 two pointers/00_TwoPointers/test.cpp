#include <bits\stdc++.h>
using namespace std;

void test1(){
    string str = "A man, a plane, a canal: panama";
    string extracted = "";
        for(int i = 0; i < (int)str.size(); i++){
            char current = str[i];
            if(isupper(current)){
                extracted.push_back(tolower(current));
            }
            else if(islower(current)){
                extracted.push_back(current);
            }
            else if(isdigit(current)){
                extracted.push_back(current);
            }
            else{
                continue;
            }
        }
        cout << extracted << endl;
    
}

int main(){
    
    test1();

return 0;
}
