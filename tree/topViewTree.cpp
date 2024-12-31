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
//2nd approach
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



signed main() {
vector<int> nodes = {1, 2, 4, 7, -1, -1, 8, -1, -1, 5, -1, 9, -1, -1, 3, -1, 6, 10, -1, -1, 11, -1, -1};

    int index=-1;
    Node* root=buildTree(nodes,index);
    // levelOrder(root);
    // cout<<endl;
    // Topview(root);
    printKthLevelNodes(root,4);
    KthLevelNodes(root,4);
  return 0;
}