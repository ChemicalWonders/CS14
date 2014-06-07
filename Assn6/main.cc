#include <iostream>
#include "heapsort.cc"

using namespace std;

//Name: Kevin Chan
//Lab Time: 8:00AM to 11AM

// JUST COMPILE THIS FILE, it includes heapsort.cc

int main(){
    
    int ar[] = {4,2,6,2,5,7,8,2,8,1,9};
    int size = 11;
    
    heapSort(ar, size);
    
    for (int i = 0; i < size; ++i){
        cout << ar[i] << " ";
    }
    
    cout << endl;
    
    //After heapsort, the answer should be "1 2 2 2 4 5 6 7 8 8 9"
    
    int array[] = {1, 2, 2, 2, 4, 5, 6, 7, 8, 8, 9};
    int sizing = 11;
    
    heapSort(ar, size);
    
    for (int i = 0; i < sizing; ++i){
        cout << array[i] << " ";
    }
    
    cout << endl;
    
    //After heapsort, the answer should be "1 2 2 2 4 5 6 7 8 8 9"
    
    int emptyArray[] = {};
    int sizer = 0;
    
    heapSort(emptyArray, sizer);
    
    for (int i = 0; i < size; ++i){
        cout << emptyArray[i] << " ";
    }
    
    cout << endl;
    
    // Should not pass, because assertion will say size > 0, aborted function.
    
    return 0;    
}
