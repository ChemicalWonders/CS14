// -*- bst.cc -*-

// If you undefine TEST this file can be used as a header file
// that defines the class tree.

#ifndef BST_H
#define BST_H
#define TEST

#include <cassert>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <map>
#include <vector>
#include <list>
#include <math.h>

using namespace std;

#define nil 0

// #define Value int  // restore for testing. 
template < typename Value >
class Tree {

  class Node {  //  binary tree node
  public:
    Value value;
    int level;  // for Andersson trees
    Node* left;
    Node* right;
    Node( const Value v = Value(), int lev = 1 ) 
      : value(v), level(lev), left(nil), right(nil)
    {}
    Value& content()  { return value; }
    bool isInternal() { return left != nil && right != nil; }
    bool isExternal() { return left != nil || right != nil; }
    bool isLeaf()     { return left == nil && right == nil; }
    int height() { 
      // returns the height of the subtree rooted at this node
      // FILL IN
      return 0;  // dummy return to suppress warnings
    }
    int size() {  
      // returns the size of the subtree rooted at this node, 
      // FILL IN
      return 0;  // dummy return to suppress warnings
    }
  }; // Node


  // const Node* nil;  // later nil will point to a sentinel node.
  int count;
  Node* root;
  
  void preorder(Node* n)const{
      if(n != nil){
          cout << n -> value << " ";
          preorder(n -> left);
          preorder(n -> right);
      }
  }
  
  void inorder(Node* n) const{

    if (n != nil){
        inorder(n -> left);
        cout << n-> value << " ";
        inorder(n -> right);
    }
 }
 
  void postorder(Node* n) const{

    if (n != nil){
        postorder(n -> left);
        postorder(n -> right);
        cout << n -> value << " ";
    }
 }
 
 void vectorInOrder(Node* n, vector<Node*> & nodeValues){

    if (n != nil){
        vectorInOrder(n -> left, nodeValues);
        nodeValues.push_back(n);
        vectorInOrder(n -> right, nodeValues);
    }
 }

  Node* atValue(int value) {
    static vector<Node*> nodeValues;
    
    vectorInOrder(root, nodeValues);
    
    return nodeValues.at(value);
 }

  int findValue(Value value){
      for (int i = 0; i < count; ++i){
          if (value == atValue(i)->value){
            return i;
        }
    }
    return -1;
  }
public:

  int size() {  
      return count -1 ;
  }
  
  bool empty() { return size() == 0; }

  void print_node( const Node* n ) {
    cout << n->value <<  " ";
  }

  bool search( Value x ) { 
    // search for a Value  in the BST and return true iff it was found.
    int value = findValue(x);
    if (value == -1){
        return false;
    }
    else{
        return true;
    }
  }

  void preorder()const {
    // Traverse and print the tree one Value per line in preorder.
    cout << "The values pre order is: ";
    preorder(root);
    cout << endl;
  }
  
  void postorder()const {
    // Traverse and print the tree one Value per line in postorder.
    cout << "The values post order is: ";
    postorder(root);
    cout << endl;
 }

  void inorder()const {
    // Traverse and print the tree one Value per line in inorder.
    cout << "The values in order is: ";
    inorder(root);
    cout << endl;
 }

  Value& operator[] (int n) { 
    Node* alpha = atValue(n);
    return alpha->value;
  }

  Tree() : count(0), root(nil) {}


  void insert( Value X ) { 
    root = insert( X, root );
    ++count;
    }
    
  Node* insert( Value X, Node* T ) {
    // The normal binary-tree insertion procedure ...  
    if (  T == nil ) {
      T = new Node( X ); // the only place that T gets updated.
    } else if ( X < T->value ) {
      T->left = insert( X, T->left );
    } else if ( X > T->value ) {
      T->right = insert( X, T->right );
    } else { 
      T->value = X;
    }

    // later, rebalancing code will be installed here

    return T;
  }

  void remove( Value X ) { 
      root = remove( X, root );
      --count;
    }
    
  Node* remove( Value X, Node* T ) {
    // The normal binary-tree removal procedure ...       
    // Weiss's code is faster but way more intricate.
    if (  T != nil ) {
      if ( X > T->value ) {
        T->right = remove( X, T->right );
      } else if ( X < T->value ) { 
        T->left = remove( X, T->left );
      } else {                                // X == T->value
        if ( T->right != nil ) {
          Node* x = T->right;
          while ( x->left != nil ) x = x->left;
          T->value = x->value;      // successor's value
          T->right = remove( T->value, T->right );
        } else if ( T->left != nil ) {

          Node* z = T->left;
          Node* x = T->left;
	  while ( x->right != nil ) {
	    z = x;
	    x = x->right;
	  }
          T->value = x->value;          // predecessor's value
          z->right = x->left;
          delete x;

//           Node* x = T->left;
//           while ( x->right != nil ) x = x->right;
//           T->value = x->value;          // predecessor's value
//           T->left = remove( T->value, T->left );

        } else {                             // *T is external
          delete T;
          T = nil;                   // the only updating of T
        }
      }
    }

    // later, rebalancing code will be installed here

    return T;
  }


  void display() { display( root ); }
  void display( Node* n ) { 
    // in-order traversal with indented display.
    static int depth = 0;
    ++ depth;
    if ( n == nil ) return;
    if ( n->right != nil ) 
      display(n->right);
    for( int i = 0; i != depth; ++i ) cout << "  ";
    cout << n->value << "-" << n->level << endl;
    if ( n->left != nil ) display(n->left);
    --depth;
  }


  void okay( ) { okay( root ); }
  void okay( Node* T ) { 
    // diagnostic code can be installed here
    T=0;  // dummy line to keep T from being unused.
    return; 
  }

};  // Tree


// ============== below is for testing ===============================

#ifdef TEST

int myrand() {  // a simple random number generator
  static unsigned long next = 3;
  next = next * 1103515245 + 12345;
  unsigned x = (unsigned) (next/65536) % 32768 ;
  return x % 100;
}


int main() {

  // This is a test routine to exercise the list.

  Tree<int> t;

  int n = 0;
  t.insert(3);
  cout << "Size is: " << t.size() << endl;
  for(int times = 0; times != 10; ++ times ) {
    
    int j = myrand();
    cerr << "inserting: " << j << endl;
    t.insert( j );
    cerr << "Traversing: " << ++n << "\n";
    t.display();
    cerr << "done\n";
    t.okay();

    //int k = myrand();
    //cerr << "removing: " << k << endl;
    //t.remove( k );
    //cerr<< "Traversing: " << ++n << "\n";
    //t.display();
    //cerr << "Done\n";
    //t.okay();
  }
    //t.remove(3);
    
    t.preorder();
    t.postorder();
    t.inorder();
    
    cout << "[0] is equal to: " << t[0] << endl;
    cout << "[4] is equal to: " << t[4] << endl;
    cout << "Size is: " << t.size() << endl;
    cout << "Find(3) is equal to: " << t.search(3) << endl;
    cout << "Find(0) is equal to: " << t.search(0) << endl;

} // main

#endif
#endif
