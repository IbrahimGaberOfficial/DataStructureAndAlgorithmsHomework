#include <bits\stdc++.h>
using namespace std;

    int hash_num(int num, int n = 65407){
        long long nn = n;
        return (num % nn + nn) %nn;
    }
    int hash_string(string str, int n = 65407){
        int base = 26 + 26 + 10; // upper and lower and digits
        long long nn = n;
        long long sum = 0;
        for(int i = 0; i < int(str.size()); i++){
            int value = 0;
            if(islower(str[i]))
                value = str[i] - 'a';
            else if(isupper(str[i]))
                value = 26 + str[i] - 'A';
            else if(isdigit(str[i]))
                value = 26 + 26 + str[i] - '0';
            else{
                cout << "character " << str[i] << ", in  index : " << i << " is not letter nor digit\n";
                assert(false);
            }
            sum = sum * base + value;
            sum = sum % nn;
        }
        return sum;
    }

class test{
    string str1, str2;
    int number;
    int INTERNAL_LIMIT = INTMAX_MAX;
    int hash(){
        long long hash1 = hash_string(str1 + str2, INTERNAL_LIMIT);
        long long hash2 = hash_num(number, INTERNAL_LIMIT);
        return (hash1 + hash2) % INTERNAL_LIMIT;
    }
};

int main(){



return 0;
}
