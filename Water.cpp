#include<bits/stdc++.h>
using namespace std;
void Water(const vector<int>& hghts){
    int lrgst=-1,secondLrgst=-1;
    for(int hght:hghts)
    {
        if(hght>lrgst)
        {
            secondLrgst=lrgst;
            lrgst =hght;
        }
        else if(hght>secondLrgst && hght!=lrgst){
            secondLrgst=hght;
        }
    }
    size_t firstIndex=hghts.size(),secondIndex=hghts.size();
    for(size_t i=0; i<hghts.size(); i++){
        if(hghts[i]==lrgst && firstIndex==hghts.size()){
            firstIndex=i;
        }
        else if(hghts[i]==secondLrgst && secondIndex==hghts.size()){
            secondIndex=i;
        }
    }
    if(firstIndex>secondIndex){
        swap(firstIndex,secondIndex);
    }
    cout<<firstIndex<<" "<<secondIndex<<endl;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        vector<int>hghts(N);
        for(int i=0; i<N; i++){
            cin>>hghts[i];
        }
        Water(hghts);
    }
    return 0;
}
