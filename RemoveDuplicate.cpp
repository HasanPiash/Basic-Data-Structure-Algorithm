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
    void insertEnd(int val){
        Node *newNode=new Node(val);
        if(head==NULL){
            head=newNode;
        }
        else{
            Node *temp=head;
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=newNode;
        }
    }
    void removeDplcts(){
        Node *crnt=head;
        while(crnt!=NULL){
            Node * rnr=crnt;
            while(rnr->next!=NULL){
                if( rnr->next->val==crnt->val)
                {
                    Node *duplicateNode= rnr->next;
                    rnr->next= rnr->next->next;
                    delete duplicateNode;
                }
                else{
                     rnr=rnr->next;
                }
            }
            crnt=crnt->next;
        }
    }
    void pList(){
        Node *temp=head;
        while(temp!=NULL)
        {
            cout<<temp->val<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
};
int main(){
   LnkdList list;
    int value;
    while(true){
        cin>>value;
        if(value==-1)
        {
            break;
        }
        list.insertEnd(value);
    }
    list.removeDplcts();
    list.pList();
    return 0;
}
