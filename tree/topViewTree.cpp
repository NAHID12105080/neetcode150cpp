#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data=data;
        left=right=NULL;
    }

};

Node* buildTree(vector<int>&nodes, int &index){
    index++;
    if(nodes.size()<=index || nodes[index]==-1){//careFul its nodes[index]==-1
        return NULL;
    }
    Node* root=new Node(nodes[index]);
    root->left=buildTree(nodes,index);
    root->right=buildTree(nodes,index);
    return root;
}

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


void Topview(Node* root){
    queue<pair<Node*,int>>q;
    map<int,int>mp;
    q.push({root,0});
    while(!q.empty()){
        Node* temp=q.front().first;
        int hd=q.front().second;
        q.pop();
        if(mp.find(hd)==mp.end()){
            mp[hd]=temp->data;
        }
        if(temp->left!=NULL){
            q.push({temp->left,hd-1});
        }
        if(temp->right!=NULL){
            q.push({temp->right,hd+1});
        }
    }
    for(auto x:mp){
        
        cout<<x.second<<" ";
    }
}

void kthNodePrintHelper(Node* root, int k, int curLevel) {
    if (root == NULL) {
        return;
    }
    if (curLevel == k) {
        cout << root->data << " ";
        return; // Stop further traversal for this branch
    }
    kthNodePrintHelper(root->left, k, curLevel + 1);
    kthNodePrintHelper(root->right, k, curLevel + 1);
}

void printKthLevelNodes(Node* root, int k) {
    kthNodePrintHelper(root, k, 1);
    cout << endl;
}
//2nd approach, trust recursion
void KthLevelNodes(Node* root, int k) {
    if (root == NULL) {
        return;
    }
    if (k == 1) {
        cout << root->data << " ";
        return;
    }
    KthLevelNodes(root->left, k - 1);
    KthLevelNodes(root->right, k - 1);
}

bool findPath(Node* root, int n, vector<int>& path) {
    if (root == NULL) {
        return false;
    }
    path.push_back(root->data);
    if (root->data == n) {
        return true;
    }
    if (findPath(root->left, n, path) || findPath(root->right, n, path)) {
        return true;
    }
    path.pop_back();
    return false;
}

int LowestCommonAncestor(Node* root, int n1, int n2) {
    vector<int> path1, path2;
    if (!findPath(root, n1, path1) || !findPath(root, n2, path2)) {
        cout << "No path found";
        return -1;
    }
    int lca = -1;
    for (int i = 0, j = 0; i < path1.size() && j < path2.size(); i++, j++) {
        if (path1[i] != path2[j]) {
            break;
        }
        lca = path1[i];
    }
    return lca;
}

signed main() {
vector<int> nodes = {1, 2, 4, 7, -1, -1, 8, -1, -1, 5, -1, 9, -1, -1, 3, -1, 6, 10, -1, -1, 11, -1, -1};

    int index=-1;
    Node* root=buildTree(nodes,index);
    // levelOrder(root);
    // cout<<endl;
    // Topview(root);
    // printKthLevelNodes(root,4);
    // KthLevelNodes(root,4);

    cout<<LowestCommonAncestor(root,10,11);
  return 0;
}