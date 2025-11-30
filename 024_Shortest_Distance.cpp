#include<bits/stdc++.h> 
#define ll long long int
using namespace std;
int main(){
    ll N,E;
    cin>>N>>E;  
    ll adj[N][N];
    ll large_val=1e18;
    for(ll i=0; i<N; i++){
        for(ll j=0; j<N; j++){
            if(i==j){
                adj[i][j]=0;
            }
            else{
                adj[i][j]=large_val;
            }
        }
    }   
    for(ll i=0; i<E; i++){
        ll A,B,W;
        cin>>A>>B>>W;
        A--;
        B--;
        adj[A][B]=min(adj[A][B],W);
    }  
    for(ll k=0; k<N; k++){
        for(ll i=0; i<N; i++){
            for(ll j=0; j<N; j++){
                if(adj[i][k]<large_val && adj[k][j]<large_val){
                    adj[i][j]=min(adj[i][j],adj[i][k]+adj[k][j]);
                }
            }
        }
    }
    ll Q;
    cin>>Q;
    while (Q--){
        ll X,Y;
        cin>>X>>Y;
        X--;
        Y--;
        if(adj[X][Y]==large_val){
            cout<<-1<<endl;  
        }
        else{
            cout<<adj[X][Y]<<endl;
        }
    }
    return 0;
}
