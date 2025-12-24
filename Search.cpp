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
int find_idx(Node *head,int X){
    int idx=0;
    Node *crnt=head;
    while(crnt!=NULL){
        if(crnt->val==X){
            return idx;
        }
        crnt=crnt->next;
        idx++;
    }
    return -1;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        Node *head=NULL;
        Node *tail=NULL;
        int val;
        while(true){
            cin>>val;
            if(val==-1)
                break;
            insert_tail(head,tail,val);
        }
        int X;
        cin>>X;    
        int result=find_idx(head, X);
        cout<<result<<endl;
    }   
    return 0;
}
