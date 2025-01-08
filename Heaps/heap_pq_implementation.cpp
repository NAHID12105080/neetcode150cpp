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
    void printHeap() {
        for (int i = 0; i < v.size(); ++i) {
            cout << v[i] << " ";
        }
        cout << endl;
    }

};

int main() {
    Heap h;
    h.push(10);
    h.push(20);
    h.push(5);
    h.push(30);

    cout << "Top element: " << h.top() << endl;
    h.printHeap();
    h.pop();
    cout << "Top element after pop: " << h.top() << endl;

    h.pop();
    cout << "Top element after another pop: " << h.top() << endl; 

    cout << "Is heap empty? " << (h.empty() ? "Yes" : "No") << endl; 

    h.pop();
    h.pop();
    cout << "Is heap empty after popping all elements? " << (h.empty() ? "Yes" : "No") << endl; // Should print Yes

    return 0;
}