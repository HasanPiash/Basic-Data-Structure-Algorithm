#include<bits/stdc++.h>
using namespace std;
int dp[1005][1005];
int ExamMarks(int N,int wght[],int W){
    if(N==0 || W==0){
        return 0;
    }
    if(dp[N][W]!=-1){
        return dp[N][W];
    }
    if(wght[N-1]<=W){
        int op1=ExamMarks(N-1,wght,W-wght[N-1])+wght[N-1];
        int op2=ExamMarks(N-1,wght,W);
        return dp[N][W]=max(op1,op2);
    }
    else{
        return dp[N][W]=ExamMarks(N-1,wght,W);
    }
}
int main(){
    int T;
    cin>>T;
    while(T--){
        int N,M;
        cin>>N>>M;
        int wght[N];
        for(int i=0; i<N; i++){
            cin>>wght[i];
        }
        int trgt=1000-M;
        if(trgt<=0)
        {
            cout<<"YES"<<endl;
            continue;
        }
        for(int i=0; i<=N; i++){
            for(int j=0; j<=trgt; j++){
                dp[i][j]=-1;
            }
        }
        if(ExamMarks(N,wght,trgt)==trgt)
        {
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }   
    return 0;
}
