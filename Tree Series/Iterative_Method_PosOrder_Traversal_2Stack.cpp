
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
    vector<int>PostOrderTraversal(Node* root){
        vector<int>postorder;
        if(root == NULL) return postorder;
        stack<Node*>stk1,stk2;
        stk1.push(root);
        while(!stk1.empty()){
            root = stk1.top();
            stk1.pop();
            stk2.push(root);
            if(root->left != NULL) stk1.push(root->left);
            if(root->right != NULL) stk1.push(root->right);
        }
        while(!stk2.empty()){
            postorder.push_back(stk2.top()->data);
            stk2.pop();
        }
        return postorder;
    }
};


int main(){
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->left->right = new Node(7);
    root->right->left->right->right = new Node(8);

    Solution sol;
    vector<int>PostOrder = sol.PostOrderTraversal(root);

    cout << "Iterative Method PostOrder Traversal With 2 Stack of the Above Tree :- ";
    for(int val:PostOrder) cout << val << " ";
    cout << endl;

}
