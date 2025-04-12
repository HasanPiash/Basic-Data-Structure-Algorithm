#include<bits/stdc++.h>
using namespace std;
class SameOrNotII{
public:
    vector<int>stkData; 
    vector<int>qData;  
    size_t qFrontIdx=0;  
    void pushStk(int val){
        stkData.push_back(val);
    }
    void popStk(){
        stkData.pop_back();
    }
    int topStk(){
        return stkData.back();
    }
    bool emptyStk(){
        return stkData.empty();
    }
    void pushQ(int val){
        qData.push_back(val);
    }
    void popQ(){
        qFrontIdx++;
    }
    int frontQ(){
        return qData[qFrontIdx];
    }
    bool emptyQ(){
        return qFrontIdx>=qData.size();
    }
};
void check_stk_q_same(int n,int m,vector<int>& stack_val,vector<int>& queue_val){
   SameOrNotII s_n;
    for(int i=0; i<n; ++i){
        s_n.pushStk(stack_val[i]);
    }
    vector<int>stk_sequence;
    while(!s_n.emptyStk()){
        stk_sequence.push_back(s_n.topStk());
        s_n.popStk();
    }
    for(int i=0; i<m; ++i){
        s_n.pushQ(queue_val[i]);
    }
    vector<int>q_sequence;
    while(!s_n.emptyQ()){
        q_sequence.push_back(s_n.frontQ());
        s_n.popQ();
    }
    if(stk_sequence==q_sequence){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<int>stack_val(n);
    vector<int>queue_val(m);
    for(int i=0; i<n; ++i){
        cin>>stack_val[i];
    }
    for(int i=0; i<m; ++i){
        cin>>queue_val[i];
    }
    check_stk_q_same(n,m,stack_val,queue_val);
    return 0;
}
