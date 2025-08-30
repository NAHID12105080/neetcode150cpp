#include<iostream>
#include<vector>
#include<queue>
using namespace std;


int main(){
    priority_queue<int,vector<int>,greater<int>>pq;//minimum priority queue , pass vecotr as container, inside it pass datatype of data and greater as comparator
    pq.push(1);
    pq.push(2);
    pq.push(3);
    pq.push(4);
    pq.push(5);
    
    while (!pq.empty())
    {
        cout<<pq.top()<<" ";
        pq.pop();
    }
    return 0;
    

}