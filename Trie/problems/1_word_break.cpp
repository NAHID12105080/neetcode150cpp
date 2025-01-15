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

bool wordBreak(string s, vector<string>& wordDict) {
    Trie t;
    for (string word : wordDict) {
        t.insert(word);
    }
    int n = s.length();
    vector<bool> dp(n + 1, false);
    dp[n] = true;
    for (int i = n - 1; i >= 0; i--) {
        Node* temp = t.root;
        for (int j = i; j < n; j++) {
            char ch = s[j];
            if (temp->children.count(ch) == 0) {
                break;
            } else {
                temp = temp->children[ch];
                if (temp->terminal && dp[j + 1]) {
                    dp[i] = true;
                    break;
                }
            }
        }
    }
    return dp[0];
}


int main(){
   string s="ilove";
    vector<string> wordDict={"i","love"};
    cout<<wordBreak(s,wordDict);

    return 0;
}