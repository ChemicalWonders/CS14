// Name: Kevin Chan
// CS 14 Lab Section: Tue 8:10AM - 11:00AM
// Problem # 5: Analyze following code for binary search.
//SHOWED IN LAB

#include <iostream>

using namespace std;

int bsearch (int array[], int target, int array_len){
    int high = array_len, low=-1, probe;
    while (high - low > 1){
        probe = (low+high)/2;
        
        if (array[probe] > target)
            high = probe;
            
        else
            low = probe;
    }
    
    if (low == -1||array[low] != target)
        return -1;
    else
        return low;
    
    }


int main(){
    int array[] = {1,2,3,4,5,6,7};
    int targetNum = 0;
    
    cout << "What target do you want: ";
    cin >> targetNum;
    cout << endl;
    
    cout << "The number is at position ";
    cout << bsearch(array,targetNum, 7);
    cout << endl;
    
    return 0;
}
// Pros:
    //Fast code that works by splitting the list into two.
    //Not many nested loops, and has a worst time of O(n log n)
    //If it's not found, it returns -1, which is a set value by the programmer.
    
// Cons:
    //Code needs to be sorted. If the array is not sorted, it doesn't find it.
    //There are probably faster ways of implementing this search.
    //Needs to know the size, which might be factored out if you're using a different
    //type of container.
