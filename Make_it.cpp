#include<bits/stdc++.h>
using namespace std;
int main(){
    int MX_N=100000;
    vector<bool>rcbl(MX_N+1,false);
    queue<int>Q;
    Q.push(1);
    rcbl[1]=true;
    while(!Q.empty()){
        int crrnt=Q.front();
        Q.pop();
        int add3=crrnt+3;
        int mult2=crrnt*2;
        if(add3<=MX_N && !rcbl[add3]){
            Q.push(add3);
            rcbl[add3]=true;
        }
        if (mult2<= MX_N && !rcbl[mult2]){
            Q.push(mult2);
            rcbl[mult2]=true;
        }
    }
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        if(rcbl[N]){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }   
    return 0;
}
