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

static int index=-1;
//inorder traversal to build tree
Node* buildTree(vector<int> nodes){
    index++;
    if(index>=nodes.size() || nodes[index]==-1){
        return NULL;
    }
    Node* root=new Node(nodes[index]);
    root->left=buildTree(nodes);
    root->right=buildTree(nodes);
    return root;
}

void preOrderPrint(Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preOrderPrint(root->left);
    preOrderPrint(root->right);

}

void InorderPrint(Node* root){
    if(root==NULL){
        return;

    }
    InorderPrint(root->left);
    cout<<root->data<<" ";
    InorderPrint(root->right);
}

void PostOrderPrint(Node* root){
    if(root==NULL){
        return;
    }
    PostOrderPrint(root->left);
    PostOrderPrint(root->right);
    cout<<root->data<<" ";
}
//a bfs traversal of tree, the previous 3 was about dfs traversal
void levelOrder(Node* root){
    queue<Node*> q;
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

//levelOrder traversal with printing endl after eacch level

void LevelOrderWithSeperateLine(Node* root){
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* temp=q.front();
        q.pop();
        cout<<temp->data<<" ";
        if(temp==NULL){

        
        cout<<endl;
        if(q.empty()){
            break;
        }

        }

        else{
            if(temp->left!=NULL){
                q.push(temp->left);
            }
            if(temp->right!=NULL){
                q.push(temp->right);
            }
        }
    }
}

signed main() {
   vector<int> nodes={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};

    return 0;
}