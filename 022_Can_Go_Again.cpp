#include<bits/stdc++.h>
using namespace std;
class CanGoAgain{
public:
    int A,B,W;
    CanGoAgain(int A,int B,int W):A(A),B(B),W(W){}
};
const int MX_NODES=1005;
vector<CanGoAgain>edges;
long long dst[MX_NODES];
bool NgtvCycle=false;
void bellmanFord(int srce,int n){
    for(int i=1; i<=n; i++){
        dst[i]=LLONG_MAX;
    }
    dst[srce]=0;
    for(int i=1; i<n; i++){
        for(const CanGoAgain& CanGoAgain : edges){
            if(dst[CanGoAgain.A]!=LLONG_MAX && dst[CanGoAgain.A]+ CanGoAgain.W< dst[CanGoAgain.B]){
                dst[CanGoAgain.B]=dst[CanGoAgain.A]+CanGoAgain.W;
            }
        }
    }
    for(const CanGoAgain& CanGoAgain : edges){
        if(dst[CanGoAgain.A]!=LLONG_MAX && dst[CanGoAgain.A]+CanGoAgain.W<dst[CanGoAgain.B]){
            NgtvCycle=true;
            break;
        }
    }
}
int main(){
    int N,E;
    cin>>N>>E;
    for(int i=0; i<E; i++){
        int A,B,W;
        cin>>A>>B>>W;
        edges.push_back(CanGoAgain(A,B,W));
    }
    int srce;
    cin>>srce;
    bellmanFord(srce,N);
    if(NgtvCycle){
        cout<<"Negative Cycle Detected"<<endl;
        return 0; 
    }
    int T;
    cin>>T;
    while(T--){
        int dest;
        cin>>dest;
        if(dst[dest]==LLONG_MAX){
            cout<<"Not Possible"<< endl;
        }
        else{
            cout<<dst[dest]<<endl;
        }
    }
    return 0;
}
