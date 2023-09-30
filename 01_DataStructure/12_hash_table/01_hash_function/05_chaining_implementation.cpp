#include <bits\stdc++.h>
using namespace std;
struct PhoneEntry
{
    const static int INTERNAL_LIMIT = 2147483647;
    string name;
    int phoneNumber;
    PhoneEntry(string name, int phoneNumber) : name(name), phoneNumber(phoneNumber)
    {}
    int hash_string(string str, int n){
        long long nn = n;
        long long sum = 0;
        for(int i = 0; i  < (int)str.size(); i++){
            sum = (sum * 26 + str[i] - 'a') % nn;
        }
        return sum % nn;
    }
    int hash(){
        return hash_string(name, INTERNAL_LIMIT);
    }
    void print(){
        cout << " [ " << name << " , " << phoneNumber << " ]";
    }
};

class PhoneHashTable{
private:
    int tableSize;
    vector<vector<PhoneEntry>> table;
public:
    PhoneHashTable(int tableSize) : tableSize(tableSize){
        table.resize(tableSize);
    }
    void put(PhoneEntry phone){
        int idx = phone.hash() % tableSize;
        for(int i = 0; i < table[idx].size(); i++){
            if(phone.name == table[idx][i].name){
                // make update and return
                table[idx][i]= phone;
                return;
            }
        }
        table[idx].push_back(phone);
    }
    bool remove(PhoneEntry phone){
        int idx = phone.hash() % tableSize;
        for(int i = 0; i < table[idx].size(); i++){
            if(table[idx][i].name == phone.name){
                swap(table[idx][i], table[idx].back());
                table[idx].pop_back();
                return true;
            }
        }
        return false;
    }
    // search if element is found and update the passed argument with the 
    // found element
    bool get(PhoneEntry &phone){
        int idx = phone.hash() % tableSize;
        for(int i = 0; i < table[idx].size(); i++){
            if(table[idx][i].name == phone.name){
                phone = table[idx][i];
                return true;
            }
        }
        return false;
    }
    // print all elements in hash table
    void print_all(){
        for(int hash = 0; hash < tableSize; hash++){
            if(!table[hash].size())
                continue;
            cout << "Hash  " << hash << " :";
            for(int i = 0; i < table[hash].size(); i++){
                table[hash][i].print();
            }
            cout << endl;
        }
    }
};


int main(){

    PhoneHashTable *phoneTable = new PhoneHashTable(100);

    phoneTable->put({"a", 122});
    phoneTable->put({"b", 122});
    phoneTable->put({"z", 122});
    phoneTable->put({"zv", 122});
    phoneTable->put({"saad", 122});

    phoneTable->put({"sada", 122});
    phoneTable->put(PhoneEntry("saad", 155));
    phoneTable->print_all();

    PhoneEntry e("saad", 0);
    if(phoneTable->get(e))
        cout << e.phoneNumber << endl;

return 0;
}
