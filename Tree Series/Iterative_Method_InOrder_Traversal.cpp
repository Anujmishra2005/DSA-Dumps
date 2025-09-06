
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
    vector<int>InOrderTraversal(Node* root){
        vector<int>inorder;
        Node* node = root;
        stack<Node*>st;
        while(true){
            if(node != NULL){
                st.push(node);
                node = node->left;
            }
            else{
                if(st.empty() == true) break;
                node = st.top();
                st.pop();
                inorder.push_back(node->data);
                node = node->right;
            }
        }
        return inorder;
    }
};


int main(){
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(6);
    root->left->right->right = new Node(7);

    Solution sol;
    vector<int>InOrder = sol.InOrderTraversal(root);

    cout << "Iterative Method InOrder Traversal of the Above Tree :- ";
    for(int val:InOrder) cout << val << " ";
    cout << endl;

}
