#include <bits/stdc++.h> 
using namespace std;
class BrowserHistory
{
public:
    class LNode
    {
    public:
        string val;
        LNode *prev;
        LNode *next;
        LNode(string x):val(x),prev(NULL),next(NULL){}
    };
    LNode *head;
    LNode *tail;
    LNode *crnt;
    BrowserHistory():head(NULL),tail(NULL),crnt(NULL){}
    void b_list()
    {
        string value;
        while(cin>>value && value!="end"){
            LNode *newNode=new LNode(value);
            if(!head){
                head=tail=newNode;
            }
            else{
                tail->next=newNode;
                newNode->prev=tail;
                tail=newNode;
            }
        }
        crnt=head;
    }
    void process_cmnd(int Qrs){
        for(int i=0; i<Qrs; ++i){
            string cmnd;
            cin>>cmnd;
            if(cmnd=="visit"){
                string addrs;
                cin>>addrs;
                visit(addrs);
            }
            else if(cmnd=="next"){
                next();
            }
            else if(cmnd=="prev"){
                prev();
            }
            else if(cmnd=="Cycle"){
                if(Cycle(head)){
                    cout<<"Cycle detected"<<endl;
                }
                else{
                    cout<<"No cycle"<<endl;
                }
            }
        }
    }
    void visit(string &addrs){
        LNode *tmp=head;
        while(tmp){
            if(tmp->val==addrs){
                crnt=tmp;
                cout<<crnt->val<<endl;
                return;
            }
            tmp=tmp->next;
        }
        cout<<"Not Available"<<endl;
    }
    void next(){
        if(crnt && crnt->next){
            crnt=crnt->next;
            cout<<crnt->val<<endl;
        }
        else{
            cout<<"Not Available"<<endl;
        }
    }
    void prev(){
        if(crnt && crnt->prev)
        {
            crnt=crnt->prev;
            cout<<crnt->val<<endl;
        }
        else{
            cout<<"Not Available"<<endl;
        }
    }
    bool Cycle(LNode *head){
        LNode *slow=head;
        LNode *fast=head;
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)
            {
                return true;
            }
        }
        return false;
    }
};
int main()
{
    BrowserHistory brsr_histr;
    brsr_histr.b_list();
    int Qrs;
    cin >> Qrs;
    brsr_histr.process_cmnd(Qrs);
    return 0;
}
