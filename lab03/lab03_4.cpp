// Name: Kevin Chan
// CS 14 Lab Section: Tue 8:10AM - 11:00AM
// Problem # 5: Determine if a singly linked list is circular or not
#include <iostream>
#include <list>
using namespace std;

bool hasLoop(Node startNode){
    Node prevNode = Node presentNode = Node futureNode = startNode;
    while (prevNode && presentNode = futureNode->next && futureNode = presentNode->next){
        if(prevNode == presentNode || prevNode == futureNode)
            return true;
        prevNode = prevNode->next;
    }
    return false;
}

int main(){
    list<int> A;
    A.push_back(1);
    A.push_back(2);
    A.push_back(3);
    A.tail() = A.head();
    int tick = 0;
    int Asize = A.size();
    
    return 0;
}
    
    
