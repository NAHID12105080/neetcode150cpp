#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        left = right = NULL;
    }
};

Node* buildTree(const vector<int>& nodes, int& treeIndex) {
    treeIndex++;
    if (treeIndex >= nodes.size() || nodes[treeIndex] == -1) {
        return NULL;
    }
    Node* root = new Node(nodes[treeIndex]);
    root->left = buildTree(nodes, treeIndex);
    root->right = buildTree(nodes, treeIndex);
    return root;
}

bool isIdentical(Node* root, Node* subroot) {
    if (root == NULL && subroot == NULL) {
        return true;
    }
    if (root == NULL || subroot == NULL) {
        return false;
    }
    if (root->data != subroot->data) {
        return false;
    }
    return isIdentical(root->left, subroot->left) && isIdentical(root->right, subroot->right);
}

bool issubTree(Node* root, Node* subroot) {
    if (root == NULL) {
        return false;
    }
    if (isIdentical(root, subroot)) {
        return true;
    }
    return issubTree(root->left, subroot) || issubTree(root->right, subroot);
}

int main() {
    vector<int> nodes = {2, 3, -1, -1, 4, -1, -1};
    int treeIndex = -1; // Initialize treeIndex for tracking position in vector
    Node* root = buildTree(nodes, treeIndex);

    // Create the subroot tree
    Node* subroot = new Node(2);
    subroot->left = new Node(3);
    subroot->right = new Node(4);

    // Check if subroot is a subtree of root
    cout << (issubTree(root, subroot) ? "Yes" : "No") << endl;

    return 0;
}
