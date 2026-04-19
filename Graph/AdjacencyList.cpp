#include<iostream>
#include<vector>
#include <queue>
using namespace std;
class AdjacencyList
{
public:
int V;
 vector<vector<int>> adj;
 AdjacencyList(int v_count){
    this->V=v_count;
    adj.resize(V);

 }

 void addEdge(int u, int v){
    adj[u].push_back(v);
 }
 void printGraph(){
    for (int i = 0; i < V; i++)
    {
        cout<<i<<":";
        for(int i:adj[i]){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    
 }
  void bfs(){
    queue<int> q;
    vector<bool> vis(V,false);
    q.push(0);
    vis[0]=true;
    while (q.size()>0)
    {
        int u=q.front();
        q.pop();
        cout<<u<<":";
        for(int val:adj[u]){
            if(!vis[val]){
                vis[val]=true;
                q.push(val);
            }
        }
    }
    cout<<endl;
    
  }  
};
int main(){
    AdjacencyList g(5);
    g.addEdge(0,1);
    g.addEdge(1,0);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,1);
    g.addEdge(2,3);
    g.addEdge(3,1);
    g.addEdge(3,2);
    g.printGraph();
}
