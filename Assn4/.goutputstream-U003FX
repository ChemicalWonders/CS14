#include <set>
#include <iostream>
#ifndef _MYMAP_H_
#define _MYMAP_H_

using namespace std;

template< typename Key, typename T >
class map_pair { 
public:
  const Key first;
  mutable T second;
  map_pair( Key s, T t ) : first(s), second(t) {}
}; // end of map_pair


template< typename Key, typename T >
struct classcomp {
  typedef map_pair< const Key, T > Pair;                  // short name
  bool operator() ( const Pair& lhs, const Pair& rhs ) const {
    return lhs.first < rhs.first;
  }
}; // end classcomp


template < typename Key, typename T >
class mymap {
public:

  typedef map_pair< const Key, T > Pair;                  // short name
  typedef set< Pair, classcomp< const Key, T> > PairSet;  // short name
  
  PairSet theSet;
  
  // THIS IS THE DEFAULT CONSTRUCTOR
  mymap():theSet() {}
  
  //COPY CONSTRUCTOR
  mymap(const mymap &m){
      theSet(m);
  }
  //DESTRUCTOR
  ~mymap(){
      theSet.clear();
  }
  // Iterator for End
  typename PairSet::iterator end(){
      return theSet.end();
  }
  //ASSIGNMENT OPERATOR, same as COPY CONSTRUCTOR
  mymap& operator=(mymap & m){
      return theSet(m);
  }
  // FIND FUNCTION
  typename PairSet::iterator find( const Key& x ) const { 
    return theSet.find( Pair( x, T() ) );        
  }
  // [] OPERATOR
  T& operator[]( const Key x ) {
    pair<typename PairSet::iterator,bool> i = insert( Pair(x,T()) );
    return i.first->second;
  }
  
  pair<typename PairSet::iterator, bool> insert( Pair p ) {
    return theSet.insert( p );
  }

}; // end of mymap

#endif
