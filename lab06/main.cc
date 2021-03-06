// Kevin Chan
// Lab #6 
// TA: John Cross

/* Problem # 1
You can choose 4 keys that chooses through 3 with m possible buckets, so the resulting answer will be 
[4(m-1)/m^3] */


/* Problem #6.
int hash(const string & key, int tableize)
{
    return (key[0] + 27*key[1] + 729*key[2]) % tablesize;
}

int hash(const string & key, int tablesize)
{
    int hashval = 0;
    for (int i = 0; i<key.length(); i++)
        hashval += key[ i ];
        
    return hashval % tablesize ;
}

The con of the the first function is that the algorithm using the same format to hash the table. If you have
the code, you can easily crack the hash. It also assumed that key is at least a size of 3.

The con of the second function is the map size is constant. There might be a slower runtime
* because it takes longer to rehash the table.
*/

#include "hash.h"

using namespace std;

int main() {

    hashMap h;

    h.insert(1, "hello");
    h.insert(2, "my");
    h.insert(11, "test");
    h.insert(3, "name");
    h.insert(4, "is");
    h.insert(5, "bob");
    h.insert(6, "help");
    h.insert(7, "me");
    h.insert(8, "conquer");
    h.insert(9, "the");
    h.insert(10, "world");

    h.insert(1, "bye");
    
    h.rehash();
    h.display();
    
    cout << "Find(4) = " << h.find(4) << endl;

}
