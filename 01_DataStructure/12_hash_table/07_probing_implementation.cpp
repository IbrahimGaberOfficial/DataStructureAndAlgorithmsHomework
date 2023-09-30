#include <bits\stdc++.h>
using namespace std;

struct PhoneEntry
{
    const static int INTERNAL_LIMIT = 2147483647;
    string name;
    string phoneNumber;
    PhoneEntry(string name, string phoneNumber) : name(name), phoneNumber(phoneNumber)
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
    int table_size;
    vector<PhoneEntry*> table;
    // used deleted to mark deleted cells
    PhoneEntry* deleted = new PhoneEntry("", "");
public:
    PhoneHashTable(int table_size) : table_size(table_size){
        table.resize(table_size);
    }
    // function used to insert new element or update exist element
    bool put(PhoneEntry phone){
        int idx = phone.hash() % table_size;
        for(int i = 0; i < table_size; i++){
            // empty
            if(!table[idx] || table[idx] == deleted){
                table[idx] = new PhoneEntry(phone.name, phone.phoneNumber);
                return true;
            }
            // found phone name and update it 's new info
            //update
            else if(table[idx]->name == phone.name){
                table[idx]->phoneNumber = phone.phoneNumber;
                return true;
            }
            // move to the next 
            idx = (idx + 1) % table_size;
        }
        return false;
    }
    // function find querey and delete it, mark as deleted
    bool remove(PhoneEntry phone){
        int idx = phone.hash() % table_size;
        for(int i = 0; i < table_size; i++){
            if(!table[idx])
                break;
            if(table[idx]->name == phone.name){
                // delete table[i];
                // mark as deleted to not conflict other functions as 
                //put() and search()

                table[idx] = deleted;
                return true;
            }
            idx = (idx + 1) % table_size; // move to next index
        }
        return false;
    }
    // function to search for querey
    bool get(PhoneEntry &phone){
        int idx = phone.hash() % table_size;
        for(int i = 0; i < table_size; i++){
            if(!table[idx])
                break;
            else if(table[idx] == deleted)
                continue;
            else if (phone.name == table[idx]->name){
                phone.phoneNumber = table[idx]->phoneNumber;
                return true;
            }

            i = (i + 1) % table_size;
        }
        return false;
    }
    void printAll(){
        for(int i = 0; i < table_size; i++){
            cout << "hash : " << i << " -> ";
            if(!table[i]){
                cout << " Empty ";
            }
            else if(table[i] == deleted){
                cout << "Deleted ";
            }
            else{
                cout << "(" << table[i]->hash() % table_size << ") ";
            table[i]->print();
            }
            cout  << endl;
        }
        cout << endl;
    }

};

int main(){
    PhoneHashTable phone_table(10);
    phone_table.printAll();

    phone_table.put(PhoneEntry{"ali", "15"});
    phone_table.printAll();
    phone_table.put(PhoneEntry{"ibro", "15"});
    phone_table.put(PhoneEntry{"saad", "25"});
    phone_table.printAll();
    phone_table.put(PhoneEntry{"saiid", "10"});
    phone_table.put(PhoneEntry{"saeid", "11"});
    phone_table.put(PhoneEntry{"sammy", "13"});
    phone_table.printAll();
    phone_table.put(PhoneEntry{"sam", "15"});
    phone_table.put(PhoneEntry{"jack", "15"});
    phone_table.put(PhoneEntry{"hany", "15"});
    phone_table.put(PhoneEntry{"mar", "15"});
    phone_table.printAll();
    cout << phone_table.put(PhoneEntry{"zak", "000"});


return 0;
}
