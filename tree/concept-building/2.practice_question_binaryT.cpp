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
    q.push(NULL); // Marker for end of level(keep in mind)

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
//no. of nodes in the longest path between 2nodes 
int diameterOfTree(Node* root){
    if(root==NULL){
        return 0;
    }
    int currentDiameter=height(root->left)+height(root->right)+1;
    int LeftTreeDiameter=diameterOfTree(root->left);
    int RightTreeDiameter=diameterOfTree(root->right);
    return max(currentDiameter,max(LeftTreeDiameter,RightTreeDiameter));
}

pair<int, int> diameter2ndapproach(Node* root) {
    if (root == NULL) {
        return {0, 0}; // Use brace-enclosed initialization
    }
    pair<int, int> leftTree = diameter2ndapproach(root->left);
    pair<int, int> rightTree = diameter2ndapproach(root->right);

    int currentDiameter = leftTree.second + rightTree.second + 1;
    int finalDiameter = max(currentDiameter, max(leftTree.first, rightTree.first));
    int finalHeight = max(leftTree.second, rightTree.second) + 1;

    return {finalDiameter, finalHeight}; // Use brace-enclosed initialization
}


int main() {
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    int treeIndex = -1; // Initialize treeIndex for tracking position in vector
    Node* root = buildTree(nodes, treeIndex);

    // cout<<"diameterOFTree :"<<diameterOfTree(root)<<endl;    
    pair<int, int> result = diameter2ndapproach(root);
    cout << "Diameter: " << result.first << ", Height: " << result.second << endl;

    return 0;
}
