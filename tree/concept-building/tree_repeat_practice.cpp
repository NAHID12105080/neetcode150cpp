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

Node* buildTree(vector<int>&nodes,int &treeIndex)
{
     treeIndex++;
    if(nodes.size()<=treeIndex || treeIndex==-1){
        return NULL;
    }
    Node* root=new Node(nodes[treeIndex]);
    root->left=buildTree(nodes,treeIndex);
    root->right=buildTree(nodes,treeIndex);

return root;

    
}

void printInorder(Node* root){
    cout<<root->data<<" ";

}

void printUsingBFS(Node* root){
  
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        Node* temp=q.front();
        q.pop();
        cout<<temp->data<<" ";
        if(temp->left!=NULL){
          
            q.push(temp->left);
        }
        if(temp->right!=NULL){
            q.push(temp->right);
        }


    }
}

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
            if (q.empty()) {
                break;
            }
            q.push(NULL);
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

int diameterOfTree(Node* root){
    if(root==NULL) {
        return 0;
    }

    

}


int main(){
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    int treeIndex = -1;
    Node* root = buildTree(nodes, treeIndex);
    // printUsingBFS(root);
    levelOrderWithSeparateLine(root);
    return 0;
}