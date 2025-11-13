#include<iostream>
#include<queue>
#include<vector>
using namespace std;
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
    queue<int> q;
    int startNode;
    cin>>startNode;
    visited[startNode]=true;
    q.push(startNode);
    while(!q.empty()){
        int node=q.front();
        q.pop();
        cout<<node<<" ";
        for(int neighbout:adj[node]){
            if(!visited[neighbout]){
                visited[neighbout]=true;
                q.push(neighbout);
            }
        }
    }
    return 0;
}