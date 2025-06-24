#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LONG_MAX >> 1;

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
    Node *root;
    Trie()
    {
        root = new Node('\0');
    }

    void insert(string s)
    {
        Node *temp = root;
        for (int i = 0; i < s.length(); i++)
        {
            char individual_char = s[i];
            if (temp->children.count(individual_char))
            {
                temp = temp->children;
            }
            else
            {
                Node *newNode = new Node(individual_char);
                temp->children = newNode;
                temp = newNode;
            }
        }

        temp->terminal = true;
    }

}

signed
main()
{
}