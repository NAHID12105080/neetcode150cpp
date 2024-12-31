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
    if(nodes.size()<=index or index==-1){
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

signed main() {
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};

    int index=-1;
    Node* root=buildTree(nodes,index);
    // levelOrder(root);
    // cout<<endl;
    Topview(root);
  return 0;
}