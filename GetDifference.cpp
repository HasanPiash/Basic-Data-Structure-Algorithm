#include <bits/stdc++.h> 
using namespace std;
class Node{
public:
    int val;
    Node *next;
    Node(int val){
        this->val=val;
        this->next=NULL;
    }
};
void insert_tail(Node *&head,Node *&tail,int v){
    Node *newNode=new Node(v);
    if(head==NULL){
        head=newNode;
        tail=newNode;
    }
    else{
        tail->next=newNode;
        tail=newNode;
    }
}
int max_min_diff(Node *head){
    if(head==NULL){
        return 0;
    }
    int maxVal=INT_MIN;
    int minVal=INT_MAX;
    Node *current=head;
    while(current!=NULL){
        if(current->val>maxVal){
            maxVal=current->val;
        }
        if(current->val<minVal){
            minVal=current->val;
        }
        current=current->next;
    }
    return maxVal-minVal;
}
int main(){
    int val;
    Node *head=NULL;
    Node *tail=NULL;
    while(true){
        cin>>val;
        if(val==-1){
            break;
        }
        insert_tail(head,tail,val);
    }
    int result=max_min_diff(head);
    cout<<result<<endl;
    return 0;
}
