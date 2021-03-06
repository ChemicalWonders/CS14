#include "hash.h"

using namespace std;

hash::hash(int k, string s) {
    //Inital Constructor
    this->key = k;
    this->data = s;
}

int hash::ki() {
    //Returns the key in the value
    return this->key;
}

string hash::unlock() {
    //Returns the data inside the hash map
    return this->data;
}

hashMap::hashMap() {
    //Constructor for the hash map
    sz = 100;//Inital Size of 100
    map = new hash*[sz];
    for (int i = 0; i < sz; i++) {
        // Initalize with all Null
        map[i] = NULL;
    }
}

hashMap::~hashMap() {
    //Destructor: Needs a for loop because it needs to be iterator through
    // a for loop
    
    for (int i = 0; i < sz; i++) {
        if (map[i] != NULL)
        delete map[i];
    }
}

void hashMap::insert(int k, string s) {
    int i = (k % sz);
    
    while (map[i] != NULL && map[i]->ki() != k) {//looks for free spot in table
        i = (i + 1) % sz;//or until the key value is reached
    }
    
    if (map[i] != NULL) {//clears the hash if taken for new hash
        delete map[i];
    }
    
    map[i] = new hash(k, s);
}

string hashMap::find(int l) { //Problem # 5: FIND FUNCTION
    int L = (l % sz);//hashing algorithm
    
    if (map[L] == NULL) {//no correspondence to key
        return "";
    }
    
    else {
        while (map[L] != NULL && map[L]->ki() != l) {
            //Found free spot and value
        L = (L+1) % sz;
        }
        
        if (map[L] != NULL) {
            //If there is a corresponding value
            return map[L]->unlock();
        }
        
        else {
            cout << "Out of bounds" << endl;
            exit(1);
        }
    }
}

void hashMap::rehash() {//Problem #2 : REHASH WITH LINEAR PROBE
    hash** replacement = new hash*[sz * 2];//new table of double size
    
    for (int i = 0; i < sz; i++) {
        if (map[i] != NULL) {
            int k = map[i]->ki(); //Key value
            string d = map[i]->unlock(); //Data value
            
            
            
            
            int j = (k % (sz * 2));//Hash with the new size
    
            while (replacement[j] != NULL && replacement[j]->ki() != k) {
                j = (j+1) % (sz * 2);
            }
            
            replacement[j] = new hash(k, d);//moves everything to new table
        }//also rehashes all the key's/indexes
    }
    
    for (int i = 0; i < sz; i++) {//deletes the old table
        if (map[i] != NULL) {
            delete map[i];
        }
    }
    
    map = new hash*[sz * 2];//Expands the table by double the size
    sz = sz * 2;//doubles the sz
    map = replacement;//moves all the values back in expanded table.
    
}

void hashMap::display() const {
    for (int i = 0; i < sz; ++i) {
        if (map[i] != NULL){
            cout << "Key " << i << ": " << map[i]->unlock() << endl;
        }
    }
}

int hashMap::size() {// Returns the size of the hash table
    return this->sz;
}
