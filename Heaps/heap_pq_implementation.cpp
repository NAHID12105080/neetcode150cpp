#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Heap{
    vector<int>v;
    public:
    void push(int val){
        //step1
        v.push_back(val);

        //fix heap
        int x=v.size()-1;//childIndex
        int parentIndex=(x-1)/2;
        
        while(parentIndex>=0 and v[x]>v[parentIndex]){
            swap(v[x],v[parentIndex]);
            x=parentIndex;
            parentIndex=(x-1)/2;
        }
    }

    void pop(){

    }

    int top(){
        return v[0];
    }

    bool empty(){
        return v.size()==0;
    }
};
