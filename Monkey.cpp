
#include <bits/stdc++.h>
using namespace std;
void sWrite(const string& str){
    string result;
    for(char c:str){
        if(isalpha(c))
        {
            result+=tolower(c);
        }
    }
    sort(result.begin(),result.end());
    cout<<result<<endl;
}
int main(){
    string line;
    while(getline(cin,line)){
        sWrite(line);
    }
    return 0;
}
