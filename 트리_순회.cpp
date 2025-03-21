#include<bits/stdc++.h>
using namespace std;

struct Node{
    char node;
    Node* left;
    Node* right;
    Node(char value) : node(value), left(nullptr), right(nullptr) {}
};

void preorder(Node* root){
    if(root == nullptr) return;
    printf("%c", root->node);
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root) {
    if(root == nullptr) return;
    inorder(root->left);
    printf("%c", root->node);
    inorder(root->right);
}

void postorder(Node* root) {
    if(root == nullptr) return;
    postorder(root->left);
    postorder(root->right);
    printf("%c", root->node);
}

Node* find_parent(Node* root, char t) {
    if(root == nullptr || root->node == t) return root;
    Node* node = find_parent(root->left, t);
    if(node != nullptr) return node;
    
    return find_parent(root->right, t);
}

int main() {
    int n; scanf("%d", &n);
    Node* root = new Node('A');

    while(n--){
        char parent, left_child, right_child;
        scanf(" %c %c %c", &parent, &left_child, &right_child);
        Node* p_node = find_parent(root, parent);
        if(left_child != '.') {
            p_node->left = new Node(left_child);
        }
        if(right_child != '.') {
            p_node->right = new Node(right_child);
        }
    }
    preorder(root);
    printf("\n");
    inorder(root);
    printf("\n");
    postorder(root);
}