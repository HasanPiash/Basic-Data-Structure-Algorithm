#include<bits/stdc++.h> 
using namespace std;
int knightMoves[8][2]={
    {2,1},{2,-1},{-2,1},{-2,-1},{1,2},{1,-2},{-1,2},{-1,-2}
};
bool Valid(int x,int y,int N,int M){
    return(x>=0 && x<N && y>=0 && y<M);
}
int bfs(int N,int M,int Ki,int Kj,int Qi,int Qj){
    vector<vector<bool>>vstd(N,vector<bool>(M,false));
    queue<pair<pair<int,int>,int>>Q;
    Q.push({{Ki,Kj},0});
    vstd[Ki][Kj]=true;
    while(!Q.empty()){
        pair<pair<int,int>,int>crnt=Q.front();
        Q.pop();
        int x=crnt.first.first;
        int y=crnt.first.second;
        int steps=crnt.second;
        if(x==Qi && y==Qj){
            return steps;
        }
        for(int i=0; i<8; i++){
            int newX=x+knightMoves[i][0];
            int newY=y+knightMoves[i][1];
            if(Valid(newX,newY,N,M) && !vstd[newX][newY]){
                vstd[newX][newY]=true;
                Q.push({{newX,newY},steps+1});
            }
        }
    }
    return -1;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        int N,M;
        cin>>N>>M;
        int Ki,Kj;
        cin>>Ki>>Kj;
        int Qi,Qj;
        cin>>Qi>>Qj;
        if(Ki==Qi && Kj==Qj){
            cout<<0<<endl;
        }
        else{
            cout<<bfs(N,M,Ki,Kj,Qi,Qj)<<endl;
        }
    }
    return 0;
}
