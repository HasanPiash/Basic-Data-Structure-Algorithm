#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Student {
public:
    string name;
    int cls;
    char section;
    int id;
    int math_marks;
    int eng_marks;

    Student() {}
    Student(string nm, int c, char s, int i, int math, int eng) {
        name = nm;
        cls = c;
        section = s;
        id = i;
        math_marks = math;
        eng_marks = eng;
    }
};

bool cmp(Student a, Student b) {
   if (a.eng_marks == b.eng_marks) {
        if (a.math_marks == b.math_marks) {
            return a.id < b.id;
        }
        return a.math_marks > b.math_marks;
    }
    return a.eng_marks > b.eng_marks;
}

int main() {
    int N;
    cin >> N;

    Student a[N];

    for (int i = 0; i < N; ++i) {
        cin >> a[i].name >> a[i].cls >> a[i].section >> a[i].id >> a[i].math_marks >> a[i].eng_marks;
    }

    sort(a, a + N, cmp);

    for (int i = 0; i < N; ++i) {
        cout << a[i].name << " " << a[i].cls << " " << a[i].section << " "
             << a[i].id << " " << a[i].math_marks << " " << a[i].eng_marks << endl;
    }

    return 0;
}
