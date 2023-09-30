#include <bits\stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.size() - 1;
        
        while (i < j) {
            while (!isalnum(s[i]) && i < j) {
                i++;
            }
            while (!isalnum(s[j]) && i < j) {
                j--;
            }
            if (tolower(s[i]) != tolower(s[j])) {
                return false;
            }
            i++;
            j--;
        }
        
        return true;
    }
};

class solution{
public:

    bool isPalindromV1(string str){
        // convert all uppercase letters into lowercase letters and removing
        // all non-alphanumeric characters
        if(!str.size())
            return true;
        
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
        int P1 = 0;
        int P2 = extracted.size() - 1;
        for(int i = 0; i <= (extracted.size()) / 2; i++){
            char P1ch = extracted[P1];
            char P2ch = extracted[P2];
            if(extracted[P1] != extracted[P2])
                return false;
            P1++;
            P2--;
            
        }
        return true;
    }
    bool isPalindromV2(string str){
        int L = 0;
        int R = (int)str.size() - 1;
        while( L < R){
            while(!isalnum(str[L]) && L < R)
                L++;
            while(!isalnum(str[R]) && L < R)
                R--;
            if((tolower(str[L])) != towlower(str[R]))
                return false;
            L++;
            R--;
        }
        return true;
    }
};


int main(){

 string str = "A man, a plan, a canal: panama";
 solution mySol;
 cout << mySol.isPalindromV2(str) << endl;
 str = "race a car";
 cout << mySol.isPalindromV2(str) << endl;
 str = " ";
 cout << mySol.isPalindromV2(str) << endl;

return 0;
}
