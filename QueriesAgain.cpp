#include<bits/stdc++.h>
using namespace std;
class QrsAgain
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
    QrsAgain():head(NULL),tail(NULL){}
    void insert_idx(int index,int val){
        if(index<0){
            cout<<"Invalid"<<endl;
            return;
        }
        ListNode *newNode=new ListNode(val);
        if(index==0){
            if(!head){
                head=tail=newNode;
            }
            else{
                newNode->next=head;
                head->prev=newNode;
                head=newNode;
            }
        }
        else{
            ListNode *tmp=head;
            int i=0;
            while(tmp && i<index-1)
            {
                tmp=tmp->next;
                i++;
            }
            if(i==index-1 && tmp){
                if(tmp->next){
                    newNode->next=tmp->next;
                    tmp->next->prev=newNode;
                }
                else{
                    tail=newNode;
                }
                tmp->next=newNode;
                newNode->prev=tmp;
            }
            else{
                cout<<"Invalid"<<endl;
                delete newNode;
                return;
            }
        }
        print_listLtoR();
        print_listRtoL();
    }
    void print_listLtoR(){
        cout<<"L ->";
        ListNode *tmp=head;
        while(tmp)
        {
            cout<<" "<<tmp->val;
            tmp=tmp->next;
        }
        cout<<endl;
    }
    void print_listRtoL(){
        cout<<"R ->";
        ListNode *tmp=tail;
        while(tmp){
            cout<<" "<<tmp->val;
            tmp=tmp->prev;
        }
        cout<<endl;
    }
    void process_qrs()
    {
        int Qrrs;
        cin>>Qrrs;
        for(int i=0; i<Qrrs; ++i)
        {
            int X,V;
            cin>>X>>V;
            insert_idx(X,V);
        }
    }
};
int main()
{
    QrsAgain qrs_agn;
    qrs_agn.process_qrs();
    return 0;
}
