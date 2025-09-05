// In binary Tree There are Two Types of Traversals BFS and DFS

// BFS is Breadth First Search , Traversal With the Help of Queue Data Structure , Level Wise Traversal

// DFS is Depth First Search , Traversal Include 3 types ;-

/*
1) Pre Order Traversal ( Root -> Left -> Right )



2) In order Traversal  ( Left -> Root -> Right )



3) Post Order Traversal ( Left -> Right -> Root )

*/


#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};

void preorder(Node* root){
    if(root == NULL) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root){
    if(root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(Node* root){
    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main(){
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->right->left = new Node(8);
    root->right->right->left = new Node(9);
    root->right->right->right = new Node(10);

/*
         1
     2       3
   4   5   6    7
      8       9   10


*/

    cout << "Pre Order of the Above Tree :- ";
    preorder(root);
    cout << endl;

    cout << "In order of the Above Tree :- ";
    inorder(root);
    cout << endl;

    cout << "Post Order of the Above Tree :- ";
    postorder(root);
    cout << endl;
}
