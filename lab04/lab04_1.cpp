// Name: Kevin Chan
// CS 14 Lab Section: Tue 8:10AM - 11:00AM
// Problem # 2: Recursive Binary Search
//SHOWED IN LAB
#include <iostream>

using namespace std;

int BinarySearch(int array[], int target, int low, int high){
    if(high < low)
        return -1;
    
    int mid = low+ ((high-low)/2);
        
        if (array[mid] > target)
            return BinarySearch(array, target, low, mid-1);
        else if (array[mid] < target)
            return BinarySearch(array, target, mid+1, high);
        else
            return mid;
    }

int main(){
    int array[] = {1,2,3,4,5,6,7};
    int targetNum = 0;
    
    cout << "What target do you want: ";
    cin >> targetNum;
    cout << endl;
    
    cout << "The number is at position ";
    cout << BinarySearch(array,targetNum, 0, 6);
    cout << endl;
    
    return 0;
}
