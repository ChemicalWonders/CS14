#ifndef __PRIM_H_
#define __PRIM_H_

#include <iostream>
#include <cstdlib>
#include <cstddef>
#include <vector>
#include <set>

using namespace std;

class Edge {
    public:
        int end1;
        int end2;
        float weight;
        
    // Constructors
        Edge(int a, int b, float c)
        : end1(a), end2(b), weight(c)
        {}
        
        Edge()
        : end1(0), end2(0), weight(0)
        {}
};

bool operator<( Edge e1, Edge e2) { 
  return (
    ( e1.weight < e2.weight ) ||
    ( e1.weight == e2.weight && e1.end1 < e2.end1 ) ||
    ( e1.weight == e2.weight && e1.end1 == e2.end1 && e1.end2 < e2.end2 )
  );
}



typedef set<Edge> Graph;

Graph insertEdge (Edge a, Graph & g ) {
    g.insert(a);
}

Graph prim (const Graph & g){
    
    vector<Edge> worklist;
    Graph results;
    
    set<Edge>::iterator m;
    
    for(m = g.begin(); m != g.end(); ++m)
        worklist.push_back(*m);
    
    results.insert(worklist.at(0));
    
    for(int i = 1; i < worklist.size(); ++i){
        if (results.find(worklist.at(i)) != results.end())
        {
            ++i;
        }
        
        else if (results.find(worklist.at(i)) == results.end())
        {
            results.insert(worklist.at(i));
            ++i;
        }
    }
    
    return results;
}

void display (Graph & a){
    
    set<Edge>::iterator it;
    
    for (it = a.begin(); it != a.end(); ++it){
        cout << "Start Node: " << it->end1 << endl;
        cout << "End Node: " << it->end2 << endl;
        cout << "Length: " << it->weight << endl;
        cout << endl;
    }
    
}

#endif
