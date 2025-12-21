#include<bits/stdc++.h> 
using namespace std;
class RemoveDuplicate{
public:
    list<int>deleteDuplicates(list<int>& dplct)
    {
        dplct.sort(); 
        dplct.unique(); 
        return dplct;
    }
    void p_list(list<int>&dplct){
        for(int val:dplct)
        {
            cout<<val<<" ";
        }
        cout<<endl;
    }
};
int main(){
   RemoveDuplicate rmvDuplicate;
    list<int>dplct;
    int val;
    while(cin>>val && val!=-1)
    {
        dplct.push_back(val);
    }
    list<int>tmp=rmvDuplicate.deleteDuplicates(dplct);
    rmvDuplicate.p_list(tmp);
    return 0;
}
