#include<bits/stdc++.h> 
using namespace std;
class SpecialQrs{
public:
    list<string>lst;
    void push(string val){
        lst.push_back(val);
    }
    void pop(){
        if(!empty())
            lst.pop_front();
    }
    string front(){
        if(!empty())  
            return lst.front();
        return "empty"; 
    }
    int size(){
        return lst.size();
    }
    bool empty(){
        return lst.empty();
    }
};
int main()
{
    SpecialQrs q;
    int Q;
    cin>>Q;
    for(int i=0; i<Q; ++i){
        char c;
        cin>>c;
        if(c=='0'){
            string s;
            cin>>s;
            q.push(s);
        }
        else if(c=='1'){
            if(!q.empty()){
                cout<<q.front()<<endl;
                q.pop();
            }
            else
            {
                cout<<"Invalid"<<endl;
            }
        }
    }
    return 0;
}
