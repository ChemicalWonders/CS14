#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <utility>
#include "MyList.h"
#include "Node.h"

using namespace std;
//CONSTRUCTORS // ALL COMPLETE
//Default Constructor
MyList::MyList()
:head(NULL)
{}

// Constructs a list from a passed-in MyList Object, e.g. MyList list1(list2)
//COPY CONSTRUCTOR: USE ASSIGNMENT OPERATOR!
MyList::MyList(const MyList & str):head(NULL)
{
    Node* temp = str.head;
    while (temp != NULL){
        push_back(temp->value);
        temp = temp -> next;
    }
}

//Constructs a list from a passed-in string literal, e.g. MyList list1("Hello World");
//Construct with stringstream. parse the string
MyList::MyList(const char* str):head(NULL){
    int value = 0;
    while (str[value] != '\0'){
        push_back(str[value]);
        value++;
    }
}

// Destructor
MyList::~MyList(){
	while(head->next != NULL){
		pop_front();
	}
}


//Mutators

//Inserts value at the front of the list
void MyList::push_front(char value){
	Node* temp = new Node (value);
	temp -> next = head;
	head = temp;
}

//Inserts value at the back of the list
void MyList::push_back(char value){
	Node* backTemp = new Node(value);
	if(head == NULL){
		head = backTemp;
    }
	else{
		Node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = backTemp;
	}
}

//Removes the front item from the list
void MyList::pop_front(){
	if (head != 0){
		Node* temp = head;
		head = head->next;
		delete temp;
	}
}

//Removes the last item from the list
void MyList::pop_back(){
    Node* removeTemp = head;
	if(head == 0){
		return;
	}
	else{
		Node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        removeTemp -> next = 0;
        delete temp;
	}
}

//Swaps the value of the node at position i in the list
//with the value of the node at position j
//HANDLE OUT-OF-RANGE CALLS
//NEED TO FIX
void MyList::swap(int i, int j){
    Node* temp = head;
    Node* secondTemp= head;
    int alpha = 0;
    int beta = 0;
    
    if (i > size()|| j > size()){
        cout << "OUT OF RANGE; EXITING NOW.";
        cout << endl;
        exit(1);
    }
    while(temp->next != NULL){
        while(secondTemp -> next != NULL){
            if (j == beta){
                std::swap(secondTemp->value, temp->value);
            }
            secondTemp = secondTemp->next;
            ++beta;
        }
        temp = temp->next;
        ++alpha;
    }
}

//Inserts a node with value at position i in the list
void MyList::insert_at_pos(int i, char value){
	if(i > size()){
        cout << "position too big, can not insert";
        cout << endl;
		return;
	}
	
	int positionalInsert = 0;
	Node* temp = new Node(value);
	Node* tmp = head->next;
	Node* prev = head;
	while(tmp != NULL){
		if (i == positionalInsert){
			prev->next = temp;
			temp -> next = tmp;
		}
		tmp = tmp -> next;
        ++i;
	}

	if (tmp == NULL){
		push_front(value);
	}
}

//Reverses the items in the list.
//NEED TO FIX
void MyList::reverse(){
	MyList A;
    Node* temp = this->head;
    while(temp != NULL){
        A.push_front(temp->value);
        temp = temp->next;
    }
    head = A.head;
}


//Accessors

//Returns the number of nodes in the list;
int MyList::size() const{
	int sizeValue = 0;
	Node* temp = head;
	while (temp != NULL)
	{
		sizeValue++;
		temp = temp -> next;
	}
	return sizeValue;
}

//Prints the contents of the list
void MyList::print() const{
	Node* temp = head;
    if (temp == NULL)
    {
        return;
    }
	while (temp != NULL){
		cout << temp -> value << " ";
		temp = temp -> next;
	}
}

//Finds the position of the first occurrence of a char value in the list
//and returns that position. If the character is not in the list, 
//the function returns -1.
int MyList::find(char value) const{
	
	int valuePosition = 0;
	Node* temp = head;
    char matchedValue = temp -> value;
	while(temp != NULL){
		
		if (matchedValue == value){
			return valuePosition;
		}
		valuePosition++;
		temp = temp -> next;
        matchedValue = temp -> value;
	}
	return -1;
}

// Finds the position of the first occurance of the MyList query_str
// in the list and returns that position. If query_str is not in the list
//the function returns -1.
int MyList::find(MyList& query_str) const{
	//TODO
}


//Operator Overloaders // ALL COMPLETE

//For assignment of one list to another, i.e. 11=12;
//Same as copy constructor, implement one and use the other one for the other one
MyList& MyList::operator=(const MyList& str){
	Node* temp = str.head;
    if(temp == NULL){
        MyList();
        return *this;
    }
    while (temp != NULL){
        push_back(temp->value);
        temp = temp -> next;
    }
    return *this;
}

//Returns the character at position i
char& MyList::operator[] (const int i){
	int iNum = i;
    
    if (i > size()){
        cout << "SEGMENTATION FAULT PLEASE TRY AGAIN";
        exit(1);
    }
    
	for (Node* j = head; head != NULL; j=j->next){
		if(iNum == 0){
			return j->value;
		}
		iNum--;
	}
}

//Concatenates two list together, e.g. 11+ 12;
MyList& MyList::operator+(const MyList& str){
	Node* temp = head;
	Node* secondTemp = str.head;
	while(temp != NULL){
		temp = temp->next;
	}
	while(secondTemp != NULL){
		push_back(secondTemp->value);
		secondTemp = secondTemp -> next;
	}
	return *this;
}
