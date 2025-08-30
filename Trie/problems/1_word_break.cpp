#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    char data;
    unordered_map<char, Node *> children;
    bool terminal;

    Node(char data)
    {
        this->data = data;
        terminal = false;
    }
};

class Trie
{
public:
    Node *root;

    Trie()
    {
        root = new Node('\0');
    }

    void insert(const string &s)
    {
        Node *temp = root;
        for (char ch : s)
        {
            if (temp->children.count(ch))
            {
                temp = temp->children[ch];
            }
            else
            {
                Node *n = new Node(ch);
                temp->children[ch] = n;
                temp = n;
            }
        }
        temp->terminal = true;
    }

    bool find(const string &s)
    {
        Node *temp = root;
        for (char ch : s)
        {
            if (temp->children.count(ch) == 0)
            {
                return false;
            }
            temp = temp->children[ch];
        }
        return temp->terminal;
    }
};

bool wordBreak(string s, vector<string> &wordDict)
{
    Trie t;
    for (const string &word : wordDict)
    {
        t.insert(word);
    }

    int n = s.length();
    vector<bool> dp(n + 1, false);
    dp[n] = true;

    for (int i = n - 1; i >= 0; i--)
    {
        Node *temp = t.root;
        for (int j = i; j < n; j++)
        {
            char ch = s[j];
            if (temp->children.count(ch) == 0)
            {
                break;
            }
            temp = temp->children[ch];
            if (temp->terminal && dp[j + 1])
            {
                dp[i] = true;
                break;
            }
        }
    }

    return dp[0];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s = "ilove";
    vector<string> wordDict = {"i", "love"};

    if (wordBreak(s, wordDict))
    {
        cout << "Yes, the string can be segmented.\n";
    }
    else
    {
        cout << "No, the string cannot be segmented.\n";
    }

    return 0;
}
