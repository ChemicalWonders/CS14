// Name: Kevin Chan
// CS 14 Lab Section: Tue 8:10AM - 11:00AM
// Problem # 3: Implement two stacks using one array
//SHOWED IN LAB
#include <iostream>
#include <stdlib.h>

using namespace std;

class twoStacksOneArray{
    int *arr;
    int size;
    int top1, top2;
    
    public:
        // Constructor
        twoStacksOneArray(int n){
            size = n;
            arr = new int[n];
            top1 = -1;
            top2 = size;
        }
        //Push an element x into stack#1
        void push1(int x){
            if (top1 < top2 -1){
                ++top1;
                arr[top1] = x;
            }
            else{
                cout << "Cannot push anymore, overflow error.";
                exit(1);
            }
        }
        //Push element x into stack #2
        void push2(int x){
            if (top1 < top2 -1){
                --top2;
                arr[top2] = x;
            }
            else{
                cout << "Cannot push to stack 2, overflow error.";
                exit(1);
            }
        }
        //Popping from stack #1
        void pop1(){
            if (top1 >= -1){
                --top1;
                return;
            }
            else{
                cout << "Cannot pop from stack 1, overflow error.";
                exit(1);
            }
        }
        //Popping from stack#2
        void pop2(){
            if(top2 < size){
                ++top2;
                return;
            }
            else{
                cout << "Cannot pop from stack 2, overflow error.";
                exit(1);
            }
        }
        void printA(){
            for (int i = 0; i < size; ++i){
                cout << " " << arr[i];
            }
            cout << top1 << endl;
            cout << top2 << endl;
        }
    };

//Testbench
int main(){
    twoStacksOneArray ts(7);
    ts.push1(5);
    ts.push2(10);
    ts.push2(15);
    ts.push1(11);
    ts.push2(7);
    ts.push1(15);
    
    ts.printA();
    cout << endl;
    
    ts.pop1();
    ts.pop2();
    cout << "after pops: ";
    ts.printA();
    
    return 0;
}
        
