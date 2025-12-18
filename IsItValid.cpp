#include<bits/stdc++.h> 
using namespace std;
class IsItValid{
public:
    bool Is_It_Valid(string s){
        stack<char>st;
        for(char c:s){
            if(c=='0'){
                if(!st.empty() && st.top()=='1')
                {
                    st.pop();
                }
                else{
                    st.push(c);
                }
            }
            else if(c=='1'){
                if(!st.empty() && st.top()=='0')
                {
                    st.pop();
                }
                else{
                    st.push(c);
                }
            }
        }
        return st.empty();
    }
};
int main(){
    int T;
    cin>>T;
    IsItValid valdt;
    for(int i=0; i<T; ++i){
        string s;
        cin>>s;
        if(valdt.Is_It_Valid(s)){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}
