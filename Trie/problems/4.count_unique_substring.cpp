#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

struct TrieNode {
    TrieNode* children[26];
    bool isEndOfWord;

    TrieNode() {
        for (int i = 0; i < 26; ++i) {
            children[i] = nullptr;
        }
        isEndOfWord = false;
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    void insert(const string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            int index = ch - 'a';
            if (node->children[index] == nullptr) {
                node->children[index] = new TrieNode();
            }
            node = node->children[index];
        }
        node->isEndOfWord = true;
    }

    int countUniqueSubstrings() {
        return countNodes(root);
    }


    TrieNode* root;

    int countNodes(TrieNode* node) {
        if (node == nullptr) return 0;

        int count = 0;
        for (int i = 0; i < 26; ++i) {
            if (node->children[i] != nullptr) {
                count += countNodes(node->children[i]);
            }
        }
        return count + 1;
    }
};

int countUniqueSubstrings(const string& s) {
    Trie trie;
    for (int i = 0; i < s.length(); ++i) {
        trie.insert(s.substr(i));
    }
    return trie.countUniqueSubstrings(); // including the empty substring
}

int main() {
    string s = "ababa";
    cout << "Number of unique substrings: " << countUniqueSubstrings(s) << endl;
    return 0;
}