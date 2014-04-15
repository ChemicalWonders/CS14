#ifndef __NODE_H_
#define __NODE_H_

#include <iostream>

using namespace std;

struct Node {
		char value;
		Node* next;
		Node(): value(), next (0){};
		Node(char a): value(a), next(0){};
};
#endif
