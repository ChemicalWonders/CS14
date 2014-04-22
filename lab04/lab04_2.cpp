// Name: Kevin Chan
// CS 14 Lab Section: Tue 8:10AM - 11:00AM
// Problem # 4: Lazy version vs Regular Version
//THIS FILE IS NOT COMPILABLE. THIS IS AN EXPLAINTATION FILE\
//SHOWED/EXPLAINED IN LAB
//Lazy Search
bool lazySearch (Node L, int target){
    Node ptr = L;
    while(ptr!=NULL && ptr.data < target){
        ptr = ptr.next;
    }
    if (ptr!=NULL && ptr.data == target)
        return true;
    return false;
}
//Regular Search
bool search (Node L, int target){
    for(Node ptr = L; ptr!=NULL; ptr=ptr.next){
        if(ptr.data==target)
            return true;
        }
        return false;
    }
//The lazySearch is actually faster than the Regular search. The reason is because
//The lazySearch does not contain a nested loop in the for loop, and mainly because
//while loop is faster than the for loop. 

// Since we don't know how many objects are going to be inside the actual search,
// we know that the lazySearch will have O(n) time, where as the nested loop will have 
// O(n^2) time. The nesting of the loop will make it of time O(n) * O(n), creating O(n^2).

//Lazy Search has O(n) time, because it iterates through each one, and linearly, it will
//try to figure out if the value is what we want.
//The regular search has a nested loop that nests an if loop within a for loop, which
//causes the time to run longer in the cause of an extreme amount of elements.
