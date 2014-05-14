
void shiftRight(int* arr, int low, int high)
{
    int root = low;
    while ((root*2)+1 <= high)
    {
        int leftChild = (root * 2) + 1;
        int rightChild = leftChild + 1;
        int swapIdx = root;
        /*Check if root is less than left child*/
        if (arr[swapIdx] < arr[leftChild])
        {
            swapIdx = leftChild;
        }
        /*If right child exists check if it is less than current root*/
        if ((rightChild <= high) && (arr[swapIdx] < arr[rightChild]))
        {
            swapIdx = rightChild;
        }
        /*Make the biggest element of root, left and right child the root*/
        if (swapIdx != root)
        {
            int tmp = arr[root];
            arr[root] = arr[swapIdx];
            arr[swapIdx] = tmp;
            /*Keep shifting right and ensure that swapIdx satisfies
            heap property aka left and right child of it is smaller than
            itself*/
            root = swapIdx;
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
    int midIdx = (high - low -1)/2;
    while (midIdx >= 0)
    {
        shiftRight(arr, midIdx, high);
        --midIdx;
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
        /*Swap max element with high index in the array*/
        int tmp = arr[high];
        arr[high] = arr[0];
        arr[0] = tmp;
        --high;
        /*Ensure heap property on remaining elements*/
        shiftRight(arr, 0, high);
    }
    return;
}

int binary_search(int array[],int first,int last, int value);
 
int main() {
 
    int list[10];
 
    for (int k=0; k<11; k++)
    list[k]=2*k+1;
 
    cout<< "binary search results: "<< binary_search(list,1,21,11)<<endl;
 
 return 0;
}

int binary_search(int array[], int first, int last, int search_key)
{
    int index;
 
    if (first > last){
        index = -1;
    }
    else{
        int mid = (first + last)/2;
 
        if (search_key == array[mid]){
            index = mid;
        }
        
        else{
            if (search_key < array[mid]){
                index = binary_search(array,first, mid-1, search_key);
            }
            else{
                index = binary_search(array, mid+1, last, search_key);
            }
        }
    } // end if
    return index;
 }// end binarySearch
