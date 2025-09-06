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

class Solution{
public:
    vector<int>PreOrderTraversal(Node* root){
        vector<int>preorder;
        if(root == NULL) return preorder;
        stack<Node*>st;
        st.push(root);
        while(!st.empty()){
            root = st.top();
            st.pop();
            preorder.push_back(root->data);
            if(root->right != NULL) st.push(root->right);
            if(root->left != NULL) st.push(root->left);
        }
        return preorder;
    }
};


int main(){
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(7);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->left->right->left = new Node(5);
    root->left->right->right = new Node(6);

    Solution sol;
    vector<int>PreOrder = sol.PreOrderTraversal(root);

    cout << "Iterative Method PreOrder Traversal of the Above Tree :- ";
    for(int val:PreOrder) cout << val << " ";
    cout << endl;

}
