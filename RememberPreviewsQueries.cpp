#include<bits/stdc++.h>
using namespace std;
class RemPrevQrs
{
public:
    class ListNode
    {
    public:
        int val;
        ListNode *prev;
        ListNode *next;
        ListNode(int x):val(x),prev(NULL),next(NULL){}
    };
    ListNode *head;
    ListNode *tail;
    RemPrevQrs():head(NULL),tail(NULL){}
    void insert_hd(int val){
        ListNode *newNode=new ListNode(val);
        if(!head){
            head=tail=newNode;
        }
        else{
            newNode->next=head;
            head->prev=newNode;
            head=newNode;
        }
    }
    void insert_tl(int val){
        ListNode *newNode=new ListNode(val);
        if (!tail){
            head =tail=newNode;
        }
        else{
            newNode->prev=tail;
            tail->next=newNode;
            tail=newNode;
        }
    }
    void delete_idx(int index){
        if(index<0)
        {
            return;
        }
        ListNode *tmp=head;
        for(int i=0; i<index && tmp; ++i){
            tmp=tmp->next;
        }
        if(!tmp)
        {
            return;
        }
        if(tmp->prev){
            tmp->prev->next=tmp->next;
        }
        else{
            head=tmp->next;
        }
        if(tmp->next){
            tmp->next->prev=tmp->prev;
        }
        else{
            tail=tmp->prev;
        }
        delete tmp;
    }
    void print_LtoR(){
        cout<<"L ->";
        ListNode *tmp=head;
        while(tmp){
            cout<<" "<<tmp->val;
            tmp=tmp->next;
        }
        cout<<endl;
    }
    void print_list_RtoL(){
        cout<<"R ->";
        ListNode *tmp=tail;
        while(tmp){
            cout<<" "<<tmp->val;
            tmp=tmp->prev;
        }
        cout<<endl;
    }
    bool Cycle(ListNode *head)
    {
        ListNode *slow=head;
        ListNode *fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)
            {
                return true;
            }
        }
        return false;
    }
    void prc_queries(){
        int Q;
        cin>>Q;
        for(int i=0; i<Q; ++i){
            int X,V;
            cin>>X>>V;
            if(X==0){
                insert_hd(V);
            }
            else if(X==1){
                insert_tl(V);
            }
            else if(X==2){
                delete_idx(V);
            }
            print_LtoR();
            print_list_RtoL();
        }
    }
};
int main()
{
    RemPrevQrs rpq;
    rpq.prc_queries();
    return 0;
}
