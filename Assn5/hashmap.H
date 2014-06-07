#ifndef __HASHMAP_H_
#define __HASHMAP_H_

#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <map>

using namespace std;

enum curStat{freed, active, deactivated};
#define each(I) for(typeof(I.begin()) it = (I).begin(); it!=(I).end(); ++it)

template <typename t>
class Node {
    public:
        t value;
        curStat currentStatus;
    
    Node()
    : value(0), currentStatus(freed)
    {}
    
    Node(t val)
    :value(val), currentStatus(active)
    {}
    
    Node& operator = (const Node & rhs){
        value = rhs.value;
        currentStatus = rhs.currentStatus;
        return *this;
    }
    
    void print ( ostream & out){
        out << "Value is: " << value;
    }
    
};

template <typename t>
class hashMap{
    
    private:
        map <const string, Node < t > > mappedValues;
        
        Node <t> hashtable [103];
       
    public:
        unsigned int hash (const string & s, int tableSize){
            unsigned int h= 0;
            each(s) h = 37*h + unsigned(*it);
            return h%tableSize;
        }
        
        unsigned int stride(const string & s, int tableSize){
            unsigned int h = 0;
            each(s) h = 31*h + unsigned (*it);
            return h & tableSize;
        }
        
        hashMap()
        {
            for (int k = 0; k < 103; ++k){
                hashtable[k] = 0;
            }
        }
              
        hashMap( hashMap< t > & l){
            typename map <const string, Node < t > > ::iterator i = l.begin();
            typename map <const string, Node < t > > ::iterator j = begin();
            for (; i != l.end(); ++i,++j){
                //~ j-> first = i->first;
                j->second = i->second;
            }
            
            for (int k = 0; k < 103; ++k){
                hashtable[k] = l.hashtable[k];
            }
        }
        
        hashMap & operator = (hashMap & l){
            return mappedValues(l);
        }
        
        //Destructor
        ~hashMap(){
            mappedValues.clear();
            }
            
        Node <t> & operator[] (const string ki){
            return hashtable[hash(ki, 103)];
        }
        
        typename map <const string, Node < t > >::iterator find(const string& l){
            return mappedValues.find(l);
        }
        
        //Begin Iterator
        typename map <const string, Node < t > > ::iterator begin(){
            return mappedValues.begin();
        }
        
        //End Iterator
        typename map <const string, Node < t > > :: iterator end(){
            return mappedValues.end();
        }
        
        void display(){
            //~ for (typename map <const string, Node < t > >::iterator it = mappedValues.begin();
             //~ it != mappedValues.end(); ++it){
                //~ cout << "Key is " << it ->first << endl;
                //~ cout << "Value is " << it->second.value << endl;
                //~ cout << "Protection Value is " << it ->second.currentStatus << endl;
            //~ }
            
            for (int i = 0; i < 103; ++i){
                cout << hashtable[i].value<< " ";
            }
            cout << endl;
        }
        

    };
template <typename t>
ostream & operator << (ostream & out,Node <t> & ki){
    ki.print(out);
    return out;
}
    
    
#endif
