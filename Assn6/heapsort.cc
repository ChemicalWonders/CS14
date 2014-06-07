#include <iostream>
#include <assert.h> //Library is needed for Assert function

using namespace std;

void shiftR(int* arr, int low, int high)
{
    int root = low;
    while ((root*2)+1 <= high) // This portion is log n.
    {
        int leftNode = (root * 2) + 1;
        int rightNode = leftNode + 1;
        int swapId = root;
        
        //Check if root is less than left child
        if (arr[swapId] < arr[leftNode])
        {
            swapId = leftNode;
        }
        
        //If right child exists, check if it is less than current root
        if ((rightNode <= high) && (arr[swapId] < arr[rightNode]))
        {
            swapId = rightNode;
        }
        
        //Make the biggest element of root, left and right child the root
        if (swapId != root)
        {
            int tmp = arr[root];
            arr[root] = arr[swapId];
            arr[swapId] = tmp;
            /*Keep shifting until left and right child of the node is smaller than
            itself*/
            root = swapId;
        }
        else
        {
            break;
        }
    }
    return;
}
void heapify(int* arr, int low, int high)
{
    /*Start with middle element. Middle element is chosen in
    such a way that the last element of array is either its
    left child or right child*/
    
    int midId = (high - low -1)/2;
    while (midId >= 0)
    {
        shiftR(arr, midId, high);
        --midId;
    }
    return;
}
void heapSort(int* arr, int size)
{
    assert(arr);
    assert(size > 0);
    
    /*This will put max element in the index 0*/
    heapify(arr, 0, size-1);
    
    int high = size - 1;
    
    while (high > 0)
    {
        //Swap max element with high index in the array
        int tmp = arr[high];
        
        arr[high] = arr[0];
        arr[0] = tmp;
        --high;
        
        //Ensure heap property on remaining elements
        shiftR(arr, 0, high);
    }
    return;
}
