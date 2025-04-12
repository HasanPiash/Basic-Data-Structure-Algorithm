#include<bits/stdc++.h>
using namespace std;
class SameOrNot{
public:
    stack<int>inputStk,outputStk;
    SameOrNot(){}
    void push(int x)
    {
        inputStk.push(x);
    }
    int pop(){
        if(outputStk.empty()){
            while(!inputStk.empty())
            {
                outputStk.push(inputStk.top());
                inputStk.pop();
            }
        }
        int topValue=outputStk.top();
        outputStk.pop();
        return topValue;
    }
    int peek(){
        if(outputStk.empty()){
            while(!inputStk.empty())
            {
                outputStk.push(inputStk.top());
                inputStk.pop();
            }
        }
        return outputStk.top();
    }
    bool empty(){
        return inputStk.empty() && outputStk.empty();
    }
};
void check_stk_q_same(int n,int m,vector<int>& stack_val,vector<int>& queue_val){
    stack<int>s;
    for(int i=0; i<n; ++i){
        s.push(stack_val[i]);
    }
    vector<int>stk_sequence;
    while(!s.empty()){
        stk_sequence.push_back(s.top());
        s.pop();
    }
    SameOrNot s_n;
    for(int i=0; i<m; ++i){
        s_n.push(queue_val[i]);
    }
    vector<int>q_sequence;
    while(!s_n.empty()){
        q_sequence.push_back(s_n.pop());
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
