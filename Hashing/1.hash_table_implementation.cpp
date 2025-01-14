#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    string key;
    int value;
    Node* next;
    Node(string key, int value) {
        this->key = key;
        this->value = value;
        next = NULL;
    }

    ~Node() {
        if (next != NULL) {//deleting the next pointer recursively, atlast deleting the current node
            delete next;
        }
    }
};

//Hashtable is effective to store unstructured data, where order is not important. unordered_map,unordered_set are the inbuilt hash table in c++. gives time complexity of O(1) for insertion,deletion and searching in average case.
class HashTable{
    int total_size;
    int current_size;//will be used in rehashing
    Node** table;//pointer to the array of pointers

    int hashfunction(string key) {
        int idx = 0;
        int p = 1;
        for (int j = 0; j < key.length(); j++) {
            idx = (idx + (key[j] * p) % total_size) % total_size;
            p = (p * 27) % total_size;
        }
        return idx;
    }

    void rehash(){
        Node** oldTable=table;
        int oldtable_size=total_size;
        total_size=2*total_size;
        table=new Node*[total_size];
        for(int i=0;i<total_size;i++){
            table[i]=NULL;
        }
        current_size=0;
        for(int i=0;i<oldtable_size;i++){
            Node* temp=oldTable[i];
            while(temp!=NULL){
                insert(temp->key,temp->value);//inserting the old table individual node to the new table
                temp=temp->next;
            }
            delete oldTable[i];//deleting the old table individual node
        }
        delete [] oldTable;//deleting the empty old table , it's just the empty space


    }

    public:
    HashTable(int total_size) {
        this->total_size = total_size;
        current_size = 0;
        table = new Node*[total_size];
        for (int i = 0; i < total_size; i++) {
            table[i] = NULL;
        }
    }

    void insert(string key,int value){
    int index=hashfunction(key);
    Node* newNode=new Node(key,value);
    newNode->next=table[index];
    table[index]=newNode;
    current_size++;

    //rehashing
    //if load increases on the main table then time complexity will increase
    double lamda=current_size/(1.0*total_size);
    if(lamda>0.7){
        rehash();
    }
    }

    int* search(string key){
        int index=hashfunction(key);
        Node* temp=table[index];
        while(temp!=NULL){
            if(temp->key==key){
                return &(temp->value);
            }
            temp=temp->next;
        }
        return NULL;
    }

    bool isExist(string key){
        int index=hashfunction(key);
        Node* temp=table[index];
        while(temp!=NULL){
            if(temp->key==key){
                return true;
            }
            temp=temp->next;
        }
        return false;
    }

    void erase(string key){
        int index=hashfunction(key);
        Node* temp=table[index];
        Node* prev=NULL;
        while(temp!=NULL){
            if(temp->key==key){
                if(prev==NULL){//case1:if the key is at the head of the linked list
                    table[index]=temp->next;
                }
                else{//case2:if the key is at the middle or end of the linked list
                    prev->next=temp->next;
                }
                temp->next=NULL;
                delete temp;
                return;
            }
            prev=temp;//updating the prev pointer
            temp=temp->next;
        }
    }

    void print(){
        for(int i=0;i<total_size;i++){
            Node* temp=table[i];
            cout<<"Bucket "<<i<<"->";
            while(temp!=NULL){
                cout<<temp->key<<" ";
                temp=temp->next;
            }
            cout<<endl;
        }
    }
};

int main() {
    HashTable h(7);
    h.insert("Mango", 100);
    h.insert("Apple", 120);
    h.insert("Banana", 20);
    h.insert("Guava", 30);
    h.insert("Pineapple", 40);
    h.insert("Orange", 50);
    h.insert("Kiwi", 60);

  
    h.print();

    int* price = h.search("Banana");
    if (price != NULL) {
        cout << "Price of Banana is " << *price << endl;
    } else {
        cout << "Banana not found" << endl;
    }

    h.erase("Banana");

    if (h.isExist("Banana")) {
        cout << "Banana is present" << endl;
    } else {
        cout << "Banana is not present" << endl;
    }

 return 0;
}