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
    vector<int> PostOrderTraversal(Node* root){
        vector<int> postorder;
        if(root == NULL) return postorder;
        stack<Node*> st;
        Node* curr = root;

        while(curr != NULL || !st.empty()){
            if(curr != NULL){
                st.push(curr);
                curr = curr->left;
            } else {
                Node* temp = st.top()->right;
                if(temp == NULL){
                    temp = st.top();
                    st.pop();
                    postorder.push_back(temp->data);
                    while(!st.empty() && temp == st.top()->right){
                        temp = st.top();
                        st.pop();
                        postorder.push_back(temp->data);
                    }
                } else {
                    curr = temp;
                }
            }
        }

        return postorder;
    }
};

int main(){
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(7);
    root->left->left = new Node(3);
    root->left->left->right = new Node(4);
    root->left->left->right->right = new Node(5);
    root->left->left->right->right->right = new Node(6);
    root->right->left = new Node(8);
    root->right->left->right = new Node(9);
    root->right->left->right->right = new Node(10);

    Solution sol;
    vector<int> PostOrder = sol.PostOrderTraversal(root);

    cout << "Iterative Method PostOrder Traversal With 1 Stack of the Above Tree :- ";
    for(int val : PostOrder) cout << val << " ";
    cout << endl;

}

