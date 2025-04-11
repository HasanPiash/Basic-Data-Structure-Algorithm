#include <bits/stdc++.h>
using namespace std;
class Elimination{
public:
    bool checkBin(string inpSt){
        stack<char>charStk;
        for(char c:inpSt){
            if (!charStk.empty() && c=='1' && charStk.top()=='0')
            {
                charStk.pop();
            }
            else{
                charStk.push(c);
            }
        }
        return charStk.empty();
    }
};
int main(){
    int tC;
    cin>>tC;
    Elimination elmntn;
    for(int t=0; t<tC; t++){
        string inpSt;
        cin>>inpSt;
        if(elmntn.checkBin(inpSt))
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}
