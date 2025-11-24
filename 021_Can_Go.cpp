#include<bits/stdc++.h>
using namespace std; 
const int N=1005;
const long long INFT=1e18;
vector<pair<int,int>>adj[N];
long long dist[N];
void CanGo(int src,int n){
    priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>dw;
    for(int i=0; i<=n; i++){
        dist[i]=INFT;
    }
    dist[src]=0;
    dw.push(make_pair(0,src));
    while(!dw.empty()){
        pair<long long,int>prnt=dw.top();
        dw.pop();
        long long d=prnt.first;
        int u=prnt.second;
        if(d>dist[u]) continue;
        for(size_t i=0; i<adj[u].size(); i++){
            int v=adj[u][i].first;
            int weight=adj[u][i].second;
            if(dist[u]+weight<dist[v]){
                dist[v]=dist[u]+weight;
                dw.push(make_pair(dist[v],v));
            }
        }
    }
}
int main(){
    int N,E;
    cin>>N>>E;
    for(int i=0; i<E; i++){
        int A,B,W;
        cin>>A>>B>>W;
        adj[A].push_back(make_pair(B,W));
    }
    int source;
    cin>>source;
    CanGo(source,N);
    int T;
    cin>>T;
    while(T--){
        int dest;
        long long mxCst;
        cin>>dest>>mxCst;
        if(dist[dest]<=mxCst){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}
