#include <bits/stdc++.h>
using namespace std;
int main(){
    int T; 
    cin>>T;
    while(T--){
        int N; 
        cin>>N;
        int a[N]; 
        int ttl=0;
        for(int i=0; i<N; i++){
            cin>>a[i];
            ttl+=a[i];
        }
        if(ttl %2!=0)
        {
            cout<<"NO"<<endl;
            continue;
        }
        int S=ttl/2;
        bool DPrg[N+1][S+1];
        DPrg[0][0]=true;
        for(int i=1; i<=S; i++)
        {
            DPrg[0][i]=false; 
        }
        for(int i=1; i<=N;i++){
            for(int j=0; j<=S; j++){
                if(a[i-1]<=j)
                {
                    DPrg[i][j]=DPrg[i-1][j-a[i-1]] || DPrg[i-1][j];
                }
                else{
                    DPrg[i][j]=DPrg[i-1][j];
                }
            }
        }
        if(DPrg[N][S])
        {
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}
