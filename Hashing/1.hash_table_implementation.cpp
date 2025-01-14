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
};

class HashTable{
    int total_size;
    int current_size;//will be used in rehashing
    Node** table;
    public:
    HashTable(int total_size) {
        this->total_size = total_size;
        current_size = 0;
        table = new Node*[total_size];
        for (int i = 0; i < total_size; i++) {
            table[i] = NULL;
        }
    }
};



int main() {
    Node* n = new Node("abc", 1);
    cout << n->key << " " << n->value << endl;
    return 0;
}