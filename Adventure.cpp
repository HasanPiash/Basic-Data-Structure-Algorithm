#include<bits/stdc++.h> 
using namespace std;
int main(){
    int T;
    cin>>T;
    while(T--){
        int N,W;
        cin>>N>>W;
        vector<int>wghts(N);
        vector<int>vals(N);
        for(int i=0; i<N; ++i){
            cin>>wghts[i];
        }
        for(int i=0; i<N; ++i){
            cin>>vals[i];
        }
        vector<int>dp(W+1,0);
        for(int i=0; i<N; ++i){
            for(int j=W; j>=wghts[i]; --j){
                dp[j]=max(dp[j],dp[j-wghts[i]]+vals[i]);
            }
        }
        cout<<dp[W]<<endl;
    }   
    return 0;
}
