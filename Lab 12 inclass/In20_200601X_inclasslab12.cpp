#include <iostream>
using namespace std;

int IndexWithminiDist(int distance[], bool visited[]) 
{
    int minimum=INT_MAX;
    int index;
              
    for(int i=0;i<6;i++) 
    {
        if(visited[i]==false && distance[i]<=minimum)      
        {
            minimum=distance[i];
            index=i;
        }
        
    }
    return index;
}

void DijkstraAlgo(int graph[6][6],int source_vetrex) 
{
    int distance[6];                            
    bool visited[6];
    
     
    for(int k = 0; k<6; k++)
    {
        distance[k] = INT_MAX;
        visited[k] = false;    
    }
    
    distance[source_vetrex] = 0;             
    
    for(int k = 0; k<6; k++)                           
    {
        int v=IndexWithminiDist(distance,visited); //get the unvisited vertex with minimum distance
        visited[v]=true;
        
        
        for(int u = 0; u<6; u++)                  
        {
            if(visited[u]==false){ // vertices which have not yet been visited
                if(graph[v][u]>0){ //neighbours of vertex v
                
                    if(distance[v]+graph[v][u]< distance[u]){
                        distance[u]=distance[v]+graph[v][u];
                    }
                }
            }
            
        }
        
    }
    float average=0;
    for(int k = 0; k<6; k++)                      
    { 
        
        if(k!=source_vetrex){
            cout<<"shortest time between City "<<source_vetrex<<" to City "<< k << " = "<<distance[k] <<endl;
            average+=distance[k];
        }
               
    }
    average=average/6;
        cout<< "Average Time = "<<average<<endl;
}


int main()
{
    int graph[6][6]={
        { 0,10, 0, 0,15, 5},
        {10, 0,10,30, 0, 0},
        { 0,10, 0,12, 5, 0},
        { 0,30,12, 0, 0,20},
        {15, 0, 5, 0, 0, 0},
        { 5, 0, 0,20, 0, 0}
        };
    for(int k = 0; k<6; k++)                      { 
        DijkstraAlgo(graph,k);
        cout<<endl;
    }
    return 0;    
}