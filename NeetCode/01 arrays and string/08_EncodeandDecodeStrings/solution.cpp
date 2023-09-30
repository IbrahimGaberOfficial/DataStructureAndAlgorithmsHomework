#include <bits\stdc++.h>
using namespace std;

class Solution {
public:
    /*
     * @param strs: a list of strings
     * @return: encodes a list of strings to a single string.
     */
    string encode(vector<string> &strs) {
        // write your code here
        ostringstream oss;
        for(auto x : strs){
            oss << x << "|";
        }
        return oss.str();
         
    }

    /*
     * @param str: A string
     * @return: decodes a single string to a list of strings
     */
    vector<string> decode(string &str) {
        // write your code here
        vector<string> strs;
        istringstream iss(str);
        while(iss.good()){
        getline(iss, str, '|');
        strs.push_back(str);
        }
        if(strs.back() == "")
            strs.pop_back();
        return strs;

    }
};
class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string result = "";
        
        for (int i = 0; i < strs.size(); i++) {
            string str = strs[i];
            result += to_string(str.size()) + "#" + str;
        }
        
        return result;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string str) {
        vector<string> result;
        int i = 0;
        while(i < str.size()){
            int j = i;
            while(str[j] != '#')
                j++;
            // substr(int start_pos, int lenth)
            int length = stoi(str.substr(i, j - i));
            string subStr = str.substr(j + 1, length);
            result.push_back(subStr);
            i = j + 1 + length;
        }
        

        return result;
    }
private:
};

int main(){

    vector<string> strs{"lint","code","love","you"};
    string str;
    Codec mySol;
    str = mySol.encode(strs) ;
    cout << str << endl;

    strs = mySol.decode(str);
    for(auto x : strs){
        cout <<"." <<  x;
    }
    return 0;
}
