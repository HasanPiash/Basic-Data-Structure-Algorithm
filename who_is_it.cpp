#include <bits/stdc++.h> 
using namespace std;
class Student {
public:
    int id;
    string name;
    string section;
    int marks;
    Student(int id,string name,string section,int marks):id(id),name(name),section(section),marks(marks){}
};
int main(){
    int T;
    cin>>T;
    for(int testCase=1; testCase<=T; testCase++){
        int highestMarks=-1, highestID=INT_MAX;
        Student* topStudent=nullptr;
        for (int i=0; i<3; i++)
        {
            int id,marks;
            string name,section;
            cin >>id>>name>>section>>marks;
            Student* currentStudent=new Student(id,name,section,marks);
            if(currentStudent->marks>highestMarks || (currentStudent->marks==highestMarks && currentStudent->id<highestID))
            {
                highestMarks=currentStudent->marks;
                highestID=currentStudent->id;
                topStudent=currentStudent;
            } else{
                delete currentStudent;
            }
        }
        cout<<topStudent->id<<" " <<topStudent->name<< " "<<topStudent->section<<" "<<topStudent->marks<<endl;
        delete topStudent; 
    }
    return 0;
}
