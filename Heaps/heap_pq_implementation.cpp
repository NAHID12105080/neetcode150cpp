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
        int n=v.size();
        swap(v[0],v[n-1]);
        v.pop_back();
        heapify(0);
    }
    void heapify(int i){
        int n = v.size();
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && v[left] > v[largest])
            largest = left;

        if (right < n && v[right] > v[largest])
            largest = right;

        if (largest != i) {
            swap(v[i], v[largest]);
            heapify(largest);
        }
    }

    int top(){
        return v[0];
    }

    bool empty(){
        return v.size()==0;
    }
};
