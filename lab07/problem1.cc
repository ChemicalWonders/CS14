#include <iostream>
#include <cstdlib>

//Lab # 7

//Name: Kevin Chan
//Lab: 8AM to 11AM

using namespace std;

//Problem #1
void arrange ( int * array, int size ){
    int isFalse = 0;
    int isMaybe = 0;
    int isTrue = 0;
    
    for (int i = 0; i < size; ++i){
        if (array[i] == 1){
            ++isTrue;
        }
        else if (array [i] == 0){
            ++isFalse;
        }
        
        else if (array[i] == 2) {
            ++isMaybe;
        }
    }
    
    for (int j = 0; j < isFalse; ++j) {
        array[j] = 0;
    }
    
    for (int k = isFalse; k < isMaybe+isFalse; ++k) {
        array[k] = 2;
    }
    
    for (int l = isFalse + isMaybe; l < size; ++l){
        array[l] = 1;
    }
    
}

//Problem #2
void heapify (int *a, int i, const int n){
    int j, temp;
    temp = a[i];
    j = 2*i;
    
    while (j <= n){
        if (j < n && a[j+1] > a[j])
            j= j+1;
        if (temp > a[j])
            break;
        else if (temp <= a[j])
        {
            a[j/2] = a[j];
            j = 2*j;
        }
    }
    a [j/2] = temp;

}

void heapsort(int *a, const int number){
    int i, temp;
    
    for(i = number; i >=2; --i){
        temp = a[i];
        a[i] = a[1];
        a[1] = temp;
        
        heapify (a , 1, i-1);
    }
}

void build_heap(int *a, const int number){
    
    int i = 0;
    for ( i  = number/2; i >= 0; --i){
        heapify(a, i ,number);
    }
}

void binarySearch (int * array, int lower, int upper, int key){
    int position;
    
    position = (lower + upper)/2;
    
    while(array[position] != key && (lower <=upper)){
        
        if(array[position] > key){
            upper = position -1;
        }
        
        else {
            lower = position + 1;
        }
        position = (lower + upper)/2;
    }
    
    if (lower <= upper){
        cout << key << " was found in this array. ";
    }
    
    else 
        cout << key << " was NOT found in this array. ";
        
    return;
}
    
    /* #5 Determine the running time of quick sort for:
     * -sorted input: O(n^2)
     * -reverse -ordered input: O(n^2)
     * -random input: O(nlog n)
     * 
     * #6 Give an already sorted array of 10 elements, how many comparisons
     * of arrays elements would each of the following algorithms perform?
     * 
     * - bubble sort: 45
     * - quicksort: 10 because 10 * log (10) 
     * 
     */

int main(){
    
    int a[10] = {14,10,12,16,42,25,6,72,82,29};
    const int number  = 10;
    
    build_heap(a, number);
    
    heapsort(a, number);
    cout << "Number is: " << number << endl;
    for (int i = 1; i < number; ++i){
        cout << a[i] << " ";
    }
    cout << endl;
    
    binarySearch(a, 0, 10, 14);
    
    return 0;
}
