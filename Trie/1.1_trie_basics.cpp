#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    char data;//to store the character
    unordered_map<char, Node*> children;//unordered_map is used to store the children of the node
    bool terminal;//to check whether the node is the end of the word or not

    Node(char data) {
        this->data = data;
        terminal = false;
    }
};

class Trie{
    Node* root;

    public:
    Trie() {
        root = new Node('\0');
    }

    void insert(string s) {
        Node* temp = root;
        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];
            if (temp->children.count(ch)) {//if the character is already present in the children of the node
                temp = temp->children[ch];
            } else {
                Node* n = new Node(ch);
                temp->children[ch] = n;
                temp = n;
            }
        }
        temp->terminal = true;
    }

    bool find(string s) {
        Node* temp = root;
        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];
            if (temp->children.count(ch) == 0) {
                return false;
            } else {
                temp = temp->children[ch];
            }
        }
        return temp->terminal;
    }
};


int main() {
    Trie t;
    t.insert("apple");
    t.insert("mango");
    t.insert("banana");
    string s;
    cin >> s;
    if (t.find(s)) {
        cout << "Present";
    } else {
        cout << "Not Present";
    }
    
    return 0;
}