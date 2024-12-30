#include<bits/stdc++.h>
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

// Function to build a tree from a vector using in-order traversal
Node* buildTree(vector<int>& nodes, int& treeIndex) {
    treeIndex++;
    if (treeIndex >= nodes.size() || nodes[treeIndex] == -1) {
        return NULL;
    }
    Node* root = new Node(nodes[treeIndex]);
    root->left = buildTree(nodes, treeIndex);
    root->right = buildTree(nodes, treeIndex);
    return root;
}

// Pre-order traversal (DFS)
void preOrderPrint(Node* root) {
    if (root == NULL) {
        return;
    }
    cout << root->data << " ";
    preOrderPrint(root->left);
    preOrderPrint(root->right);
}

// In-order traversal
void inOrderPrint(Node* root) {
    if (root == NULL) {
        return;
    }
    inOrderPrint(root->left);
    cout << root->data << " ";
    inOrderPrint(root->right);
}

// Post-order traversal
void postOrderPrint(Node* root) {
    if (root == NULL) {
        return;
    }
    postOrderPrint(root->left);
    postOrderPrint(root->right);
    cout << root->data << " ";
}

// Level-order traversal (BFS)
void levelOrder(Node* root) {
    if (root == NULL) {
        return;
    }
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();
        cout << temp->data << " ";
        if (temp->left != NULL) {
            q.push(temp->left);
        }
        if (temp->right != NULL) {
            q.push(temp->right);
        }
    }
}

// Level-order traversal with levels printed on separate lines
void levelOrderWithSeparateLine(Node* root) {
    if (root == NULL) {
        return;
    }
    queue<Node*> q;
    q.push(root);
    q.push(NULL); // Marker for end of level

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if (temp == NULL) {
            cout << endl;
            if (!q.empty()) {
                q.push(NULL); // Add marker for the next level
            }
        } else {
            cout << temp->data << " ";
            if (temp->left != NULL) {
                q.push(temp->left);
            }
            if (temp->right != NULL) {
                q.push(temp->right);
            }
        }
    }
}

// Find height of the tree
int height(Node* root) {
    if (root == NULL) {
        return 0;
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return max(leftHeight, rightHeight) + 1;
}

// Count the number of nodes in the tree
int countNumberOfNodes(Node* root) {
    if (root == NULL) {
        return 0;
    }
    int leftCount = countNumberOfNodes(root->left);
    int rightCount = countNumberOfNodes(root->right);
    return leftCount + rightCount + 1;
}

// Sum of all nodes in the tree
int sumOfNodes(Node* root) {
    if (root == NULL) {
        return 0;
    }
    int leftSum = sumOfNodes(root->left);
    int rightSum = sumOfNodes(root->right);
    return leftSum + rightSum + root->data;
}

int main() {
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    int treeIndex = -1; // Initialize treeIndex for tracking position in vector
    Node* root = buildTree(nodes, treeIndex);

    cout << "Pre-order Traversal: ";
    preOrderPrint(root);
    cout << endl;

    cout << "In-order Traversal: ";
    inOrderPrint(root);
    cout << endl;

    cout << "Post-order Traversal: ";
    postOrderPrint(root);
    cout << endl;

    cout << "Level-order Traversal: ";
    levelOrder(root);
    cout << endl;

    cout << "Level-order Traversal with Levels on Separate Lines:" << endl;
    levelOrderWithSeparateLine(root);

    cout << "Height of the Tree: " << height(root) << endl;
    cout << "Number of Nodes: " << countNumberOfNodes(root) << endl;
    cout << "Sum of All Nodes: " << sumOfNodes(root) << endl;

    return 0;
}
