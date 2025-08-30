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

    string longestStrWithEow(Node* temp){
        Node* temp=root;
        string ans="";
        for(auto it:temp->children){
            if(it.second->freq>0){
                string temp=it.first+longestStrWithEow(it.second);
                if(temp.size()>ans.size()){
                    ans=temp;
                }
            }
        }
        return ans;
    }
};

string longestString(vector<string>&words){
    Trie t;
    for(string word:words){
        t.insert(word);
    }
    return t.longestStrWithEow(t.root);

}


int main(){
    vector<string>words={"zebra","z","zeb","zebr","dog","duck"};
    longestString(words);

    return 0;
}