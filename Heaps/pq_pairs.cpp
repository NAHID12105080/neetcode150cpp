#include<vector>
#include<queue>
#include<string>
#include<iostream>
using namespace std;

struct ComparePair {
    bool operator()(pair<string,int>&p1,pair<string,int>&p2){
        return p1.second<p2.second;
    }
};

int main(){
    priority_queue<pair<string,int>,vector<pair<string,int>>,ComparePair>pq;
    pq.push({"A",100});
    pq.push({"B",120});
    pq.push({"C",10});

    while (!pq.empty())
    {
        cout<<pq.top().first<<" "<<pq.top().second<<endl;
        pq.pop();
    }
    return 0;
}