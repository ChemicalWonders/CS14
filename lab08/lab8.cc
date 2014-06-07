//Name: Kevin Chan
//Lab Time: 8AM to 11AM

#include <iostream>
#include <vector>
#include <queue>
using namespace std;


//Problem #1
    // What is the maximum number of edges a bipartite graph on n vertices can have?
    // A mathematical proof is required.
    
    /*
     * A bipartite graph on n vertices can have at most 1/4 n^2 edges.
     * 
     * Proof: Suppose the bipartition is (V1, V2) and |V1| = k, |V2| = n-k.
     * The number of edges between V1 and V2 can be at most k(n-k), which
     * is maximized for k = n/2.
     */
    
    
//Problem #2
    // Show that every tree is bipartite.
    
    /*
     * Every tree T contains a vertex v of degree 1, and that T - v is also a tree.
     * Now we process by induction on the number n vertices of tree T.
     * For n = 1, 2, the only trees are K1 and K3 and both are bipartite.
     * Suppose that any tree on less than n vertices are bipartite and let T be a tree on n vertices.
     * 
     * Let v be a vertex of degree 1 in T and let u be its only neighbor. We know that T-v is a tree with
     * n-1 vertices, so by induction assumption T-v has bipartition X,Y.
     * This means that ever edge in T-v has one endpoint in X and the other one in Y.
     * Now if u for ever x, than X,Y U{v} is a bipartition of T. However, if u for ever Y,
     * than Y, X U {v} is a bipartition of T.
     */
    
//Problem #3
    //Write a program to find the strongly connected components in a digraph.

#define MAXV 1000
typedef vector <int> vi;
 
// Assuming vertices are labeled 0...V-1
vi G[MAXV], Grev[MAXV];
bool explored[MAXV];
int leader[MAXV], finish[MAXV], order[MAXV], t = -1, parent = 0, V, E;
 
// running DFS on the reverse graph
void dfs_reverse(int i) {
    explored[i] = true;
    for(vi::iterator it = Grev[i].begin(); it != Grev[i].end(); it++)
        if(!explored[*it])
            dfs_reverse(*it);
    t++;
    finish[i] = t;
}
 
// running DFS on the actual graph
void dfs(int i) {
    explored[i] = true;
    leader[i] = parent;
    for(vi::iterator it = G[i].begin(); it != G[i].end(); it++)
        if(!explored[*it])
            dfs(*it);
}
 
// check if u & v are in the same connected component
bool stronglyConnected(int u, int v)    {
    return leader[u] == leader[v];
}


//Problem #6
    // Give a linear algorithm to determine whether a graph is bipartite.

#define V 4
    // This function returns true if graph G[V][V] is Bipartite, else false
bool isBipartite(int G[][V], int src)
{
    // Create a color array to store colors assigned to all veritces. Vertex
    // number is used as index in this array. The value '-1' of  colorArr[i]
    // is used to indicate that no color is assigned to vertex 'i'.  The value
    // 1 is used to indicate first color is assigned and value 0 indicates
    // second color is assigned.
    int colorArr[V];
    for (int i = 0; i < V; ++i)
        colorArr[i] = -1;
 
    // Assign first color to source
    colorArr[src] = 1;
 
    // Create a queue (FIFO) of vertex numbers and enqueue source vertex
    // for BFS traversal
    queue <int> q;
    q.push(src);
 
    // Run while there are vertices in queue (Similar to BFS)
    while (!q.empty())
    {
        // Dequeue a vertex from queue ( Refer http://goo.gl/35oz8 )
        int u = q.front();
        q.pop();
 
         // Find all non-colored adjacent vertices
        for (int v = 0; v < V; ++v)
        {
            // An edge from u to v exists and destination v is not colored
            if (G[u][v] && colorArr[v] == -1)
            {
                // Assign alternate color to this adjacent v of u
                colorArr[v] = 1 - colorArr[u];
                q.push(v);
            }
 
            //  An edge from u to v exists and destination v is colored with
            // same color as u
            else if (G[u][v] && colorArr[v] == colorArr[u])
                return false;
        }
    }
 
    // If we reach here, then all adjacent vertices can be colored with
    // alternate color
    return true;
}


int main()
{
    return 0;
}
