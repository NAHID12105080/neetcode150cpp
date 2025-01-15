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

//problems code start from here
bool helper(Trie &trie, string key){
    if(key.length()==0){
        return true;
    }

    for(int i=0;i<key.size();i++){
        string left=key.substr(0,i+1);
        string right=key.substr(i+1);
        if(trie.find(left) && helper(trie,right)){
            return true;
        }
    }
}

bool wordBreak(string s, vector<string>& dict){
    Trie trie;
    for(int i=0;i<dict.size();i++){
        trie.insert(dict[i]);
    }

    return helper(trie,s);

}



int main(){
   string s="ilove";
    vector<string> wordDict={"i","love"};
    cout<<wordBreak(s,wordDict);

    return 0;
}