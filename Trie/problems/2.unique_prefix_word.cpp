#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
 
    unordered_map<char,Node*>children;
    bool endOFword;
    int freq;

    Node(){
        endOFword=false;
        }
}; 

class Trie{
    public:
    Node* root;
    Trie(){
        root=new Node();
        root->freq=-1;
    }

    //rewrite the insert function for this problem only
    void insert(string s){
        Node* temp=root;

        for(int i=0;i<s.size();i++){
            if(temp->children.count(s[i])==0){
                temp->children[s[i]]=new Node();
                temp->children[s[i]]->freq=1;
            }
            else{
                temp->children[s[i]]->freq++;
            }
            temp=temp->children[s[i]];
        }
        temp->endOFword=true;
    }
};

void unique_prefix_word(vector<string>&words){
    Trie t;
    for(string word:words){
        t.insert(word);
    }
    for(string word:words){
        Node* temp=t.root;
        string prefix="";
        for(int i=0;i<word.size();i++){
            prefix+=word[i];
            temp=temp->children[word[i]];
            if(temp->freq==1){
                cout<<prefix<<endl;
                break;
            }
        }
    }
}

int main(){
    vector<string>words={"zebra","dog","duck","dove"};
    unique_prefix_word(words);
    return 0;
}