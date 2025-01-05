#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data=data;
        left=NULL;
        right=NULL;
    }
};

Node* insert(Node* root, int data)
{
    if(root==NULL){
        return new Node(data);
    }

    if(data<root->data){
        root->left=insert(root->left,data);
    }
    else{
        root->right=insert(root->right,data);
    }
    return root;
}

Node* buildBST(int arr[], int n){
    Node* root=NULL;
    for(int i=0;i<n;i++){
        root=insert(root,arr[i]);
    }
    return root;
}

void inorder(Node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

bool searchBST(Node* root, int key){
    if(root==NULL){
        return false;
    }
    if(root->data==key){
        return true;
    }
    if(key<root->data){
        return searchBST(root->left,key);
    }
    return searchBST(root->right,key);
    
}


Node* InorderSuccessor(Node* root){
    while(root->left!=NULL){
        root=root->left;
    }

    return root;
}


Node* deleteNode(Node* root, int val){
    if(root==NULL) {
        return NULL;
    }
    if(val<root->data){
         root->left=deleteNode(root->left,val);
    }
    if(val>root->data){
         root->right=deleteNode(root->right,val);
    }
    else{
        if(root->left==NULL&& root->right==NULL){
            delete root;
            return NULL;
        }

        if(root->left==NULL || root->right==NULL){
            return root->left==NULL?root->right:root->left;
        }

        //2child case:
        else{
            Node* IS=InorderSuccessor(root->right);
            root->data=IS->data;
            root->right=deleteNode(root->right,IS->data);
            return root;
        }
    }
    return root;
}


int main(){
    int arr[]={11,1,2,3,4,5};
    Node* root=buildBST(arr,6);
    // inorder(root);
    // cout<<endl;
    // cout<<searchBST(root,5)<<endl;


    inorder(root);
    deleteNode(root,5);
    cout<<endl;
    inorder(root);


    return 0;
}
