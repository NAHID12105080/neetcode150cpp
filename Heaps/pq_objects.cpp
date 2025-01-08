#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Student{
    public:
    string name;
    int marks;

    Student(string n,int m){
        name=n;
        marks=m;
    }

    bool operator<(const Student &s) const{
        return marks<s.marks;
    }
};

int main(){
    priority_queue<Student>pq;

    pq.push(Student("A",100));
    pq.push(Student("B",120));
    pq.push(Student("C",10));

    while (!pq.empty())
    {
        cout<<pq.top().name<<" "<<pq.top().marks<<endl;
        pq.pop();
    }
}