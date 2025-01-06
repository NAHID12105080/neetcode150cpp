#include<bits/stdc++.h>

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

    //       8
    //    /     \
    //   3       10
    //  / \        \
    // 1   6        14
    //    / \      /
    //   4   7    13

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
            root->right=deleteNode(root->right,IS->data);// as inorder successor lies in right subtree always and it's the left most child of the it, has 0,1 child max , as left child must be NULL
            return root;
        }
    }
    return root;
}

void printGivenRange(Node* root, int start, int end){
   if(root==NULL){
    return;
   }

    if(start<=root->data && root->data<=end){
        cout<<root->data<<" ";
        printGivenRange(root->left,start,end);
        printGivenRange(root->right,start,end);
    }

    else if(root->data<start){
        printGivenRange(root->right,start,end);

    }
    else{
        printGivenRange(root->left,start,end);
    }
}


//print all path from root to leaf
void printPath(vector<int> path){
    for(auto i:path){
        cout<<i<<" ";
    }
    cout<<endl;
}

void printMainHelper(Node* root, vector<int>&path)
{
    if(root==NULL){
        return;
    }
    path.push_back(root->data);
   
    if(root->left==NULL && root->right==NULL){
        printPath(path);
        path.pop_back();
        return;
    }
    printMainHelper(root->left,path);
    printMainHelper(root->right,path);
    path.pop_back();
}

void pathRootToleaf(Node* root){
    vector<int>path;

    printMainHelper(root, path);

}

bool isValidBSTHelper(Node* root, Node* minNode, Node* maxNode) {
    if (root == NULL) {
        return true;
    }
    if ((minNode != NULL && root->data <= minNode->data) || (maxNode != NULL && root->data >= maxNode->data)) {
        return false;
    }
    return isValidBSTHelper(root->left, minNode, root) && isValidBSTHelper(root->right, root, maxNode);
}

bool isValidBST(Node* root) {
    return isValidBSTHelper(root, NULL, NULL);
}

    //       8
    //    /     \
    //   3       10
    //  / \        \
    // 1   6        14
    //    / \      /
    //   4   7    13

Node* buildBSTsortedArray(int arr[], int start, int end){
    if(start>end){
        return NULL;
    }
    int mid=start+(end-start)/2;
    Node* root=new Node(arr[mid]);
    root->left=buildBSTsortedArray(arr,start,mid-1);
    root->right=buildBSTsortedArray(arr,mid+1,end);
    return root;
}



int main(){
    int arr[] = {8, 3, 10, 1, 6, 4, 7, 14, 13};
    //       8
    //    /     \
    //   3       10
    //  / \        \
    // 1   6        14
    //    / \      /
    //   4   7    13


    Node* root=buildBST(arr,9);
    // inorder(root);
    // cout<<endl;
    // cout<<searchBST(root,5)<<endl;


    // inorder(root);
    // deleteNode(root,5);
    // cout<<endl;
    // inorder(root);

    //-------
    // inorder(root);
    // cout<<endl;
    // printGivenRange(root,2,4);


    // pathRootToleaf(root);

    // isValidBST(root)?cout<<"Yes":cout<<"No";

    buildBSTsortedArray(arr,0,8);
    inorder(root);

    return 0;
}
