#include <iostream>
#include <climits>

using namespace std;

#define V 6  // # number of vertices in the graph

int minimumKey(int key[], bool setMst[])
{
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; ++v)
    {
        if (setMst[v] == false && key[v] < min)
        {
            min = key[v];
            min_index = v;
        }
    }

    return min_index;
}

// Construct the MST using prim's algorithm
void prims_MST(int graph[V][V])
{
    int parent[V];  
    int key[V];     
    bool setMst[V]; 

    // Initialize all keys as infinite and setMst[] as false
    for (int i = 0; i < V; ++i)
    {
        key[i] = INT_MAX;
        setMst[i] = false;
    }

    // include the first vertex in graph
    key[0] = 0;      
    parent[0] = -1;  // First node is always the root of MST

    // MST will have V vertices
    for (int count = 0; count < V - 1; ++count)
    {
        int u = minimumKey(key, setMst);

        setMst[u] = true;

        // Update key values 
        // Consider only vertices not yet included in the MST
        for (int v = 0; v < V; ++v)
        {
            if (graph[u][v] && setMst[v] == false && graph[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Print the constructed MST
    cout << "Edge\n";
    cout << endl;
    for (int i = 1; i < V; ++i)
    {
        cout <<"("<< parent[i] << ","<< i <<")"<< endl;
    }
}



int main()
{
    
    int graph[V][V] = {
        {0, 3, 0, 0, 0,1},
        {3, 0, 2, 1, 10,0},
        {0, 2, 0, 3, 0,5},
        {0, 1, 3, 0, 5,0},
        {0, 10, 0, 5, 0,4},
        {1, 0 , 5, 0, 4, 0}
    };

    // Prims MST for the above graph with starting node = 0
    prims_MST(graph);

    return 0;
}
