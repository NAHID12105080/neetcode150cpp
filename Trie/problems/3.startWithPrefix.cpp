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
    public:
    Node* root;
    Trie() {
        root = new Node('\0');
    }

    void insert(string s) {
        Node* temp = root;
        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];
            if (temp->children.count(ch)) {//if the character is already present in the children of the node
                temp = temp->children[ch];//move temp to the children of the node
            } else {
                Node* n = new Node(ch);
                temp->children[ch] = n;
                temp = n;
            }
        }
        temp->terminal = true;
    }

    
};

//problems code start from here
//similar to the find function of the trie
//just atlast return true instead of temp->terminal
bool startsWithPrefix(vector<string>&words,string prefix){
    Trie t;
    for(string word:words){
        t.insert(word);
    }
    Node* temp=t.root;
    for(int i=0;i<prefix.size();i++){
        if(temp->children.count(prefix[i])==0){
            return false;
        }
        temp=temp->children[prefix[i]];
    }
    return true;
}




int main(){
    vector<string> words={"zebra","dog","duck","dove"};
    cout<<startsWithPrefix(words,"m")<<endl;

    return 0;
}