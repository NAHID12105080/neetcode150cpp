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
//         1
//        / \
//       2   3validVal+1
//      / \    \
//     4   5    6
//    / \   \   / \
//   7   8   9 10  11

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
//         1
//        / \
//       2   3
//      / \    \
//     4   5    6
//    / \   \   / \
//   7   8   9 10  11


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
//         1
//        / \
//       2   3
//      / \    \
//     4   5    6
//    / \   \   / \
//   7   8   9 10  11

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
//         1
//        / \
//       2   3
//      / \    \
//     4   5    6
//    / \   \   / \
//   7   8   9 10  11

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

//Better approach with reduced space complexity
//approach 2 as the lca of 2 nodes is the first node in the same subtree of the 2 nodes
//         1
//        / \
//       2   3
//      / \    \
//     4   5    6
//    / \   \   / \
//   7   8   9 10  11

Node* LCA2(Node* root , int n1, int n2){
    if(root == NULL){
        return NULL;
    }
    if(root->data == n1 || root->data == n2){
        return root;
    }
    Node* left = LCA2(root->left,n1,n2);
    Node* right = LCA2(root->right,n1,n2);
    if(left != NULL && right != NULL){
        return root;
    }
    return left==NULL?right:left;
    
}
// minimum distance between 2 nodes in a binary tree
int distance(Node* root, int n){
    if(root==NULL){
        return -1;
    }
    if(root->data==n){
        return 0;
    }
    int left=distance(root->left,n);
    int right=distance(root->right,n);
    if(left!=-1){
        return left+1;
    }
    if(right!=-1){
        return right+1;
    }
    return -1;//if not found
}

int minimumDistanceBetweenNodes(Node* root, int n1, int n2){
    Node* lca=LCA2(root,n1,n2);
    int d1=distance(lca,n1);
    int d2=distance(lca,n2);
    return d1+d2;
   
}

//kth ancestor of a node in a binary tree
//         1
//        / \
//       2   3
//      / \    \
//     4   5    6
//    / \   \   / \
//   7   8   9 10  11

int kthAncestor(Node* root, int n, int k){
    if(root==NULL){
        return -1;
    }
    if(root->data==n){
        return 0;
    }
    int leftDist=kthAncestor(root->left,n,k);
    int rightDist=kthAncestor(root->right,n,k);
    if(leftDist==-1 && rightDist==-1){
        return -1;
    }

    int validVal=leftDist==-1?rightDist:leftDist;

    if(validVal+1==k){
        cout<<root->data<<" ";//printing the kth ancestor********
    }
    return validVal+1;//returning the distance of the node from the root*****(keep in mind)
}

int TreeTransformWithSum(Node* root){
    if(root==NULL){
        return 0;
    }
    if(root->left==NULL && root->right==NULL){
        return root->data;
    }
    int leftSum=TreeTransformWithSum(root->left);
    int rightSum=TreeTransformWithSum(root->right);
    int temp=root->data;
    root->data=leftSum+rightSum;
    return temp+root->data;
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



signed main() {
vector<int> nodes = {1, 2, 4, 7, -1, -1, 8, -1, -1, 5, -1, 9, -1, -1, 3, -1, 6, 10, -1, -1, 11, -1, -1};
//         1
//        / \
//       2   3
//      / \    \
//     4   5    6
//    / \   \   / \
//   7   8   9 10  11

    int index=-1;
    Node* root=buildTree(nodes,index);

    // levelOrder(root);
    // cout<<endl;
    // Topview(root);
    // printKthLevelNodes(root,4);
    // KthLevelNodes(root,4);

    // cout<<LowestCommonAncestor(root,10,11);

    // cout<<LCA2(root,10,11)->data;

    // cout<<minimumDistanceBetweenNodes(root,10,11);

    // kthAncestor(root,11,1);

    TreeTransformWithSum(root);
    levelOrderWithSeparateLine(root);
  return 0;
}