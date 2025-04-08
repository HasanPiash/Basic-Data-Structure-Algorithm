#include <bits/stdc++.h>

using namespace std;

class Student {
public:
    string name;
    int cls;
    char section;
    int id;
    Student() {}

    Student(string nm, int c, char s, int i) {
        name = nm;
        cls = c;
        section = s;
        id = i;
    } 
};

int main() 
{
    int N;
    cin >> N;

    Student students[N];
    for (int i = 0; i < N; ++i)
    {
        cin >> students[i].name >> students[i].cls >> students[i].section >> students[i].id;
    }

    for (int i = 0; i < N / 2; ++i) {
        char temp = students[i].section;
        students[i].section = students[N - i - 1].section;
        students[N - i - 1].section = temp;
    }

    for (int i = 0; i < N; ++i) {
        cout << students[i].name << " " << students[i].cls << " " << students[i].section << " " << students[i].id << "\n";
    }

    return 0;
}
