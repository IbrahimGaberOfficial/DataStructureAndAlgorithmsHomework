#include <bits\stdc++.h>
using namespace std;

 bool isAnagram(string s, string t) {
    int arr1[26]{ };
    int arr2[26]{ };
     int s_sz = (int)s.size();
        int t_sz = (int)t.size();
        if(s_sz != t_sz)
            return false;
        for(int i = 0; i < s_sz; i++){
            int up = s[i] - 'a';
            arr1[up]++;
            up = t[i]  - 'a';
            arr2[up]++;
        }
       
        for(int i = 0; i < 26; i++){
            if(arr1[i] != arr2[i])
                return false;
        }
        return true;
        
    }

void sort_string(){
    int arr[123]{ };
    int sz = 0;
    cin >> sz;
    for(int i = 0; i < sz; i++){
        char _intput;
        cin >> _intput;
        arr[(int)_intput]++;

    }
    for(int i = 0; i < 123; i++){
        if(arr[i])
            cout << (char)i << " ";
    }

}

int main(){
string s = "nl", t = "cx";
cout << isAnagram(s, t) << endl;;

// sort_string();

return 0;
}
