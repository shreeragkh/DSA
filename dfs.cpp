#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void dfsUtil(int node, vector<vector<int>>& adj, vector<bool>& visited){
    visited[node]=true;
    cout<<node<<" ";
    for(int neighbour: adj[node]){
        if(!visited[neighbour]){
            dfsUtil(neighbour,adj,visited);
        }
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool> visited(n,false);
    int startNode;
    cin>>startNode;
    dfsUtil(startNode,adj,visited);
    return 0;
}