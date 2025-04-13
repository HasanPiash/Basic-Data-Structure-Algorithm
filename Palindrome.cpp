#include <bits/stdc++.h>
using namespace std;
class DoublyLinkedList{
public:
    class Node{
    public:
        int val;
        Node* next;
        Node* prev;
        Node(int val):val(val),next(NULL),prev(NULL){}
    };
    Node* head;
    Node* tail;
    DoublyLinkedList():head(NULL),tail(NULL){}
    void insert_tail(int val){
        Node* newNode=new Node(val);
        if(head==NULL){
            head=tail=newNode;
            return;
        }
        tail->next=newNode;
        newNode->prev=tail;
        tail=tail->next;
    }
    bool Palindrome(){
        if(head==NULL) return true; 
        Node* left=head;
        Node* right=tail;
        while(left!=right && left->prev!=right){
            if(left->val!=right->val){
                return false;
            }
            left=left->next;
            right=right->prev;
        }
        return true;
    }
};
int main(){
    DoublyLinkedList dll;
    int val;
    while(cin>>val && val!=-1){
        dll.insert_tail(val);
    }
    if(dll.Palindrome()){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    return 0;
}
