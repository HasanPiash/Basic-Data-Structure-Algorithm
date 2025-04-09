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
class LnkdList{
private:
    Node *head;
public:
    LnkdList(){
        head=NULL;
    }
    void insertHd(int v){
        Node *newNode=new Node(v);
        newNode->next=head;
        head=newNode;
    }
    void insertTail(int v){
        Node *newNode=new Node(v);
        if(head==NULL){
            head=newNode;
            return;
        }
        Node *tmp=head;
        while(tmp->next!=NULL){
            tmp=tmp->next;
        }
        tmp->next=newNode;
    }
    void delete_Idx(int idx){
        if(head==NULL){
            return;
        }
        if(idx==0){
            Node *temp=head;
            head=head->next;
            delete temp;
            return;
        }
        Node *tmp=head;
        int count=0;
        while(tmp!=NULL&&count<idx-1){
            tmp=tmp->next;
            count++;
        }
        if(tmp==NULL||tmp->next==NULL){
            return;
        }
        Node *nextNode=tmp->next->next;
        delete tmp->next;
        tmp->next=nextNode;
    }  
    void pList(){
        Node *tmp=head;
        while(tmp!=NULL)
        {
            cout<<tmp->val<<" ";
            tmp=tmp->next;
        }
        cout<<endl;
    }
};
int main(){
    LnkdList list;
    int Q;
    cin >> Q;
    for(int i=0; i<Q; ++i){
        int X,V;
        cin>>X>>V;
        if(X==0){
            list.insertHd(V);
        }
        else if(X==1){
            list.insertTail(V);
        }
        else if(X==2){
            list.delete_Idx(V);
        } 
        list.pList();
    }  
    return 0;
}
