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
        if (next != NULL) {
            delete next;
        }
    }
};

//Hashtable is effective to store unstructured data, where order is not important.
class HashTable{
    int total_size;
    int current_size;//will be used in rehashing
    Node** table;

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
    double lamda=current_size/(1.0*total_size);
    if(lamda>0.7){
        rehash();
    }
    }
};




int main() {
    Node* n = new Node("abc", 1);
    cout << n->key << " " << n->value << endl;
    return 0;
}