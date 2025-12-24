#include<bits/stdc++.h> 
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
    bool SameSame(LnkdList other){
        Node *crnt1=head;
        Node *crnt2=other.head;
        while(true){
            if(crnt1==NULL){
                if(crnt2==NULL)
                {
                    return true;
                }
                else{
                    return false;
                }
            }
            else{
                if(crnt2==NULL)
                {
                    return false;
                }
                else{
                    if(crnt1->val!=crnt2->val)
                    {
                        return false;
                    }
                    else{
                        crnt1=crnt1->next;
                        crnt2=crnt2->next;
                    }
                }
            }
        }
        return true; 
    }
};
int main(){
    LnkdList list1,list2;
    int value;
    while(true){
        cin>>value;
        if(value==-1)
        {
            break;
        }
        list1.insertEnd(value);
    }
    while(true){
        cin>>value;
        if(value==-1)
        {
            break;
        }
        list2.insertEnd(value);
    }
    if (list1.SameSame(list2)){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    return 0;
}
