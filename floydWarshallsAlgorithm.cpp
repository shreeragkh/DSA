#include<iostream>
using namespace std;
#define INF 1e9
int main(){
    int n,m;
    cin>>n>>m;
    int dist[n][n];
    for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++)
    {
        if(i==j){
            dist[i][j]=0;
        }
        else{
            dist[i][j]=INF;
        }
    }
}
    for(int i=0;i<m;i++){
            int u,v,w;
            cin>>u>>v>>w;
            dist[u][v]=w;
    }
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if(dist[i][k]+dist[k][j]<dist[i][j]){
                    dist[i][j]=dist[i][k]+dist[k][j];
                }
            }
            
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(dist[i][j]==INF){
                cout<<"INF"<<" ";
            }
            else{
                cout<<dist[i][j]<<" ";
            }
        }
        cout<<endl;
    }   
    return 0;
    
    
} 
