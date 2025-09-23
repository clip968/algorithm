#include<bits/stdc++.h>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    Node(int val) : key(val), left(nullptr), right(nullptr) {}
};

Node* makeBST(vector<int>& v, int& idx, int minVal, int maxVal) {
    if(idx >= v.size() || v[idx] < minVal || v[idx] > maxVal) {
        return nullptr;
    }
    int val = v[idx];
    Node* root = new Node(v[idx++]);
    root->left = makeBST(v, idx, minVal, (long long) val - 1);
    root->right = makeBST(v, idx, (long long) val, maxVal);
    return root;
}

void postOrder(Node* root) {
    if(root == nullptr) return;
    postOrder(root->left);
    postOrder(root->right);
    printf("%d\n", root->key);
}

int main() {
    vector<int> v;
    int tmp;
    while(scanf("%d", &tmp) != EOF) {
        v.push_back(tmp);
    }

    int idx{};
    Node* root = makeBST(v, idx, INT_MIN, INT_MAX);
    postOrder(root);
    return 0;
}