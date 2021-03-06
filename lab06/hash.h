#include <iostream>
#include <vector>
#include <list>
#include <cstdlib>

#ifndef hash_H_
#define hash_H_

using namespace std;

class hash {
    private:
        int key;
        string data;
        
    public:
        hash(int key, string s);
        int ki();
        string unlock();
    };
    
class hashMap {
    private:
        int sz;
        hash** map;
    public:
        hashMap();
        ~hashMap();
        void insert(int k, string s);
        string find(int l);
        void rehash();
        void display () const;
        int size();
    };
#endif
